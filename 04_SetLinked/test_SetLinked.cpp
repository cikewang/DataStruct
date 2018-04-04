/*
 * test_SetLinked.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#include "SetLinked.h"


int main(void) {

	SNode *ht1, *ht2;

	initSet(ht1);
	insertSet(ht1, 1);
	insertSet(ht1, 2);
	insertSet(ht1, 3);
	insertSet(ht1, 4);
	insertSet(ht1, 5);

	outputSet(ht1);


	initSet(ht2);
	insertSet(ht2, 1);
	insertSet(ht2, 2);
	insertSet(ht2, 3);
	insertSet(ht2, 4);
	insertSet(ht2, 5);
	insertSet(ht2, 6);

	outputSet(ht2);

	SNode *ht;
	unionSet(ht1, ht2, ht);
	outputSet(ht);


	interseSet(ht1, ht2, ht);
	outputSet(ht);

	differenceSet(ht1, ht2, ht);
	outputSet(ht);
	return 0;
}


