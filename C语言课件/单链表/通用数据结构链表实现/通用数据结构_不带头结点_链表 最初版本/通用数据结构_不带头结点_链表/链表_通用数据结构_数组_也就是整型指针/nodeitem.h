#ifndef nodeitem_h
#define nodeitem_h
#define ARR_LEN 5
typedef int* nodeitem;
typedef int Bool;

Bool is_equal(nodeitem *p1, nodeitem *p2);
void display_nodeitem(nodeitem *pn);
void input_data(nodeitem na[],int n);
void copy_nodeitem(nodeitem *pn1,nodeitem *pn2);
void destroy_nodeitem(nodeitem *pn);

#endif