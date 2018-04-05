/*
 * SparseMatrix.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#include "SparseMatrix.h"


void initSMatrix(SMatrix &M) {
	M.m = 0;
	M.n = 0;
	M.t = 0;
}

void initLMatrix(LMatrix &M) {
	M.m = 0;
	M.n = 0;
	M.t = 0;
	for (int i=1; i<=MaxRows; i++) {
		M.vector[i] = NULL;
	}
}

void initCLMatrix(CLMatrix &M) {
	M.m = 0;
	M.n = 0;
	M.t = 0;
	for (int i=1; i<=MaxRows; i++) {
		M.rv[i] = NULL;
	}
	for (int i=1; i<=MaxColumns; i++) {
		M.cv[i] = NULL;
	}
}


/**
 * 稀疏矩阵 顺序结构输入
 */
void inputSMatrix(SMatrix &M, int m, int n) {
	M.m = m;
	M.n = n;
	int row, col, val;
	int k = 0;
	cin>>row>>col>>val;

	while (row != 0) {
		M.sm[k].row = row;
		M.sm[k].col = col;
		M.sm[k].val = val;
		k++;
		cin>>row>>col>>val;
	}
	M.t = k;
}

/**
 * 十字链接存储
 */
void inputCLMatrix(CLMatrix &M, int m, int n) {
	M.m = m;
	M.n = n;
	int row, col, val;
	int k = 0;
	cin>>row>>col>>val;
	while (row != 0) {
		k++;
		CrossNode *cp, *newptr;
		// 建立一个新结点
		newptr = new CrossNode;
		newptr->row = row;
		newptr->col = col;
		newptr->val = val;
		newptr->down = newptr->right = NULL;
		// 把新结点链接到所在行单链表的末尾
		cp = M.rv[row];
		if (cp == NULL) {
			M.rv[row] = newptr;
		} else {
			while (cp->right != NULL) {
				cp = cp->right;
			}
			cp->right = newptr;
		}
		// 把新结点链接到所在列单链表的末尾
		cp = M.cv[col];
		if (cp == NULL) {
			M.cv[col] = newptr;
		} else {
			while (cp->down != NULL) {
				cp = cp->down;
			}
			cp->down = newptr;
		}
		// 输入一个三元组
		cin>>row>>col>>val;
	}
	M.t = k;
}

/**
 * 输出顺序存储矩阵
 */
void outputSMatrix(SMatrix &M) {
	cout << "(";
	for (int i=0; i<M.t; i++) {
		cout << "(" << M.sm[i].row << ", ";
		cout << M.sm[i].col << ", ";
		cout << M.sm[i].val << ") ";
	}

	cout << ")" << endl;;
}

/**
 * 转置  算法复杂度 O(nxt)
 */
SMatrix transpose(SMatrix &M) {
	SMatrix S;
	initSMatrix(S);
	int m, n, t;
	m = M.m;
	n = M.n;
	t = M.t;
	S.m = n;
	S.n = m;
	S.t = t;

	if (t == 0) {
		return S;
	}

	int k = 1;
	// 用 col 扫描  M.sm 数组中的 col 域
	for (int col=1; col<=n; col++ ) {
		// 用 i 指示 M.sm 数组中当前元素下标
		for (int i=1; i<=t; i++) {
			if (M.sm[i].col == col) {
				S.sm[i].row = col;
				S.sm[i].col = M.sm[i].row;
				S.sm[k].val = M.sm[i].val;
				k++;
			}
		}
	}

	return S;
}


/**
 * 快速转置
 */

SMatrix fastTranspose(SMatrix &M) {
	SMatrix S;
	initSMatrix(S);
	int m, n, t;

	m = M.m;
	n = M.n;
	t = M.t;

	S.m = M.n;
	S.n = M.m;
	S.t = M.t;

	if (t == 0) {
		return S;
	}
	// 为 num 和 pot 向量动态分配存储空间
	int *num = new int[n+1];
	int *pot = new int[n+1];
	// 对 num 向量进行初始化，置每个分量为0
	int col, i;
	for (col=1; col<=n; col++) {
		num[col] = 0;
	}
	// 第一遍扫描数组 M.sm，统计出每一列（既转置后的每一行）非零元素的个数
	for (i=1; i<=t; i++) {
		int j=M.sm[i].col;
		num[j]++;
	}
	// 计算每一列（既转置后每一行）的第1个非零元素在 S.sm 中的位置
	pot[1] = 1;
	for (col=2; col<=n; col++) {
		pot[col] = pot[col-1] + num[col-1];
	}
	// 对 M.sm 进行第二遍扫描，把每个元素行、列互换写入到 S.sm 的确定位置
	for (i=1; i<=t; i++) {
		// 取带转换元素的列好
		int j = M.sm[i].col;
		// 取待转换元素在 S.sm 中的位置
		int k = pot[j];
		// 转换元素
		S.sm[k].row = j;
		S.sm[k].col = M.sm[i].row;
		S.sm[k].val = M.sm[i].val;
		// 使 pot[j] 指向下一个位置
		pot[j]++;
	}
	// 删除动态分配的数组
	delete []num;
	delete []pot;


	return S;

}




