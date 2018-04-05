/*
 * test_StackLinked.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "StackLinked.h"
#include "Transform.h"


int main(void) {

	cout << "请输入整数入栈，-1 结束：" << endl;
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


	cout << "数字转换" << endl;

	Transform(10, 2);
	Transform(10, 16);
	Transform(10, 8);
	return 0;
}


