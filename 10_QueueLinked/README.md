# 队列 - 链接存储结构
	队列链接存储结构也是通过由结点构成的单链表实现的

### 队列连接存储
~~~
typedef int ElemType;
struct LinkeQueueK {
	LNode *front;		// 队首指针
	LNode *rear;		// 队尾指针
}

struct LNode {
	ElemType data;
	LNode *next
}
~~~

![队列链接表示意图](https://github.com/cikewang/DataStruct/blob/master/Z_Images/10_01.jpg)