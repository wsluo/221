#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <sys/mman.h>

int main(){
	
    uint32_t t0 = 0;
    uint32_t t1 = 0;
	
	for (int i=0;i<100;i++){
		
		int f = open("test.dat",O_RDWR|O_DIRECT);
		
		char* map = (char *) mmap(0,1073741824,PROT_WRITE, MAP_SHARED, f, 0);
		
		char c;
		
		
        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));

        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
		
		strcpy(map,"a!");
		
		__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
		
		printf("%f \n",(double)(t1-t0));
		
		
		munmap( map, 1073741824);
		
		
	}
	
	return 0;
}
