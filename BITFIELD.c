#include<stdio.h>

struct bits{
unsigned int a7:1;
unsigned int a6:1;
unsigned int a5:1;
unsigned int a4:1;
unsigned int a3:1;
unsigned int a2:1;
unsigned int a1:1;
unsigned int a0:1;
};
struct hexa{
unsigned int h1:4;
unsigned int h0:4;
};
union u{
char ch ;
struct bits b;
struct hexa h;
}u1;
int main(){
int i=15;
u1.ch=5;
printf("%d %d %d %d %d %d %d %d",u1.b.a0,u1.b.a1,u1.b.a2,u1.b.a3,u1.b.a4,u1.b.a5,u1.b.a6,u1.b.a7);
u1.b.a6=1;
u1.b.a7=0;
printf("\n%c",u1.ch);
printf("\n %x %x ",u1.h.h0,u1.h.h1);
printf("\n DEC=%d",i);
printf("\n HEXA=%X",i);
printf("\nOCTAL=%o",i);
return 0;
}
