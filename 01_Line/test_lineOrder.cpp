#include <iostream>
#include <stdlib.h>
#include "lineOrder.h"

int main(void) {


	int a[10] = {2,3,4,5,6,7,8,9,1,10};
	int i;
	ElemType x;

	// 初始化
	List t;
	initList(t);

	// 赋值
	for (i=0; i<10; i++) {
		cout << a[i] << " ";
		insertList(t, a[i], i+1);
	}
	cout << endl;

	// 遍历输出
	traverseList(t);

	// 获取单个
	cout << getList(t, 4) << endl;

	// 查找指定参数
	cin >> x;
	if (findList(t, x)) {
		cout << "查找成功" << endl;
	} else {
		cout << "查找失败" << endl;
	}

	// 删除
	if (deleteList(t, x, 0)) {
		cout << "删除成功" << endl;
	} else {
		cout << "删除失败" << endl;
	}

	// 遍历输出
	traverseList(t);

	for (i=0; i<3; i++) {
		deleteList(t, x, i);
	}

	// 遍历输出
	traverseList(t);

	cout << "按值插入,输入待插入元素的值：" << endl;
	cin >> x;
	if (insertList(t, x, 0)) {
		cout << "插入成功" << endl;
	} else {
		cout << "插入失败" << endl;
	}

	// 遍历输出
	traverseList(t);

	// 排序
	sortList(t);

	// 遍历输出
	traverseList(t);

	clearList(t);

	// 遍历输出
	traverseList(t);

	if (checkListIsEmpty(t)) {
		cout << "列表为空" << endl;
	} else {
		cout << "列表不为空" << endl;
	}

	return 0;
}



