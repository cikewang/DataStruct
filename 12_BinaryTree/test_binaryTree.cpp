/*
 * test_binaryTree.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: libo
 */


#include "Tree.h"
#include "BinaryTree.h"

int main(void) {

	ElemType x;

	// 定义指向二叉搜索树结点的指针，并用它作为树根指针
	BTreeNode *bst;

	// 初始化二叉搜索树，即置树根指针 bst 为空
	initBTree(bst);

	// 定义数组 a 并初始化
	ElemType a[10] = {30, 50, 20, 40, 25, 70, 54, 23, 80, 92};

	// 利用数组 a 建立树根只在行业指针为 bst 的二叉搜索树
	createBStree(bst, a, 10);

	// 已广义表形式输出二叉搜索树
	printBTree(bst);
	cout << endl;

	// 求出以 bst 为根指针的二叉搜索树的深度
	cout << "深度：";
	cout << depthBTree(bst) << endl;

	// 中序遍历以 bst 为树根指针的二叉搜索树
	cout << "中序：";
	inOrder(bst);
	cout << endl;

	// 从二叉搜索树中查找一个结点
	cout << "输入一个待查找的整数值：";
	cin >> x;
	if (findBSTree(bst, x)) {
		cout << "查找元素" << x << "成功！" << endl;
	} else {
		cout << "查找元素" << x << "失败" << endl;
	}

	cout << "输入一个待插入结点的整数值：";
	cin >> x;
	insertBSTree(bst, x);

	// 从二叉搜索树中删除一个结点
	cout << "输入一个待删除结点的值：";
	cin >> x;
	if (deleteBSTree(bst, x)) {
		cout << "删除元素" << x << "成功！" << endl;
	} else {
		cout << "删除元素" << x << "失败！" << endl;
	}

	// 再以广义表形式输出二叉树
	printBTree(bst);
	cout << endl;

	cout << "中序：";
	inOrder(bst);
	cout << endl;

	clearBTree(bst);

}
