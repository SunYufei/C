#ifndef node_h
#define node_h
#include"nodeitem.h"
typedef struct node{
	nodeitem elem;
	struct node* next;
}node,*pnode;
pnode create_node(nodeitem *pn);
#endif