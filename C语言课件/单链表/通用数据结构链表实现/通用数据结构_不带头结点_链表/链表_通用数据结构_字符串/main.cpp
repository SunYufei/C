#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#define N 5

int main()
{
	linklist l;
	nodeitem temp;
	int i;
	nodeitem na[N];
	init_list(&l);
	input_data(na,N);
	for(i=0;i<N;i++)
		insert_list(&l,&na[i]);
	display_list(&l);
	printf("\nprintf input the string you want to delete!\n");
	temp=(char*)malloc(MAX_LEN*sizeof(char));
	gets(temp);
	delete_list(&l,&temp);
	display_list(&l);
	destory_list(&l);
	return 0;
}