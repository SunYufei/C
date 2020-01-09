#include<stdio.h>
#include"linklist.h"
#define N 5

int main()
{
	linklist l;
	nodeitem na[N],i;
	init_list(&l);
	input_data(na,N);
	for(i=0;i<N;i++)
		insert_list_tail(&l,&na[i]);
	
	display_list(&l);
	destory_list(&l);
	return 0;
}