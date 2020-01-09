#include"nodeitem.h"
#include<stdio.h>
#include<string.h>

void input_data(nodeitem s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("please input the information of student %d\n",i+1);
		printf("please input the number!");
		scanf("%d",&(s[i].num));
		getchar();
		printf("please input the sex!");
		scanf("%c",&(s[i].sex));//why can not use getchar(s[i].sex)
		getchar();
		printf("please input the name!");
		gets(s[i].name);
	}
}

Bool is_equal(nodeitem *p1, nodeitem *p2)
{
	return (p1->num==p2->num)&&(p1->sex==p2->sex)&&(!strcmp(p1->name,p2->name));
}

void input_single_stu(stu *ps)
{
    printf("please input the number!");
	scanf("%d",&(ps->num));
	getchar();
	printf("please input the sex!");
	scanf("%c",&(ps->sex));
	getchar();
	printf("please input the name!");
	gets(ps->name);
}

void display_nodeitem(nodeitem *pn)
{
	static int i=1;
	printf("\nthe %d student information is as follows!\n",i);
	printf("num=%d,sex=%c and name=%s\n",pn->num,pn->sex,pn->name);
	i++;
}

void copy_nodeitem(nodeitem *pn1,nodeitem *pn2)
{
	pn1->num=pn2->num;
	pn1->sex=pn2->sex;
	strcpy(pn1->name,pn2->name);
}

void destroy_nodeitem(nodeitem *pn)
{

}

