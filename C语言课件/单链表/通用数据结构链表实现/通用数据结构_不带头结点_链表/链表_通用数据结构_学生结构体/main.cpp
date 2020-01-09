#include<stdio.h>
#include"linklist.h"
#include"nodeitem.h"
#define N 3

int main()
{
	linklist l;
	stu s[N];
	stu temp;
	int i;
	init_list(&l);
	input_data(s,N);
	for(i=0;i<N;i++)
		insert_list(&l,&s[i]);
	display_list(&l);
	printf("\n please input the information of student you want to delete!\n");
	input_single_stu(&temp);
	delete_list(&l,&temp);
	display_list(&l);
	destory_list(&l);
	return 0;
}