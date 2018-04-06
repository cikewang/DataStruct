/*
 * QueueOrder.h
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#ifndef QUEUEORDER_H_
#define QUEUEORDER_H_

#include <iostream>
using namespace std;

typedef int ElemType;

struct Queue {
	ElemType *queue;
	int front, rear, len;	// 队首指针，尾指针，队列长度变量
	int maxSize;
};

void initQueue(Queue &Q);
void enQueue(Queue &Q, ElemType item);
ElemType outQueue(Queue &Q);
bool emptyQueue(Queue &Q);
void clearQueue(Queue &Q);


#endif /* QUEUEORDER_H_ */
