//定义一个链表的数据类型
typedef struct List{
	int value;
	struct List *next;
} LinkedList;
//不带头结点的链表
//node1->node2->node3->node5
typedef LinkedList Node;
//初始化一个链表
void initList(LinkedList **list);  
//往链表中填充数据
LinkedList* fillList(LinkedList *list);
//查找相应位置上的节点，并返回该节点
Node *find(LinkedList *list,int index);
//删除相应位置上的节点
void deleteNode(LinkedList *list,int index);
//清空链表
void makeEmpty(LinkedList *list);
//获取首节点
Node *first(LinkedList *list);
//获取末节点
Node *last(LinkedList *list);
//打印链表数据
void printList(LinkedList *list);
