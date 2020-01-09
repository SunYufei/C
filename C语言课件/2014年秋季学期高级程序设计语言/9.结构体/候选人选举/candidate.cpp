#include"candidate.h"
#include<stdio.h>
#include<string.h>
void init_can(Can c[],int n)
{
	int i;
	for(i=0;i<n;i++){
	printf("please input the name of candidate!");
	gets(c[i].name);
	c[i].count=0;
	}
}
void elect_can(Can c[],int m,int n)
{
	int i,j;
	char name[100];
	for(i=0;i<n;i++){
 		printf("please input the name of your choice!");
 		gets(name);
		for(j=0;j<m;j++){
			if(strcmp(name,c[j].name)==0)
				c[j].count++;
		}
	}
}
void display_winner(Can c[],int n)
{
	int equal_num=0;
	int i,max=c[0].count,j=0;
	for(i=1;i<n;i++){
	   if(c[i].count>max)
		   max=c[i].count;
	}
	for(i=0;i<n;i++){
	    if(c[i].count==max)
		{
			equal_num++;
			j=i;
		}
	}
	if(equal_num>=2){
		printf("there are over two candidates who get the same number of tickets and you must think reelection!\n");
		return ;
	}
	else
		printf("the candiate %s wins in this election\n",c[j].name);
}
void display_result(Can c[],int n)
{
	printf("\n the election results are as follow!\n");
	int i;
	for(i=0;i<n;i++){
	   printf("candidate %s gets %d tickets!\n",c[i].name,c[i].count);
	}
}
