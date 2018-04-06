/*
 * Hanoi.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */


#include "Hanoi.h"

void Hanoi(int n, int a, int b, int c) {

	if (n == 1) {
		// 当只有一个盘子时，直接将 a 柱子上移到 c 柱子上结束
		cout << a << " -> " << c << ", ";
	} else {
		// 首先把 n-1 个盘子由  a 柱子搬到 b 柱子上
		// 用参数 c 表示过度
		Hanoi(n-1, a, c, b);
		// 把 a 柱子上最后一个盘子搬到 c柱子上
		cout << a << " -> " << c << ", ";
		// 最后把 n-1 个盘子由 b 柱子搬到 c 柱子上
		// 用 a 表示过度柱子
		Hanoi(n-1, b, a, c);
	}
	cout << endl;
}

