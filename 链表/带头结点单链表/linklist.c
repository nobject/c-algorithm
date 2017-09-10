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
	List list = init();
	fillList(list);
	Position firstNode = first(list);
	printf("首节点：%d\n",firstNode->Element);
	Position lastNode = last(list);
	printf("尾节点：%d\n",lastNode->Element);
	int length = size(list);
	printf("链表长度：%d\n",length);
	insertAsFirst(list,5);
	firstNode = first(list);
	printf("首节点：%d\n",firstNode->Element);
	insertAsLast(list,12);
	lastNode = last(list);
	printf("尾节点：%d\n",lastNode->Element);
	insert(list,3,2);
	printList(list);
	Position findNode = find(list,3);
	printf("查找的元素：%d\n",findNode->Element);
	makeEmpty(list);
	length = size(list);
	printf("清空后的链表长度：%d\n",length);
	return 0;
}
/**
* 链表初始化
*/
List init() {
	Position head = (struct Node*) malloc(sizeof(struct Node));
	head->Next = NULL;
	printf("%s函数执行,初始化头结点\n",__FUNCTION__);
	return head;
}
/**
* 填充链表内容
*/
void fillList(List list){
	Position p = malloc(sizeof(struct Node));
	p->Next = NULL;
	scanf("%d",&(p->Element));
	Position pNode = list;
	while(p->Element>0){
		pNode->Next = p;
		pNode = p;

		p = malloc(sizeof(struct Node));
		p->Next = NULL;
		scanf("%d",&(p->Element));
	}
	printf("%s函数执行,带头结点的单链表创建成功\n",__FUNCTION__);
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
		list = list->Next;
	}
	return size;
}
//将元素插入头部
void insertAsFirst(List list,int x){  
  
    Position p;
    p = (struct Node *)malloc(sizeof(struct Node));  
    p->Element = x;
  
    p->Next = list->Next;
    list->Next = p;
    printf("%s函数执行，在表头插入元素%d成功\n",__FUNCTION__,x);  
}
//将元素插入尾部
void insertAsLast(List list,int x){  
    Position p;
    p = (struct Node *)malloc(sizeof(struct Node));  
    p->Element = x;
  	
    p->Next = NULL;
    while(list->Next != NULL){
    	list = list->Next;
    }
    list->Next = p;
    printf("%s函数执行，在表尾插入元素%d成功\n",__FUNCTION__,x);  
}
//在指定的位置插入节点
void insert(List list,ElementType e,int index){
	Position p;
	int pos = 0;
	p = (struct Node *)malloc(sizeof(struct Node));  
	p->Element = e;
	while(list->Next!=NULL && pos!=index){
		list = list->Next;
		pos++;
	}
	p->Next = list->Next;
	list->Next = p;
	printf("%s函数执行，在%d插入元素%d成功\n",__FUNCTION__,index,e);  
}
//清空链表
void makeEmpty(List list){
	Position p;
	while(list->Next!=NULL){
		p = list->Next;
		list->Next = p->Next;
		free(p);
	}
	printf("%s函数执行，清空带头结点的链表成功\n",__FUNCTION__);  
}
//查找对应的节点
Position find(List list,int index){
	int pos = 0;
	while(list->Next!=NULL && pos !=index){
		list = list->Next;
		pos++;
	}
	return list; 
}

void printList(List list){
	while(list->Next!=NULL){
		list = list->Next;
		printf("%d\n", list->Element);
	}
}