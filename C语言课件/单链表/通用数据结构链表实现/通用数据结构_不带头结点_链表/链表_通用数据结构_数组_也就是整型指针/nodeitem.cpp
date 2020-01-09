#include"nodeitem.h"
#include<stdio.h>
#include<stdlib.h>

void display_nodeitem(nodeitem *pn)
{
	int i;
	printf("\nthe elements in this array is as follows!\n");
    for(i=0;i<ARR_LEN;i++)
	{
	 printf("%d\t",(*pn)[i]);
	}
}

Bool is_equal(nodeitem *p1, nodeitem *p2)
{
	int i;
	for(i=0;i<ARR_LEN;i++)
	{
		if((*p1)[i]==(*p2)[i])
			;
		else
			return 0;
	}
	if(i==ARR_LEN)
		return 1;
}

void input_data(nodeitem na[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		
		na[i]=(int*)malloc(ARR_LEN*sizeof(int));
		printf("\nplease input the %d nodeitem\n",i+1);
		for(j=0;j<ARR_LEN;j++)
			scanf("%d",&(na[i][j]));
	}
}

void copy_nodeitem(nodeitem *pn1,nodeitem *pn2)
{
	int i;
	*pn1=(int*)malloc(ARR_LEN*sizeof(int));
	for(i=0;i<ARR_LEN;i++)
		(*pn1)[i]=(*pn2)[i];
}

void destroy_nodeitem(nodeitem *pn)
{
	free(*pn);
}