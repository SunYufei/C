#include"nodeitem.h"
#include<stdio.h>
Bool is_equal(nodeitem *p1, nodeitem *p2)
{
	return *p1==*p2;
}
void display_nodeitem(nodeitem *pn)
{
	printf("%d\t",*pn);
}
void input_data(nodeitem na[],int n)
{
	printf("please input the data\n");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&na[i]);
}
void copy_nodeitem(nodeitem *pn1,nodeitem *pn2)
{
	*pn1=*pn2;
}
void destroy_nodeitem(nodeitem *pn)
{
}