#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define iters 100000
#define repeats 1000

  double mean(double* arr);
  double std(double* arr);

  double testaccess(int size, int stride);

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

  //size: kB, stride: bytes
  double testAccess(int size, int stride)
  {
     double results[repeats];

     for (int i=0;i<repeats;i++){
        results[i]=0;
     }
     uint32_t t0 = 0;
     uint32_t t1 = 0;
     int arraySize = size * 1024/4;
     int stepInt   = stride/4;

     int * array;
     array = (int *) calloc (arraySize,sizeof(int));
     //    memset(array,0,arraySize * sizeof(int));
     //     printf("allocated!\n");
     for(int run=0;run<repeats;run++){

     int next = 0;
     int current = 0;
     for (int i=0;i<iters; i++){
        next = current + stepInt;
        if (next>=arraySize){
        next = next%arraySize+1;
        }
       // array[current] = next; //(int)(array+next);
        array[current]=&array[next];
        current=next;
     }
//     printf("stepped!\n");
     __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
     __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
     __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

     int* p=array;//int p=0;
     for (int i=0; i<iters; i++){
         p = *p;// array[p];
          }

      __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
     // printf("outout!\n");
      double diff =(double)(t1-t0)/iters;
      results[run]=diff;
//      printf("%d\n",run);
    }
   double avg=mean(results);
   double s =std(results);
  // printf("at leat\n");
   printf("%f %f %d %d\n",avg,s,stride,size);
   free(array);
   return (double)(t1-t0);
  }


int main(){

int  sizes[]={4,8,16,32,48,64,128,192,256,512,768,1024,2048,4096};//,8192,16384};//,131072,262144,524288,1048576,2097152,4194304,8388608};
int  strides[]={4,8,16,32,64,128,256,512,1024};

//printf("%d",strides);

for(int i=0;i<9;i++){
//printf("stride %d\n",strides[i]);
for (int j=0;j<sizeof(sizes)/sizeof(sizes[0]);j++){
int stride = strides[i];
int size  =  sizes[j];
testAccess(size,stride);
}
}

//testAccess(128,128);
printf("%d\n",sizeof(int*));

}

