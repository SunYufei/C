#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
void init_list(plinklist pl)
{
	pl->head=(pnode)malloc(sizeof(node));//����ط��в��
	if(!pl->head){
	printf("cannot allocate such memory!");
	exit(EXIT_FAILURE);
	}
	pl->head->next=NULL;
}

void insert_list_head(plinklist pl,nodeitem *pn)
{
	pnode p=create_node(pn);
	p->next=pl->head->next;
	pl->head->next=p;
}
void insert_list_tail(plinklist pl,nodeitem *pn)//����ط��в�࣬�����жϿձ������ˣ������󲿷�����������ǰ�pl->head��Ϊpl->head->next
{
	pnode temp=pl->head;
	pnode p=create_node(pn);
	while(temp->next)
		temp=temp->next;
	temp->next=p;
	
}
Bool is_inlist(plinklist pl,nodeitem *pn)
{
	pnode p=pl->head->next;
	while(p)
	{
     if(is_equal(&(p->elem),pn))
		 return 1;
	 p=p->next;
	}
	return 0;
}
void delete_list(plinklist pl,nodeitem* pn)//����ط��в�࣬�����ж��Ƿ�ɾ���Ľڵ��ǵ�һ���ڵ�����
{
	pnode curr,prev;
	if(is_inlist(pl,pn)){
    
	for(curr=pl->head->next,prev=pl->head;curr!=NULL&& !is_equal(&(curr->elem),pn);prev=curr,curr=curr->next)
		;
	
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
pnode p=pl->head->next;
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