/*
 * Stack.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */


#include "StackOrder.h"

/**
 * 初始化
 */
void initStack(Stack &S) {
	S.maxSize = 10;

	S.stack = new ElemType[S.maxSize];
	if (!S.stack) {
		cerr << "动态存储分配失败" << endl;
		exit(1);
	}

	S.top = -1;
}

/**
 * 压栈
 */
void push(Stack &S, ElemType item) {

	if (S.top == S.maxSize - 1) {
		int k = sizeof(ElemType);
		S.stack = (ElemType *)realloc(S.stack, 2 * k * S.maxSize);
		S.maxSize = 2 * S.maxSize;
	}

	S.top++;
	S.stack[S.top] = item;
}

/**
 * 出栈
 */
ElemType pop(Stack &S) {

	if (S.top < 0) {
		cerr << "栈为空" << endl;
		exit(1);
	}

	S.top--;
	return S.stack[S.top+1];
}

/**
 * 读取栈顶元素，栈不改变
 */
ElemType peek(Stack &S) {

	if (S.top < 0) {
		cerr << "栈为空" << endl;
		exit(1);
	}

	return S.stack[S.top];
}

/**
 * 判断栈是否为空
 */
bool emptyStack(Stack &S) {
	return S.top == -1;
}

/**
 * 清空栈
 */
void clearStack(Stack &S) {
	if (S.stack) {
		delete S.stack;
		S.stack = NULL;
	}
	S.top = -1;
	S.maxSize = 0;
}

