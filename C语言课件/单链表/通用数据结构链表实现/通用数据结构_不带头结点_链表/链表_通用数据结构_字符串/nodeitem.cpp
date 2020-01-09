#include"nodeitem.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
Bool is_equal(nodeitem *p1, nodeitem *p2)
{
	return !strcmp(*p1,*p2);
}
void display_nodeitem(nodeitem *pn)
{
	printf("%s\t",*pn);
}
void input_data(nodeitem na[],int n)
{
	int i;
	printf("\nplease input the string!\n");
	for(i=0;i<n;i++)
	{
		na[i]=(char*)malloc(MAX_LEN*sizeof(char));
		gets(na[i]);
	}
}

void copy_nodeitem(nodeitem *pn1,nodeitem *pn2)
{
	*pn1=(nodeitem)malloc(strlen(*pn2)+1);
	if(*pn1==NULL){
		printf("cannot allocate such memeory!");
		exit(EXIT_FAILURE);
	}
    strcpy(*pn1,*pn2);
}

void destroy_nodeitem(nodeitem *pn)
{
	free(*pn);
}