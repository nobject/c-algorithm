#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
// 定义链表结构体
struct Node
{
	ElementType Element;
	Position    Next;
};

int main(int argc, char const *argv[])
{
	printf("2");
	exit;printf("首节点：%d\n",first->Element);
	List list = init();
	insertAfter(list,1,list);
	insertAfter(list,2,list);
	Position first = first(list);
	printf("首节点：%d\n",first->Element);
	Position last = last(list);
	printf("尾节点：%d\n",last->Element);
	int size = size(list);
	printf("链表长度：%d\n",size);
	return 0;
}
/**
* 链表初始化
*/
List init() {
	Position head = Position malloc(sizeof(Node));
	head->Next = NULL;
	return head;
}
//首节点
Position first(List list) {
	return list->Next;
}
//末节点
Position last(List list) {
	while (list->Next != NULL) {
		list = list->Next;
	}
	return list;
}
//链表长度
int size(List list) {
	int size = 0;
	while (list->Next != NULL) {
		size++;
	}
	return size;
}
/**
* 在某一项之前插入
*/
void insertBefore(Position p, ElementType e,List list) {
	Position tempCell = malloc(sizeof(struct Node));
	tempCell->Element = e;
	tempCell->Next = p;
	Position prev = prev(p,list);
	prev->Next = tempCell;
}
/**
* 在某一项之后插入
*/
void insertAfter(Position p, ElementType e,List list) {
	Position tempCell = malloc(sizeof(struct Node));
	tempCell->Element = e;
	tempCell->Next = p->Next;
	p->next = tempCell;
}
/**
* 删除链表中的某一项
*/
ElementType remove(Position p,List list){
	Position prev = prev(p,list);
	prev->next = p->next;
	free(p);
}

void delete(List *list){
	
}
/**
* 获取前驱
*/
Position prev(Position p,List list){
	Position prev;
	while(list->Next!=NULL){
		if(list->Next == p){
			prev = list;
			break;
		}
		list = list->Next;
	}
	return prev;
}