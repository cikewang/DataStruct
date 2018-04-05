/*
 * test_Stack.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */


#include "StackOrder.h"

int main(void) {

	Stack s;
	initStack(s);

	int a[8] = {3, 2, 5, 76,4, 23, 34,1};
	int count =  sizeof(a)/4;

	int i;
	for (i=0; i<count; i++) {
		push(s, a[i]);
	}

	while (!emptyStack(s)) {
		cout << pop(s) << " ";
	}
	cout << endl;

	clearStack(s);

	return 0;
}

