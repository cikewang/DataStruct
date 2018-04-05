/*
 * Transform.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "Transform.h"

void Transform(long num, int r) {

	Stack *a;
	initStack(a);

	while (num != 0) {
		int k = num%r;
		push(a, k);
		num /= r;
	}

	while (!emptyStack(a)) {
		cout << pop(a);
	}
	cout << endl;
}


