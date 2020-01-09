#include<stdio.h>
typedef int A[10];
typedef A B[3];
int main()
{
	printf("%d,%d\n",sizeof(A),sizeof(B));
	return 0;
}