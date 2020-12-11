#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
  pid_t process_id;

  uint32_t t0 = 0;
  uint32_t t1 = 0;
  //reset and clear overflows
  __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007)); 
  __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
  __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));

  process_id = getpid();   


  __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
  printf("%u\n", t1-t0);


}
