/*
 * test_StackLinked.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "StackLinked.h"

int main(void) {

	Stack *s;
	initStack(s);

	int x;
	cin>> x;
	while (x != -1) {
		push(s, x);
		cin>>x;
	}

	while (!emptyStack(s)) {
		cout << pop(s) << " ";
	}
	cout << endl;
	clearStack(s);

	return 0;
}


