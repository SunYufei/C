#include<stdio.h>
#include"linklist.h"
#include"nodeitem.h"
#define N 3

int main()
{
	linklist l;
	nodeitem ns[N];

	int i;
	init_list(&l);
	input_data(ns,N);
	for(i=0;i<N;i++)
		insert_list(&l,&ns[i]);
	display_list(&l);
	destory_list(&l);
	return 0;
}