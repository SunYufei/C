#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu{
	int age;
	char name[100];
};
int main()
{
	struct Stu zs,ls;
	zs.age=19;	
	strcpy(zs.name,"zhangsan");
	ls=zs;
	ls.age=18;strcpy(ls.name,"liliu");
	printf("%s,%d\n",zs.name,zs.age);
	printf("%s,%d\n",ls.name,ls.age);
	return 0;
}