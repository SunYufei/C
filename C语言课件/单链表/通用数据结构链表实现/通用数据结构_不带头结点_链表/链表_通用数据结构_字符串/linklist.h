#ifndef linklist_h
#define linklist_h
#include"node.h"

typedef struct{
	node* head;//or pnode head;
}linklist,*plinklist;
typedef int Bool;

void init_list(plinklist pl);
void insert_list(plinklist pl,nodeitem *pn);
void display_list(plinklist pl);
void delete_list(plinklist pl,nodeitem *pn);
void destory_list(plinklist pl);
Bool is_inlist(plinklist pl,nodeitem *pn);

#endif
