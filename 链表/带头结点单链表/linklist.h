// ADT
//元素类型定义
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
//链表初始化
List init();
//链表大小
int size(List list);
//首节点
Position first();
//末节点
Position last();
//将e当作首节点插入
void insertAsFirst(List list,ElementType e);
//将e当作末节点插入
void insertAsLast(List list,ElementType e);
void fillList(List list);
void makeEmpty(List list);
Position find(List list,int index);
void insert(List list,ElementType e,int index);
void printList(List list);
