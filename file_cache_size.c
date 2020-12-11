#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close

#define repeats 1
#define CYCLE_TIME (double)1/(double)750000000
#define MEMCMP_OVERHEAD 0

void block_time(int size);

//size in MB
void block_time(int size){

    uint32_t t0 = 0;
    uint32_t t1 = 0;
	
	
	time_t start, end;
	double dif;
	
    FILE *infile;
	int buffer_size = 4096;
	char * buffer = malloc(buffer_size); //4kb
	
	int max_block = size * 1024 /4;
	
	//double results[repeats];
	
	double * results = malloc( max_block * sizeof(double));
	
	
	//while (fread(buffer,1,buffer_size,infile)==buffer_size) {;} //load everything
	
    for (int r=0; r<repeats; r++){	
		
		int loaded = 0;
		
		int current_position = 0;
		
		int f = open("test.dat",O_RDONLY|O_SYNC);
		
		while (read(f,buffer,buffer_size)==buffer_size){
			;
		}
			
/*	
		for (int j=0;j<max_block;j++){
		
			pread(f,buffer,buffer_size,j*buffer_size);
		}
		*/
		
		close(f);
		
	    //read the file for the second time
        f = open("test.dat",O_RDONLY|O_SYNC);
		
		loaded = 0;

		time(&start);
		
		
		for (int j=0;j<max_block;j++){
			
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
	        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
			//pread(f,buffer,buffer_size,j*buffer_size);
			read(f,buffer,buffer_size);
					
			__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
			
			results[j] = (double)(t1 - t0);
			
		}
		
		
		time(&end);
		dif = difftime (end,start);
		
        close(f);
        //results[i]=t1-t0;
		//results[i]=dif;

    }
	
    double sum=0;
    int arrayLen=max_block;
    for (int i=0;i<arrayLen;i++){
            sum+=results[i];
    }
    double avg = sum/(double)arrayLen;
	
    sum=0;
    for(int i=0;i<arrayLen;i++){
            sum+=(results[i]-avg)*(results[i]-avg);
    }

    double s = sqrt(sum/(double)arrayLen);


    printf("%d MB: %f  %f\n",size, avg, s);

}



int main(){
	block_time(256);
	block_time(512);
	block_time(1024);
	block_time(2048);
	block_time(3072);
	block_time(4096);
	block_time(8192);	
}
