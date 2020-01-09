#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void init_list(plinklist pl)
{
	pl->head=NULL;
}
plinklist create_list_in_head(nodeitem ni[],int n)
{
	int i;
	plinklist pl=(linklist*)malloc(sizeof(linklist));
	init_list(pl);
	for(i=0;i<n;i++)
		insert_list_head(pl,&ni[i]);
	return pl;

}
plinklist create_list_in_tail(nodeitem ni[],int n)
{
    int i;
	plinklist pl=(linklist*)malloc(sizeof(linklist));
	init_list(pl);
	for(i=0;i<n;i++)
		insert_list_tail(pl,&ni[i]);
	return pl;

}
void insert_list_head(plinklist pl,nodeitem *pn)//这实质上是头插入法
{
	pnode p=create_node(pn);
	p->next=pl->head;
	pl->head=p;
}

void insert_list_tail(plinklist pl,nodeitem *pn)
{
	pnode temp=pl->head;
	pnode p=create_node(pn);
	if(pl->head==NULL)
		pl->head=p;
	else{
	while(temp->next)
		temp=temp->next;
	temp->next=p;
	}
}

Bool is_inlist(plinklist pl,nodeitem *pn)
{
	pnode p=pl->head;
	while(p)
	{
     if(is_equal(&(p->elem),pn))
		 return 1;
	 p=p->next;
	}
	return 0;
}

void delete_list(plinklist pl,nodeitem* pn)
{
	pnode curr,prev;
	if(is_inlist(pl,pn)){
    
	for(curr=pl->head,prev=NULL;curr!=NULL&& !is_equal(&(curr->elem),pn);prev=curr,curr=curr->next)
		;
	if(prev==NULL)//delete the first node
		pl->head=curr->next;
	else
	
        prev->next=curr->next;
	destroy_nodeitem(&(curr->elem));
    free(curr);
	}
	else{
		printf("this item is not in the list!");
		return ;
	}
}

void display_list(plinklist pl)
{
	pnode p=pl->head;
	while(p)
	{
		display_nodeitem(&p->elem);
		p=p->next;
	}
	printf("\n");
}

void destory_list(plinklist pl)
{
  pnode p=pl->head;
  while(p)
  {
	  destroy_nodeitem(&(p->elem));
	  pnode temp=p;
	  p=p->next;
	  free(temp);
  }
}