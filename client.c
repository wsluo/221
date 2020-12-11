#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <math.h>

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

 
int main()
{
    int socketDesc = 0,n = 0;
    char buff[1024*1024];
	char ping_buff[64];
	double ping_results[100];
    struct sockaddr_in ipOfServer;
	
	int rflag, sflag=0;
	

    uint32_t t0 = 0;
    uint32_t t1 = 0;
 
    memset(buff, '0' ,sizeof(buff));

 
    if((socketDesc = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("Socket not created \n");
        return 1;
    }
	

 
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(2017);
    //ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	ipOfServer.sin_addr.s_addr = inet_addr("192.168.0.181");
	
	
    __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
 
	//connect to the server
    if(connect(socketDesc, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer))<0)
    {
        printf("Connection failed \n");
        return 1;
    }
	
	__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
	
	printf("connection time: %f \n",(double)(t1-t0)/750000000);
	
	
	//ping test: RTT
	int t = 1;
	for (int i=0;i<100;i++){
		
        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
        __asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));

        __asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
		
		sflag=send(socketDesc, &ping_buff, sizeof(ping_buff), 0);
		//printf("send %d %d\n",i,sflag);
		
		rflag=recv(socketDesc, &ping_buff, sizeof(ping_buff), 0);
		//printf("receiv %d %d\n",i,rflag);
		
		__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
		
		ping_results[i]=(double)(t1-t0);
	}
	
	printf("ping mean %f, ping std %f \n",mean(ping_results,100)/750000000,std(ping_results,100)/750000000);
	
	
	for (int i=0; i<10; i++){
		printf("%d \n",i);
		
		sflag=send(socketDesc, &buff, sizeof(buff), 0);
		//printf("send %d \n",sflag);
		
		int acc=0;
		while(1){
			rflag=recv(socketDesc, &buff, sizeof(buff), 0);
			acc+=rflag;
			
			if (rflag <=0 | acc == sizeof(buff)){
				printf("receiv %d %d\n",rflag,acc);
				break;}
		}
		
	}
	
    return 0;
}
