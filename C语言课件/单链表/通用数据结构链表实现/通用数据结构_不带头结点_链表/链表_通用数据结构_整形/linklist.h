#ifndef linklist_h
#define linklist_h
#include"node.h"

typedef struct{
	node* head;//or pnode head;
}linklist,*plinklist;

typedef int Bool;
void init_list(plinklist pl);
plinklist create_list_in_head(nodeitem ni[],int n);//Í·²å
plinklist_create_list_in_tail(nodeitem ni[],int n);//Î²²å
void insert_list_head(plinklist pl,nodeitem *pn);
void display_list(plinklist pl);
void delete_list(plinklist pl,nodeitem *pn);
Bool is_inlist(plinklist pl,nodeitem *pn);
void insert_list_tail(plinklist pl,nodeitem *pn);
void destory_list(plinklist pl);

#endif
