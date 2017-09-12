#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
	//定义一个指向结构体的指针(头结点)，此时该指针为野指针，指向内存里的随机一个地址
	LinkedList *list;
	printf("声明头结点的地址：%p\n", &list);
	printf("声明头结点所指向的地址：%p\n", *list);
	//初始化，传递该指针(头结点)的地址，如果不传地址，只传指针
	initList(&list);
	printf("头结点的地址：%p\n", &list);
	printf("头结点所指向的地址：%p\n", list);
	fillList(list);
	printList(list); 
	Node *fNode = first(list);
	printf("首结点：%d\n", fNode->value);
	Node *lNode = last(list);
	printf("末结点：%d\n", lNode->value);
	Node *findNode = find(list,2);
	deleteNode(list,2);
	printList(list);
	makeEmpty(list);
	printList(list);
	return 0;
}

//初始化一个链表,构建头结点 head = &list(头结点本身的地址),*head = list（头结点所指向的地址）,**head = *list(头结点所指向的地址存放的结点的内容)
void initList(LinkedList **head){
	printf("头结点所指向的地址：%p\n", *head);
	*head = (LinkedList *)malloc(sizeof(LinkedList));
	printf("分配空间后头结点所指向的地址：%p\n", *head);
	(*head)->next = NULL;  
	printf("%s带头结点的链表初始化成功\n", __FUNCTION__);
}
//往链表中填充数据
void fillList(LinkedList *list){  
	Node *p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	scanf("%d",&(p->value));
	while(p->value > 0){
		list->next= p;
		list = p;
		p = (Node *)malloc(sizeof(Node));
		p->next = NULL;
		scanf("%d",&(p->value));
	}
	printf("%s数据填充完成\n", __FUNCTION__);
}
//查找相应位置上的节点，并返回该节点
Node *find(LinkedList *list,int index){
	int pos = 0;
	while(list->next!=NULL && pos != index){
		pos++;
		list = list->next;
	}
	if(list == NULL){
		
	}
	printf("%s查找第%d个元素成功，值为%d\n", __FUNCTION__,index,list->value);
	return list;
}
//删除相应位置上的节点
void deleteNode(LinkedList *list,int index){
	int pos = 0;
	while(list->next!=NULL && pos != index-1){
		pos++;
		list = list->next;
	}
	Node *p = list->next;
	int value = p->value;
	list->next = list->next->next;
	free(p);
	printf("%s删除第%d个元素成功，值为%d\n", __FUNCTION__,index,value);
}
//清空链表
void makeEmpty(LinkedList *list){
	Node *p;
	while(list->next!=NULL){
		p = list->next;
		list->next = p->next;
		free(p);
	}
	printf("%清空链表成功\n", __FUNCTION__);
}
//获取首节点
Node *first(LinkedList *list){
	return list->next;
}
//获取末节点
Node *last(LinkedList *list){
	while(list->next!=NULL){
		list = list->next;
	}
	return list;
}
//打印链表数据
void printList(LinkedList *list){
	while(list->next!=NULL){
		list = list->next;
		printf("%d\n",list->value);
	}
	printf("%s数据打印完成\n", __FUNCTION__);
}