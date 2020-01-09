#include<stdio.h>
#include"linklist.h"
#define N 5
int main()
{
	linklist l;
	nodeitem na[N],i,delete_item;
	init_list(&l);
	input_data(na,N);
	for(i=0;i<N;i++)
		insert_list_head(&l,&na[i]);
	printf("\nplease input the item you want to delete!\n");
	scanf("%d",&delete_item);
	delete_list(&l,&delete_item);
	display_list(&l);
	destory_list(&l);
	return 0;
}