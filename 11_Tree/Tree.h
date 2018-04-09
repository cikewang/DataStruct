/*
 * Tree.h
 *
 *  Created on: 2018年4月9日
 *      Author: libo
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
using namespace std;

typedef char ElemType;

struct BTreeNode {
	ElemType data;
	BTreeNode *left;
	BTreeNode *right;
};

void initBTree(BTreeNode* &BT);
void creatBTree(BTreeNode* &BT, char *a);
bool emptyBTree(BTreeNode *BT);
int depthBTree(BTreeNode *BT);
bool findBTree(BTreeNode *BT, ElemType &x);
void printBTree(BTreeNode *BT);
void clearBTree(BTreeNode* &BT);
void preOrder(BTreeNode *BT);
void inOrder(BTreeNode *BT);
void postOrder(BTreeNode *BT);

#endif /* TREE_H_ */
