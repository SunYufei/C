#include"nodeitem.h"
#include<stdio.h>
#include<stdlib.h>

void display_nodeitem(nodeitem *pn)
{
	int i;
	printf("\nthe elements in this array is as follows!\n");
    for(i=0;i<pn->length;i++)
	{
	 printf("%d\t",(pn->table)[i]);
	}
}

Bool is_equal(nodeitem *p1, nodeitem *p2)
{
	int i;
	if(p1->length!=p2->length)
		return 0;
	for(i=0;i<p1->length;i++)
	{
		if( (p1->table)[i]==(p2->table)[i])
			;
		else
			return 0;
	}
		return 1;
}

void input_data(nodeitem na[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		
		
		printf("\nplease input the %d nodeitem\n",i+1);
		printf("\nplease input the length of this nodeitem!\n");
		scanf("%d",&(na[i].length));
        na[i].table=(int*)malloc(na[i].length*sizeof(int));
		printf("\nplease input the value of the elements in this array!\n");
		for(j=0;j<na[i].length;j++)
			scanf("%d",&((na[i].table)[j]));

	}
}

void copy_nodeitem(nodeitem *pn1,nodeitem *pn2)
{
	int i;
    pn1->table=(int*)malloc(pn2->length*sizeof(int));
	pn1->length=pn2->length;
	for(i=0;i<pn2->length;i++)
		(pn1->table)[i]=(pn2->table)[i];
}

void destroy_nodeitem(nodeitem *pn)
{
	free(pn->table);
}
