/*
 * Tree.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: libo
 */

#include "Tree.h"

/**
 * 初始化树
 */
void initBTree(BTreeNode* &BT) {
	BT = NULL;
}

/**
 * 广义表格式创建
 */
void creatBTree(BTreeNode* &BT, char *a) {
	// 栈数组长度要大于等于二叉树的深度减1
	const int maxSize = 10;
	// s 数组作为存储根结点指针的栈使用
	BTreeNode *s[maxSize];
	// top 作为栈顶指针，初值为 -1，表示空栈
	int top = -1;
	// 把树根指针置为空，既从空树开始
	BT = NULL;
	// 定义 p为指向二叉树结点的指针
	BTreeNode *p = NULL;
	// 用 k 作为处理结点的左子树和右子树的标记， k = 1 处理左子树，k = 2 处理右子树
	int k=0;
	// 用 i 扫描数组 a 中存储的二叉树广义表字符串
	int i=0;

	while (a[i]) {
		switch(a[i]) {
			// 空格不做处理
			case ' ':
				break;
			case '(':
				if (top == maxSize -1) {
					cout << "栈空间不足，请添加 maxSize值" << endl;
					exit(1);
				}
				top++;
				s[top]=p;
				k = 1;
				break;
			case ')':
				if (top == -1) {
					cout << "二叉树广义表字符串错误" << endl;
					exit(1);
				}
				top--;
				break;
			case ',':
				k = 2;
				break;
			default:
				p = new BTreeNode;
				p->data = a[i];
				p->left = p->right = NULL;
				if (BT == NULL) {
					// 作为根结点插入
					BT = p;
				} else {
					if (k == 1) {
						// 作为左孩子结点插入
						s[top]->left = p;
					} else {
						// 作为右孩子结点插入
						s[top]->right = p;
					}
				}
		}
		i++;
	}
}

/**
 * 判断是否为空
 */
bool emptyBTree(BTreeNode *BT) {
	return BT == NULL;
}

/**
 * 求二叉树深度
 */
int depthBTree(BTreeNode *BT) {
	if (BT == NULL) {
		return 0;
	} else {
		int dep1 = depthBTree(BT->right);
		int dep2 = depthBTree(BT->right);

		if (dep1 > dep2) {
			return dep1 + 1;
		}
		return dep2 + 1;
	}
}

/**
 * 从二叉树中查找值为 x的结点，存在返回 true，否则返回 false
 */
bool findBTree(BTreeNode *BT, ElemType &x) {
	if (BT == NULL) {
		return false;
	} else {
		if (BT->data == x) {
			x = BT->data;
			return true;
		} else {
			if (findBTree(BT->left, x)) {
				return true;
			}
			if (findBTree(BT->right, x)) {
				return true;
			}
		}
	}
	return false;
}

/**
 * 输出二叉树
 */
void printBTree(BTreeNode *BT) {

	if (BT != NULL) {
		cout << BT->data;
		if (BT->left != NULL  || BT->right != NULL) {
			cout << '(';
			printBTree(BT->left);
			if (BT->right != NULL)
				cout << ',';
			printBTree(BT->right);
			cout << ')';
		}
	}
}


/**
 * 清除二叉树
 */
void clearBTree(BTreeNode* &BT) {
	if (BT != NULL) {
		clearBTree(BT->left);
		clearBTree(BT->right);
		delete BT;
		BT = NULL;
	}
}

/**
 * 前序遍历
 */

void preOrder(BTreeNode *BT) {
	if (BT != NULL) {
		cout << BT->data << ' ';
		preOrder(BT->left);
		preOrder(BT->right);
	}
}

/**
 * 中序遍历
 */
void inOrder(BTreeNode *BT) {
	if (BT != NULL) {
		inOrder(BT->left);
		cout << BT->data << ' ';
		inOrder(BT->right);
	}
}

/**
 * 后续遍历
 */
void postOrder(BTreeNode *BT) {
	if (BT != NULL) {
		postOrder(BT->left);
		postOrder(BT->right);
		cout << BT->data << ' ';
	}
}





