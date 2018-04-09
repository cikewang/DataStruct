/*
 * test_tree.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: libo
 */

#include "Tree.h"
#include <stdlib.h>

int main(void) {

	BTreeNode *bt;
	initBTree(bt);

	char b[50];

	cout << "输入二叉树用广义表表示的字符串：" << endl;
	cin.getline(b, sizeof(b));

	// 创建
	creatBTree(bt, b);

	// 输出
	printBTree(bt);
	cout << endl;

	cout << "前序遍历：" << endl;
	preOrder(bt);
	cout << endl;


	cout << "中序遍历：" << endl;
	inOrder(bt);
	cout << endl;


	cout << "后序遍历：" << endl;
	postOrder(bt);
	cout << endl;

	ElemType x;
	cin >> x;
	if (findBTree(bt, x)) {
		cout << "找到字符 " << x << endl;
	} else {
		cout << "没有找到字符 " << x << endl;
	}

	cout << "深度：" << depthBTree(bt) << endl;
	return 0;
}


