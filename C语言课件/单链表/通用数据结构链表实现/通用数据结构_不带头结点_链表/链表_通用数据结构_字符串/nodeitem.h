#ifndef nodeitem_h
#define nodeitem_h
typedef char* nodeitem;
typedef int Bool;
#define MAX_LEN 100

Bool is_equal(nodeitem *p1, nodeitem *p2);
void display_nodeitem(nodeitem *pn);
void copy_nodeitem(nodeitem *pn1,nodeitem *pn2);//copy the value of pn2 to pn1
void input_data(nodeitem na[],int n);
void destroy_nodeitem(nodeitem *pn);

#endif