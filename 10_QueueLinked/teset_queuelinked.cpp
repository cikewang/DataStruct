/*
 * teset_queuelinked.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#include "QueueLinked.h"

int main(void)
{
	LinkQueue q;
	initQueue(q);

	int a[9] = {1,2,3,4,5,6,7,8,9};

	for (int i=0; i<9; i++) {
		enQueue(q, a[i]);
	}

	cout << outQueue(q) << endl;
	cout << outQueue(q) << endl;
	cout << outQueue(q) << endl;

	cout << peekQueue(q) << endl;

	if (emptyQueue(q)) {
		cout << "空队列" << endl;
	} else {
		cout << "非空队列" << endl;
	}

	clearQueue(q);


	if (emptyQueue(q)) {
		cout << "空队列" << endl;
	} else {
		cout << "非空队列" << endl;
	}

	return 0;
}


