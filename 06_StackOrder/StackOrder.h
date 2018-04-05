/*
 * Stack.h
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */



#include <iostream>
using namespace std;

typedef int ElemType;

struct Stack {
	ElemType *stack;
	int top;
	int maxSize;
};


void initStack(Stack &S);
void push(Stack &S, ElemType item);
ElemType pop(Stack &S);
ElemType peek(Stack &S);
bool emptyStack(Stack &S);
void clearStack(Stack &S);

