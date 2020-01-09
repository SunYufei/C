#include<stdio.h>
int main()
{
	union  int_char
	{ 
		int i;
		char ch[4];
	}x;
	x.i=24897;
	printf("%c\n",0);
	printf("i=%o\n",x.i);
	printf("ch0=%o,ch1=%o,ch2=%o,ch3=%o\n ch0=%c,ch1=%c,ch2=%c,ch3=%c\n", x.ch[0],x.ch[1],x.ch[2],x.ch[3],x.ch[0],x.ch[1],x.ch[2],x.ch[3]);
	return 0;
}
