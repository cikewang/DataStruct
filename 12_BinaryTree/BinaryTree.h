/*
 * BinaryTree.h
 *
 *  Created on: 2018年5月16日
 *      Author: libo
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Tree.h"


bool findBSTree(BTreeNode *BST, ElemType &item);
bool findBSTree1(BTreeNode *BST, ElemType &item);
void createBStree(BTreeNode *&BST, ElemType a[], int n);
void insertBSTree(BTreeNode *&BST, const ElemType &item);
void insertBSTree1(BTreeNode *&BST, const ElemType &item);
void updateBSTree(BTreeNode *&BST, const ElemType &item);
bool deleteBSTree(BTreeNode *&BST, const ElemType &item);

#endif /* BINARYTREE_H_ */
