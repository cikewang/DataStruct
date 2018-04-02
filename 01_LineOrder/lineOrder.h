/*
 * lineOrder.h
 *
 *  Created on: 2018年3月30日
 *      Author: libo
 */

#ifndef LINEORDER_H_
#define LINEORDER_H_
#include <iostream>
using namespace std;

typedef int ElemType;

struct List {
	ElemType *list;
	int size;
	int maxSize;
};

void initList(List &L);
void clearList(List &L);
int LengthList(List &L);
bool checkListIsEmpty(List &L);
ElemType getList(List &L, int pos);
void traverseList(List &L);
bool findList(List &L, ElemType &item);
bool updateList(List &L, const ElemType &item);
bool insertList(List &L, ElemType &item, int pos);
bool deleteList(List &L, ElemType &item, int pos);
void sortList(List &L);

#endif /* LINEORDER_H_ */
