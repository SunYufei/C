#include<stdio.h>
extern int a;
extern void inc();
int main()
{
	inc();
	printf("a=%d",a);
	return 0;
}