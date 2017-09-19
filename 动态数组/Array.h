#define CAPACITY 16;
#define GROTHFACTOR 2;  //增长比率因子
#define SHRINKFACTOR 4; //缩小比率因子
// 定义动态数组结构
typedef struct {
	int *array;
	int size;
	int capacity;
} Array;
//接口函数
Array *create(int capacity);
int size(Array *arrptr);
int capacity(Array *arrptr);
bool is_empty(Array *arrptr);
int at(Array *arrptr,int index);
void print(Array *arrptr);
void push(Array *arrptr,int item);
void insert(Array *arrptr,int index,int item);
void prepend(Array *arrptr,int item);
int pop(Array *arrptr);
void delete(Array *arrptr,int index);
void delByValue(Array *arrptr,int item);
int find(Array *arrptr,int item);
void resize(Array *arrptr,int type);

