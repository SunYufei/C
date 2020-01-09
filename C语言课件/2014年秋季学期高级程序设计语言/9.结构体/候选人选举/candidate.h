#ifndef candidate_h
#define candidate_h
#define CAN_NUM 3
#define ELECTOR_NUM 10
typedef struct candidate{
	char name[100];
	int count;
}Can,*pcan;

void init_can(Can c[],int n);//or you can write void init_can(pcan c,int n)
void elect_can(Can c[],int m,int n);//m represents the number of candidates and n represents the number of electors
void display_winner(Can c[],int n);
void display_result(Can c[],int n);
#endif