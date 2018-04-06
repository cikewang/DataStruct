/*
 * QueueLinked.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#include "QueueLinked.h"

/**
 * 初始化
 */
void initQueue(LinkQueue &HQ) {
	HQ.front = HQ.rear = NULL;
}

/**
 * 入队列
 */
void enQueue(LinkQueue &HQ, ElemType item) {

	LNode *newptr = new LNode;
	newptr->data = item;
	newptr->next = NULL;

	if (HQ.rear == NULL) {
		HQ.front = HQ.rear = newptr;
	} else {
		// 若队列非空，则新结点被链接到队尾并修改队尾指针
		HQ.rear = HQ.rear->next = newptr;
	}
}

/**
 * 从队列中删除一个元素
 */
ElemType outQueue(LinkQueue &HQ) {

	if (HQ.front == NULL) {
		cerr << "队列为空" << endl;
		exit(1);
	}

	// 暂存队首元素以便返回
	ElemType temp = HQ.front->data;
	// 暂存队首指针一遍回收队首结点
	LNode *p = HQ.front;
	// 将队首指针指向下一个结点
	HQ.front = p->next;
	if (HQ.front == NULL) {
		// 若删除后链对为空，则使队尾指针为空
		HQ.rear = NULL;
	}
	// 回收原队首结点
	delete p;

	return temp;
}

/**
 * 读取队首元素
 */
ElemType peekQueue(LinkQueue &HQ) {
	if (HQ.front == NULL) {
		cerr << "队列为空" << endl;
		exit(1);
	}

	return HQ.front->data;
}

/**
 * 判断队列是否为空
 */
bool emptyQueue(LinkQueue &HQ) {
	// 判断队首或队尾是否为空指针
	return HQ.front == NULL;
}

/**
 * 清空队列
 */
void clearQueue(LinkQueue &HQ) {

	LNode *p = HQ.front;
	while (p != NULL) {
		HQ.front = HQ.front->next;
		delete p;
		p = HQ.front;
	}
	HQ.front = NULL;
	HQ.rear = NULL;
}













