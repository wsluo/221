#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


#include <fcntl.h> // for open
#include <unistd.h> // for close

#define repeats 10
#define CYCLE_TIME (double)1/(double)750000000
#define MEMCMP_OVERHEAD 0

 double mean(double *arr,int arrayLen);
 double std(double *arr, int arrayLen);

 double mean(double *arr, int arrayLen){
	 double sum=0;

	 for (int i=0;i<arrayLen;i++){
	 sum+=arr[i];
	 }
	 return sum/(double)arrayLen;
 }


 double std(double *arr, int arrayLen){
	 double sum=0;
	 double m = mean(arr, arrayLen);

	 for(int i=0;i<arrayLen;i++){
		 sum+=(arr[i]-m)*(arr[i]-m);
	 }
	 
	 return sqrt(sum/(double)arrayLen);
}



void file_read_time_seq(int size);

void file_read_time_random(int size);

//size in MB
void file_read_time_seq(int size){

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    time_t start, end;
    double dif;
	
	double repeated_measures[repeats];
	
	for (int r=0; r<repeats; r++){
	
	    int f = open("test.dat",O_DIRECT);

		int buffer_size = 4096;
		char * buffer = malloc(buffer_size); //4kb	

		int max_block = size * 1024 /4;


		double * results = malloc( max_block * sizeof(double));

		int current_position = 0;


		for (int i=0;i<max_block;i++){
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
	        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
			pread(f,buffer,buffer_size,i*buffer_size);
		
			__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
		
			results[i] = (double)(t1 - t0);
		
		}

		close(f);
	
		repeated_measures[r] = mean(results,max_block);
		
	}
	
	printf("%d %f %f\n",size, mean(repeated_measures,repeats),std(repeated_measures,repeats));

}



void file_read_time_random(int size){

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    time_t start, end;
    double dif;
	
	double repeated_measures[repeats];
	
	for (int r=0; r<repeats; r++){
	
	    int f = open("test.dat",O_DIRECT);

		int buffer_size = 4096;
		char * buffer = malloc(buffer_size); //4kb	

		int max_block = size * 1024 /4;

		double * results = malloc( max_block * sizeof(double));
		
		int * positions = malloc( max_block * sizeof(int));
		
		for (int i=0; i<max_block;i++){
			positions[i] = rand() % (max_block-1);
		}


		for (int i=0;i<max_block;i++){
			
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
	        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
			pread(f,buffer,buffer_size,positions[i]*buffer_size);
		
			__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
		
			results[i] = (double)(t1 - t0);
		}

		close(f);
	
		repeated_measures[r] = mean(results,max_block);
		
	}
	
	printf("%dMB %f %f %d \n",size, mean(repeated_measures,repeats),std(repeated_measures,repeats),getpid());

}


int main(int argc, char *argv[] ){
	
	//int sizes[] = {2,4,16,128,256};
	
	int child;
	
	if (sscanf (argv[1], "%i", &child) != 1) {
	    fprintf(stderr, "error - not an integer");
	}

	pid_t pids[child ];
	int i;
	int n = child ;

	/* Start children. */
	for (i = 0; i < n; ++i) {
	  if ((pids[i] = fork()) < 0) {
	    abort();
	  } else if (pids[i] == 0) {
	    file_read_time_random(128);
	    exit(0);
	  }
	}
	
	/* Wait for children to exit. */
	int status;
	pid_t pid;
	while (n > 0) {
	  pid = wait(&status);
	  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
	  --n;  
	}
	


}
