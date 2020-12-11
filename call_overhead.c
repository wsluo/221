#include <stdio.h>
#include <stdint.h>

void call0();
void call1(int a1);
void call2(int a1,int a2);
void call3(int a1,int a2,int a3);
void call4(int a1,int a2,int a3,int a4);
void call5(int a1,int a2,int a3,int a4,int a5);
void call6(int a1,int a2,int a3,int a4,int a5,int a6);
void call7(int a1,int a2,int a3,int a4,int a5,int a6,int a7);

void call0(){
}
void call1(int a1){
}
void call2(int a1,int a2){
}
void call3(int a1,int a2, int a3){
}
void call4(int a1,int a2, int a3, int a4){
}
void call5(int a1,int a2, int a3, int a4, int a5){
}
void call6(int a1,int a2, int a3, int a4, int a5, int a6){
}
void call7(int a1,int a2, int a3, int a4, int a5, int a6, int a7){
}

int main(int argc, char* argv[]){

long N = strtol(argv[1], NULL, 10);

uint32_t t0 = 0;
uint32_t t1 = 0;

int repeat = 1000;




// clear overflows:
__asm__ volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(0x80000007));
__asm__ volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));

if  (N==0){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call0();
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

// clear overflows:
if (N==1){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call1(0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

// clear overflows:
if (N==2){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call2(0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

// clear overflows 3:
if (N==3){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call3(0,0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

// clear overflows 4
if (N==4){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call4(0,0,0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

// clear overflows 5
if (N==5){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call5(0,0,0,0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

//clear overflows 6
if (N==6){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call6(0,0,0,0,0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

//clear overflows 7
if (N==7){
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t0));
for (int i=0;i<repeat;i++){
call7(0,0,0,0,0,0,0);
}
__asm__ volatile ("mrc p15, 0, %0, c9, c13, 0":"=r" (t1));
printf("%u\n", t1-t0);
}

return 0;
}


