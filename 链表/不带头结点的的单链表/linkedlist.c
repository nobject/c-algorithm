#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
	LinkedList *list = NULL;
	list = fillList(list);
	printList(list); 
	Node *fNode = first(list);
	printf("首结点：%d\n", fNode->value);
	Node *lNode = last(list);
	printf("末结点：%d\n", lNode->value);
	Node *findNode = find(list,2);
	deleteNode(list,2);
	printList(list);
	makeEmpty(list);
	//printList(list);
	return 0;
}

//往链表中填充数据
LinkedList* fillList(LinkedList *list){  
	Node *p,*pMove;
	pMove = list;
	while(1){
	    //初始化一个新结点 
		p = (Node *)malloc(sizeof(Node));
		p->next = NULL;
		scanf("%d",&(p->value));
		if(p->value < 0){
			free(p);
			break;
		}
		if(list == NULL){
			pMove = list = p;
		}else{
			pMove->next = p;
		    pMove = pMove->next;
		}
	}
	printf("%s数据填充完成\n", __FUNCTION__);
	return list;
}
//查找相应位置上的节点，并返回该节点
Node *find(LinkedList *list,int index){
	int pos = 1;
	while(list!=NULL && pos != index){
		pos++;
		list = list->next;
	}
	printf("%s查找第%d个元素成功，值为%d\n", __FUNCTION__,index,list->value);
	return list;
}
//删除相应位置上的节点
void deleteNode(LinkedList *list,int index){
	int pos = 1;
	while(list!=NULL && pos != index-1){
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
	while(list!=NULL){
		p = list->next;
		free(list);
		list = p;
		
	}
	printf("%清空链表成功\n", __FUNCTION__);
}
//获取首节点
Node *first(LinkedList *list){
	return list;
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
	while(list!=NULL){
		printf("%d\n",list->value);
		list = list->next;
	}
	printf("%s数据打印完成\n", __FUNCTION__);
}