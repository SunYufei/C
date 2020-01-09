#include<stdio.h>
#include"linklist.h"
#define N 2

int main()
{
	linklist l;
	int i;
	nodeitem n[N];
	init_list(&l);
	input_data(n,N);
	for(i=0;i<N;i++)
		insert_list(&l,&n[i]);
	//delete_list(&l,&i);
	display_list(&l);
	destory_list(&l);
	return 0;
}