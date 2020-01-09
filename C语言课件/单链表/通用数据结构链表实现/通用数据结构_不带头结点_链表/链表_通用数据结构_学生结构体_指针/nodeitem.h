#ifndef nodeitem_h
#define nodeitem_h
#define LEN 100
typedef int Bool;
typedef struct {
	int num;
	char sex;
	char name[LEN];
}stu,*pstu;
typedef pstu nodeitem;

void input_data(stu *s[],int n);
void input_single_stu(stu *ps);
Bool is_equal(nodeitem *p1, nodeitem *p2);
void display_nodeitem(nodeitem *pn);
void copy_nodeitem(nodeitem *pn1,nodeitem *pn2);
void destroy_nodeitem(nodeitem *pn);

#endif