#include <stdio.h>
#include <stdint.h>

#define num_of_loops 1000000

int main(){
  uint32_t t0 = 0;
  uint32_t t1 = 0;
  //reset and clear overflows
  __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007)); 
  __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
  __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

  for (int  i=0; i<num_of_loops; i++){


  }


  __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
  double m= (t1-t0-9)/(double)(num_of_loops);
  printf("%f\n", m);
}


