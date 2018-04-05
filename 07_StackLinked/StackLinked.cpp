/*
 * StackLinked.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "StackLinked.h"

/**
 * 初始化
 */
void initStack(Stack* &HS) {
	HS = NULL;
}

/**
 * 进栈
 */
void push(Stack* &HS, const ElemType &item) {
	Stack *newptr = new Stack;
	newptr->data = item;
	newptr->next = HS;
	HS = newptr;
}

/**
 * 出栈
 */
ElemType pop(Stack* &HS) {
	if (HS == NULL) {
		cerr << "栈为空" << endl;
		exit(1);
	}

	Stack *p = HS;
	HS = HS->next;
	ElemType temp = p->data;
	delete p;
	return temp;
}

/**
 * 输出栈顶元素
 */
ElemType peek(Stack *HS) {
	if (HS == NULL) {
		cerr << "栈为空" << endl;
		exit(1);
	}

	return HS->data;
}

/**
 * 判断是否为空
 */
bool emptyStack(Stack *HS) {
	return HS == NULL;
}

/**
 * 清空栈
 */
void clearStack(Stack *HS) {

	Stack *cp, *np;
	cp = HS;
	while (cp != NULL) {
		np = cp->next;
		delete cp;
		cp = np;
	}
	HS = NULL;
}
