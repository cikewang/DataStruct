/*
 * BinaryTree.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: libo
 */


#include "BinaryTree.h"


/**
 * 二叉搜索树递归查找方法
 */
bool findBSTree(BTreeNode *BT, ElemType &item) {

	if (BT == NULL) {
		return false;
	} else {
		if (BT->data == item) {
			item = BT->data;
			return true;
		} else if(item < BT->data) {
			return findBSTree(BT->left, item);
		} else {
			return findBSTree(BT->right, item);
		}
	}
}

/**
 * 二叉搜索树，非递归查找方法
 */
bool findBSTree1(BTreeNode *BT, ElemType &item) {

	while (BT != NULL) {
		if (item == BT->data) {
			item = BT->data;
			return true;
		} else if (item < BT->data) {
			BT = BT->left;
		} else {
			BT = BT->right;
		}
	}
	return false;
}

/**
 * 递归插入元素
 */
void insertBSTree(BTreeNode *&BT, const ElemType &item) {

	if (BT == NULL) {
		// 把按照 item 元素生成的新结点连接到已找到的插入位置
		BTreeNode *p = new BTreeNode;
		p->data = item;
		p->left = p->right = NULL;
		BT = p;
	} else if(item < BT->data) {
		// 向左子树插入元素
		insertBSTree(BT->left, item);
	} else {
		// 向右子树插入元素
		insertBSTree(BT->right, item);
	}
}

/**
 * 非递归插入
 */
void insertBSTree1(BTreeNode *&BT, const ElemType &item) {

	// 为插入新元素寻找插入位置，定义指针 t 指向当前待比较的结点，初始指向树根结点，
	// 定义指针 parent 指向 t结点的双亲结点，初始为 NULL
	BTreeNode *t = BT, *parent = NULL;
	while (t != NULL) {
		parent = t;
		if (item < t->data) {
			t = t->left;
		} else {
			t = t->right;
		}
	}

	BTreeNode *p = new BTreeNode;
	p->data = item;
	p->left = p->right = NULL;
	// 将新结点插入到二叉树BST中
	if (parent == NULL) {
		BT = p;
	} else if (item < parent->data) {
		parent->left = p;
	} else {
		parent->right = p;
	}
}

void updateBSTree(BTreeNode *&BT, ElemType &item) {

}

/**
 * 利用数组中的 n个元素建立二叉搜索树的算法
 */
void createBStree(BTreeNode *&BT, ElemType a[], int n) {
	BT = NULL;
	for (int i=0; i<n; i++) {
		insertBSTree(BT, a[i]);
	}
}

// 从二叉搜索树 BST中删除值为 item的结点，树根指针必须为引用
bool deleteBSTree(BTreeNode *&BT, const ElemType &item) {

	// 树为空，未找到待删除元素，返回假表示删除失败
	if (BT == NULL) {
		return false;
	}

	if (item < BT->data) {
		// 待删除元素小于根结点值，继续在右子树中删除
		return deleteBSTree(BT->left, item);
	} else {
		// 待删除元素大于根结点值，继续在右子树中删除
		return deleteBSTree(BT->right, item);
	}

	BTreeNode *temp = BT;
	// 待删除元素等于树根结点值且左子树为空，将右子树作为整个树并返回真
	if (BT->left == NULL) {
		BT = BT->right;
		delete temp;
		return true;
	}
	// 待删除元素等于根结点且右子树为空，将左子树作为整个树并返回真
	else if(BT->right == NULL) {
		BT = BT->left;
		delete temp;
		return true;
	}
	// 待删除元素等于树根且左右子树都不为空时
	else {
		// 中序前驱结点就是左孩子结点时，把左孩子结点赋值给树根结点，然后从左子树中删除根节点
		if (BT->left->right == NULL) {
			BT->data = BT->left->data;
			return deleteBSTree(BT->left, BT->left->data);
		}
		// 找出中序前驱结点，既左子树的右下角结点，把该结点赋值给树根节点，然后从以中序前驱结点为根的树上删除根结点
		else {
			BTreeNode *p1 = BT, *p2 = BT->left;
			while (p2->right != NULL) {
				p1 = p2;
				p2 = p2->right;
			}
			BT->data = p2->data;
			return deleteBSTree(p1->right, p2->data);
		}
	}



}


