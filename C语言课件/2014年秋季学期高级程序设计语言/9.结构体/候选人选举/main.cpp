#include<stdio.h>
#include"candidate.h"
int main()
{
	Can c[CAN_NUM];
	init_can(c,CAN_NUM);
	elect_can(c,CAN_NUM,ELECTOR_NUM);
	display_result(c,CAN_NUM);
	display_winner(c,CAN_NUM);
	return 0;
}