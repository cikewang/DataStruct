/*
 * SparseMatrix.h
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#ifndef SPARSEMATRIX_H_
#define SPARSEMATRIX_H_

#include <iostream>
using namespace std;

typedef int ElemType;
const int MaxTerms = 10;
const int MaxRows = 10;
const int MaxColumns = 10;

/**
 * 顺序存储结构
 */
struct Triple {
	int row, col;
	ElemType val;
};

struct SMatrix {
	int m, n, t;
	Triple sm[MaxTerms];
};

/**
 * 带行指针向量的链接存储
 */
struct TripleNode {
	int row, col;
	ElemType val;
	TripleNode *next;
};

struct LMatrix {
	int m, n, t;
	TripleNode *vector[MaxRows];
};

/**
 * 十字连接存储
 */
struct CrossNode {
	int row, col;
	ElemType val;
	CrossNode *down, *right;
};

struct CLMatrix {
	int m, n, t;
	CrossNode *rv[MaxRows];
	CrossNode *cv[MaxColumns];
};

void initSMatrix(SMatrix &M);
void initLMatrix(LMatrix &M);
void initCLMatrix(CLMatrix &M);
void inputSMatrix(SMatrix &M, int m, int n);
void inputCLMatrix(CLMatrix &M, int m, int n);
void outputSMatrix(SMatrix &M);
SMatrix transpose(SMatrix &M);
SMatrix fastTranspose(SMatrix &M);

#endif /* SPARSEMATRIX_H_ */
