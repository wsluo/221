#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <sys/wait.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close


int main(){
	
    uint32_t t0 = 0;
    uint32_t t1 = 0;
	
	int fd[2];
	pipe(fd);
	
	pid_t pid;
	
	for (int i=0; i<10;i++){
		t0 = 0;
		t1 = 0;
		
		pid = fork();
		//parent
		if ( pid != 0){
					
			printf("I am parent\n");
			
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
	        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
			
			wait(NULL);
			read(fd[0],(void*)&t1,sizeof(uint32_t));	
		
			
		}//child
		else{
			
			printf("I am child\n");
			
			__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
				
			write(fd[1],(void*)t1,sizeof(uint32_t));
					
		}
		
		if (t1>t0) printf("%f \n",(double)(t1-t0));
		
		
			
	}
	
	return 0;
	
}
