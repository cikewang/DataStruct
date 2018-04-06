/*
 * test_queueorder.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#include "QueueOrder.h"


int main(void)
{
	Queue q;
	initQueue(q);

	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);

	cout << outQueue(q) << endl;
	cout << outQueue(q) << endl;
	cout << outQueue(q) << endl;
	cout << outQueue(q) << endl;
	enQueue(q, 5);
	enQueue(q, 6);
	cout << outQueue(q) << endl;
	return 0;
}
