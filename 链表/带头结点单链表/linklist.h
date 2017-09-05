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
List insertAsFirst(ElementType e);
//将e当作末节点插入
List insertAsLast(ElementType e);
//将e当作节点P的直接前驱插入
void insertBefore(Postion p, ElementType e,List list);
//将e当作节点P的直接后继插入
void insertAfter(Postion p, ElementType e,List list);
//删除位置p处的节点，并返回其数值
ElementType remove(Postion p);
//查找目标元素e，失败时返回NULL
Postion find(ElementType e);
