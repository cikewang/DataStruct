/*
 * linkedList.h
 *
 *  Created on: 2018年4月2日
 *      Author: libo
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

typedef int ElemType;
struct LNode {
	ElemType data;
	LNode *next;
};

void initList(LNode* &HL);
void clearList(LNode* &HL);
int lengthList(LNode *HL);
ElemType getList(LNode *HL, int pos);
void traverseList(LNode *HL);
bool findList(LNode *HL, ElemType &item);
bool updateList(LNode *HL, const ElemType &item);
bool insertList(LNode* &HL, ElemType item, int pos);
bool deleteList(LNode* &HL, ElemType &item, int pos);
void sortList(LNode* &HL);
void reversLinked(LNode* &HL);
LNode *reversLinked2(LNode* HL);
ElemType getMaxItem(LNode *HL);

#endif /* LINKEDLIST_H_ */
