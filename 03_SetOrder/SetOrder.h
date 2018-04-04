/*
 * SetOrder.h
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#ifndef SETORDER_H_
#define SETORDER_H_

#include <iostream>
using namespace std;

typedef int ElemType;

struct Set {
	ElemType *set;	// 指向动态分配的数组空间
	int len;		// 集合当前长度
	int maxSize;	// 存集合数组长度，所能存储集合的最大长度
};

void initSet(Set &s);
void clearSet(Set &s);
int lengthSet(Set &s);
bool emptySet(Set &s);
bool inSet(Set &s, ElemType item);
void outputSet(Set &s);
bool findSet(Set &s, ElemType &item);
bool modifySet(Set &s, const ElemType &item);
bool insertSet(Set &s, ElemType item);
bool deleteSet(Set &s, ElemType &item);
void unionSet(Set &s1, Set &s2, Set &s);
void interseSet(Set &s1, Set &s2, Set &s);
void differenceSet(Set &s1, Set &s2, Set &s);

#endif /* SETORDER_H_ */
