/*
 * SetLinked.h
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#ifndef SETLINKED_H_
#define SETLINKED_H_

#include <iostream>
using namespace std;

typedef int ElemType;

struct SNode{
	ElemType data;
	SNode *next;
};

void initSet(SNode* &HT);
void clearSet(SNode* &HT);
int lengthSet(SNode *HT);
bool emptySet(SNode *HT);
bool inSet(SNode *HT, ElemType item);
void outputSet(SNode *HT);
bool findSet(SNode *HT, ElemType &item);
bool modifySet(SNode *HT, const ElemType item);
bool insertSet(SNode* &HT, ElemType item);
bool deleteSet(SNode* &HT, ElemType &item);
void unionSet(SNode *HT1, SNode *HT2, SNode* &HT);
void interseSet(SNode *HT1, SNode *HT2, SNode* &HT);
void differenceSet(SNode *HT1, SNode *HT2, SNode* &HT);



#endif /* SETLINKED_H_ */
