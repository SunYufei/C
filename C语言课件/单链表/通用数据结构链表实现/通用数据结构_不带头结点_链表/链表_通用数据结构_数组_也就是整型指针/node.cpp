#include<stdio.h>
#include<stdlib.h>
#include"node.h"

pnode create_node(nodeitem *pn)
{
	pnode p=(pnode)malloc(sizeof(node));
	if(p==NULL){
		printf("cannot allocate such memeory!");
		exit(EXIT_FAILURE);
	}
	copy_nodeitem(&(p->elem),pn);
	p->next=NULL;
	return p;
}
