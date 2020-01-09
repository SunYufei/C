#include<stdio.h>
struct student
{
	int  num;
	char name[20];
	char sex;
	int age;
};
int main()
{
	printf("%d",sizeof(struct student));
	return 0;
}
