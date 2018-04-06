/*
 * QueueOrder.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */


#include "QueueOrder.h"

void initQueue(Queue &Q) {

	// 初始化队列空间为 10
	Q.maxSize = 10;
	// 动态存储空间分配
	Q.queue = new ElemType[Q.maxSize];
	// 初始置队列为空
	Q.front = Q.rear = 0;
}

/**
 * 插入队列
 */
void enQueue(Queue &Q, ElemType item) {

	// 对存储空间用完情况进行处理
	if ((Q.rear + 1) % Q.maxSize == Q.front) {
		int k = sizeof(ElemType);
		Q.queue = (ElemType *)realloc(Q.queue, 2 * k * Q.maxSize);

		// 把原队尾内容移动到 maxSize 位置
		if (Q.rear != Q.maxSize-1) {
			for (int i=0; i<=Q.maxSize; i++) {
				Q.queue[i+Q.maxSize] = Q.queue[i];
			}
			Q.rear += Q.maxSize;
		}

		Q.maxSize *= 2;
	}

	// 求出队尾的下一个位置
	Q.rear = (Q.rear+1) % Q.maxSize;
	// 把 item 的值赋给新的队尾位置
	Q.queue[Q.rear] = item;
}

/**
 * 删除队列元素
 */

ElemType outQueue(Queue &Q) {
	if (Q.front == Q.rear) {
		cerr << "队列为空"<< endl;
		exit(1);
	}

	Q.front = (Q.front+1) % Q.maxSize;
	return Q.queue[Q.front];
}


/**
 * 判断队列是否为空
 */

bool emptyQueue(Queue &Q) {
	return Q.front == Q.rear;
}

/**
 * 清空队列
 */

void clearQueue(Queue &Q) {
	if (Q.queue != NULL) {
		delete Q.queue;
		Q.queue = NULL;
	}
	Q.front = 0;
	Q.rear = 0;
	Q.maxSize = 0;
}











