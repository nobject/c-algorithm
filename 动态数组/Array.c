#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "stdbool.h"
#include "Array.h"

int main(int argc, char const *argv[])
{
	Array *arrptr = create(8);
	push(arrptr, 3);
	push(arrptr, 8);
	push(arrptr, 7);
	push(arrptr, 6);
	push(arrptr, 2);
	print(arrptr);
	printf("size = %d\n", size(arrptr));
	printf("capacity = %d\n", capacity(arrptr));
	printf("index = %d 的 值 = %d\n", 2, at(arrptr, 2));
	insert(arrptr, 4, 0);
	printf("插入index = %d 的 值 = %d\n", 4, 0);
	print(arrptr);
	pop(arrptr);
	prepend(arrptr, 12);
	prepend(arrptr, 9);
	prepend(arrptr, 3);
	prepend(arrptr, 20);
	print(arrptr);

	return 0;
}
Array *create(int capacity) {
	Array *arrptr;
	arrptr = malloc(sizeof(Array));
	int *array = malloc(capacity * sizeof(int));
	arrptr->array = array;
	arrptr->capacity = capacity;
	arrptr->size = 0;
	return arrptr;
}
int size(Array *arrptr) {
	return arrptr->size;
}
int capacity(Array *arrptr) {
	return arrptr->capacity;
}
bool is_empty(Array *arrptr) {
	if (arrptr->size == 0) {
		return true;
	} else {
		return false;
	}
}
int at(Array *arrptr, int index) {
	if (index > arrptr->size - 1 || index < 0) {
		exit(0);
	}
	return *(arrptr->array + index);
}

void push(Array *arrptr, int item) {
	//判断空间是否足够,如果不够，需要扩容
	if (arrptr->size == arrptr->capacity) {
		resize(arrptr , 1);
	}
	*(arrptr->array + arrptr->size) = item;
	arrptr->size++;
}
void insert(Array *arrptr, int index, int item) {
	//判断空间是否足够,如果不够，需要扩容
	if (arrptr->size == arrptr->capacity) {
		resize(arrptr, 1);
	}

	int size = arrptr->size;
	printf("size的 值 = %d\n", size);
	while (size > index) {
		*(arrptr->array + size) = *(arrptr->array + size - 1);
		size --;
	}
	*(arrptr->array + index) = item;
	arrptr->size++;
}
void prepend(Array *arrptr , int item) {
	insert(arrptr, 0, item);
}
int pop(Array *arrptr) {
	if (arrptr->size < 0) {
		exit(0);
	}
	int popItem = *(arrptr->array + arrptr->size - 1);
	arrptr->size--;
	return popItem;
}
void delete(Array *arrptr, int index) {
	if (arrptr->size < 0) {
		exit(0);
	}
	int *array = arrptr->array;
	while (index < arrptr->size - 1) {
		*(arrptr->array - 1 + index++) = *(array + index);
	}
	arrptr->size--;
}
void delByValue(Array *arrptr, int item) {
	int index = 0;
	while (index < arrptr->size) {
		if (*(arrptr->array + index) == item) {
			break;
		}
		index++;
	}
	if (index != arrptr->size) {
		delete(arrptr, index);
	}
}
int find(Array *arrptr, int item) {
	int index = 0;
	while (index < arrptr->size) {
		if (*(arrptr->array + index) == item) {
			break;
		}
		index++;
	}
	if (index == arrptr->size) {
		index = -1;
	}
	return index;
}
//扩容 | 缩容
void resize(Array *arrptr , int type) {
	int capacity = 0;
	if (type == 1) {
		capacity = arrptr->capacity * GROTHFACTOR;
	} else {
		capacity = arrptr->capacity / SHRINKFACTOR;
	}
	int *array = (int *)malloc(capacity*sizeof(int));
	
	//将旧数据拷贝到新数据
	for (int i = 0; i < arrptr->size; ++i) {
    	*(array + i) = *(arrptr->array + i);
  	}
  	arrptr->capacity = capacity;
	arrptr->array = array;
}

void print(Array *arrptr) {
	printf("Size: %d\n", arrptr->size);
	printf("Capacity: %d\n", arrptr->capacity);

	printf("Items:\n");
	for (int i = 0; i < arrptr->size; ++i) {
		printf("%d: %d\n", i, *(arrptr->array + i));
	}

	printf("---------\n");
}