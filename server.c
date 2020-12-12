#include <stdio.h> // standard input and output library
#include <stdlib.h> // this includes functions regarding memory allocation
#include <string.h> // contains string functions
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <time.h> //contains various functions for manipulating date and time
#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
 
int main()
{
    time_t clock;
	char buff[1024*1024]; // Actually this is called packet in Network Communication, which contain data and send through.
	char ping_buff[64];
	
	int clintListn = 0, clientSock = 0;
	struct sockaddr_in ipOfServer;
	clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
	memset(&ipOfServer, '0', sizeof(ipOfServer));
	memset(buff, '0', sizeof(buff));
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
	ipOfServer.sin_port = htons(2017); 		// this is the port number of running server
	bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
	listen(clintListn , 20);
	
	int rflag, sflag=0;
	

    uint32_t t0 = 0;
    uint32_t t1 = 0;
 
	while(1)
	{
		printf("\n\nHi,Iam running server.Some Client hit me\n"); // whenever a request from client came. It will be processed here.
		clientSock = accept(clintListn, (struct sockaddr*)NULL, NULL);
		
		printf("client sock: %d\n",clientSock);
 
		clock = time(NULL);
		//snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); // Printing successful message
		
		//ping test
		for (int i=0;i<100;i++){
			rflag=recv(clientSock, &ping_buff, sizeof(ping_buff), 0);
			
			printf("receiv %d %d\n",i,rflag);
			
			sflag=send(clientSock, &ping_buff, sizeof(ping_buff), 0);
			printf("send %d %d\n",i,sflag);
		}
		

		for (int i=0; i<10; i++){
			printf("%d \n",i);
			
			//rflag=recv(clientSock, &buff, sizeof(buff), 0);
			//printf("receiv %d \n",rflag);
			int acc=0;
			while(1){
				rflag=recv(clientSock, &buff, sizeof(buff), 0);
				acc+=rflag;
				printf("receiv %d %d\n",rflag,acc);
				if (rflag <=0 | acc == sizeof(buff)){break;}
			}
			
			sflag=send(clientSock, &buff, sizeof(buff), 0);
			printf("send %d \n",sflag);
			}
			
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
	        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));

	        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
		//write(clintConnt, dataSending, strlen(dataSending));
		close(clientSock);
		
		__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
		
		printf("%f tear down time:", (double)(t1-t0)/750000000);
		
		
        sleep(1);
     }
 
     return 0;
}
