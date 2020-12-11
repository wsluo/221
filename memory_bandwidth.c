#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define repeats 1000
#define CYCLE_TIME (double)1/(double)750000000
#define MEMCMP_OVERHEAD 0

double mean(double* arr);
double std(double* arr);

void read_bandwidth(int size);
void write_bandwidth(int size);
void copy_bandwidth(int size);

double mean(double *arr){
	double sum=0;
	int arrayLen=repeats;
	for (int i=0;i<arrayLen;i++){
		sum+=arr[i];
	}
	return sum/(double)arrayLen;
}

double std(double *arr){
	double sum=0;
	double  m = mean(arr);
	int arrayLen=repeats;
	for(int i=0;i<arrayLen;i++){
		sum=(arr[i]-m)*(arr[i]-m);
	}

	return sqrt(sum/(double)arrayLen);
}

//size in MB
void read_bandwidth(int size){

    double results[repeats];

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    int arraySize = size * 1024 * 1024/4;

    int * arrayA;
    arrayA = (int *) calloc (arraySize,sizeof(int));

    int * arrayB;
    arrayB = (int *) calloc (arraySize,sizeof(int));

	for (int i=0; i<repeats; i++){
//            int * arrayA;
//            int * arrayB;
//            arrayA = (int *) calloc (arraySize,sizeof(int));
//            arrayB = (int *) calloc (arraySize,sizeof(int));

	    __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	    __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
	    __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

	    int c = memcmp(arrayA, arrayB, size*1024*1024);

            __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));

	    results[i]=t1-t0;
//            free(arrayA);
//            free(arrayB);
	}

    double avg=mean(results);
    double s =std(results);

    double bandwidth = (double)size / (CYCLE_TIME * avg);
    printf("%f MB/s read bandwidth with %d MB\n",bandwidth,size);

}



//size in MB
void write_bandwidth(int size){

    double results[repeats];

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    int arraySize = size * 1024 * 1024/4;

    int * arrayA;
    arrayA = (int *) calloc (arraySize,sizeof(int));

        for (int i=0; i<repeats; i++){

            __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
            __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
            __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

            memset(arrayA, 1,size*1024*1024);

            __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));

            results[i]=t1-t0;

        }

    double avg=mean(results);
    double s =std(results);

    double bandwidth = (double)size / (CYCLE_TIME * avg);
    printf("%f MB/s write bandwidth with %d MB\n",bandwidth,size);


}


//size in MB
void copy_bandwidth(int size){

    double results[repeats];

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    int arraySize = size * 1024 * 1024/4;

    int * arrayA;
    arrayA = (int *) calloc (arraySize,sizeof(int));
    int * arrayB;
    arrayB = (int *) calloc (arraySize,sizeof(int));
        for (int i=0; i<repeats; i++){

            __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
            __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
            __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

            memcpy(arrayA, arrayB, size*1024*1024);

            __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));

            results[i]=t1-t0;

        }

    double avg=mean(results);
    double s =std(results);

    double bandwidth = (double)size*2 / (CYCLE_TIME * avg);
    printf("%f MB/s copy bandwidth with %d MB\n",bandwidth,size);


}


int main(){

	read_bandwidth(16);
        write_bandwidth(16);
        copy_bandwidth(16);

}
