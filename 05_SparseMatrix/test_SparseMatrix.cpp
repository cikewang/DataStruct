/*
 * test_SparseMatrix.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

#include "SparseMatrix.h"

int main(void) {

	SMatrix sm;
	initSMatrix(sm);
	inputSMatrix(sm, 3, 3);
	outputSMatrix(sm);


	CLMatrix clm;
	initCLMatrix(clm);

	return 0;
}



