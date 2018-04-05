/*
 * StackLinked.h
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#ifndef STACKLINKED_H_
#define STACKLINKED_H_

#include <iostream>
using namespace std;

typedef int ElemType;

struct Stack {
	ElemType data;
	Stack *next;
};

void initStack(Stack* &HS);
void push(Stack* &HS, const ElemType &item);
ElemType pop(Stack* &HS);
ElemType peek(Stack *HS);
bool emptyStack(Stack *HS);
void clearStack(Stack *HS);


#endif /* STACKLINKED_H_ */
