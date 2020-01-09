#include<stdio.h>
#include"linklist.h"
#define N 5

int main()
{
	linklist l,*pl;
	nodeitem na[N],nb[N],i;
	init_list(&l);
	input_data(na,N);
	input_data(nb,N);
	for(i=0;i<N;i++)
		insert_list_tail(&l,&na[i]);
	display_list(&l);
    pl=create_list_in_head(nb,N);
	display_list(pl);
	destory_list(&l);
	destory_list(pl);
	free(pl);
	return 0;
}