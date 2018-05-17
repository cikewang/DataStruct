/*
 * test_heap.cpp
 *
 *  Created on: 2018年5月17日
 *      Author: libo
 */

#include "Heap.h"

int main(void) {

	int a[8] = {23, 56, 40, 62, 38, 55, 10, 16};

	Heap b;
	initHeap(b);

	int i, x;

	for (i=0; i<8; i++) {
		insertHeap(b, a[i]);
	}

	for (i=0; i<7; i++) {
		cout << b.heap[i] << ", ";
	}

	cout << b.heap[7] << endl;

	while (!emptyHeap(b)) {
		x = deleteHeap(b);
		cout << x;
		if (!emptyHeap(b)) {
			cout << ", ";
		}
	}

	cout << endl;

	clearHeap(b);

	return 0;
}




