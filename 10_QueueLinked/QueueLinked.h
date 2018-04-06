/*
 * QueueLinked.h
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#ifndef QUEUELINKED_H_
#define QUEUELINKED_H_

#include <iostream>
using namespace std;

typedef int ElemType;

struct LNode {
	ElemType data;
	LNode *next;
};

struct LinkQueue {
	LNode *front;
	LNode *rear;
};

void initQueue(LinkQueue &HQ);
void enQueue(LinkQueue &HQ, ElemType item);
ElemType outQueue(LinkQueue &HQ);
ElemType peekQueue(LinkQueue &HQ);
bool emptyQueue(LinkQueue &HQ);
void clearQueue(LinkQueue &HQ);


#endif /* QUEUELINKED_H_ */
