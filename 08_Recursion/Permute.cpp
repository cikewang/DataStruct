/*
 * 全排列
 *例如：123 全排列如下
 *1 2 3
 *1 3 2
 *2 1 3
 *2 3 1
 *3 2 1
 *3 1 2
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "Permute.h"

/**
 * 全排列
 */
void Permute(int a[], int s, int n) {
	int i, temp;

	// 当递归排序到最后一个元素时结束递归，输出 a中保持的一种排列
	if (s == n-1) {
		for (i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		// 循环 s-n次，每次使 a[s] 取一个新值
		for (i=s; i<n; i++) {
			// 交换 a[s] 与 a[i] 的元素值
			temp = a[s];
			a[s] = a[i];
			a[i] = temp;
			// 对 a[s+1] ~ a[n-1] 中的元素进行递归排序
			Permute(a, s+1, n);
			// 恢复 a[s] 与 a[i] 的原有值
			temp = a[s];
			a[s] = a[i];
			a[i] = temp;
		}
	}
}


/**
 * 测试全排列
 */
void testPermute() {
	const int upperLimit = 6;

	int a[upperLimit];
	int n;

	while (1) {
		cout << "请输入n的值，它应该在 1和" << upperLimit << "之间:";
		cin >> n;
		if (n >= 1 && n <= upperLimit) {
			break;
		}
	}

	for (int i=0; i<n; i++) {
		a[i] = i+1;
	}

	Permute(a, 0, n);
	cout << endl;
}
