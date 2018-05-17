/*
 * Head.h
 *
 *  Created on: 2018年5月17日
 *      Author: libo
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int ElemType;

struct Heap {
	ElemType *heap;
	int len;
	int maxSize;
};


// 初始化一个堆为空
void initHeap(Heap &HBT);
// 清除一个堆，使之为空
void clearHeap(Heap &HBT);
// 判断一个堆是否为空
bool emptyHeap(Heap &HBT);
// 向堆中插入元素
void insertHeap(Heap &HBT, ElemType item);
// 从堆中删除堆顶元素并返回
ElemType deleteHeap(Heap &HBT);

#endif /* HEAP_H_ */
