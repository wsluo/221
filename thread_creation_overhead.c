#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void* mythread(void *arg){
}

int main(){
pthread_t tid;
uint32_t t0 = 0;
uint32_t t1 = 0;
 //reset and clear overflows
__asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007)); 
__asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
int r = pthread_create(&tid,NULL,mythread,NULL);

__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
 
pthread_join(tid,NULL);
return 0;
}
