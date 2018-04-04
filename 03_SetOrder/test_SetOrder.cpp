/*
 * test_SetOrder.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#include "SetOrder.h"


int main(void) {

	Set s1;
	Set s2;
	Set set;

	initSet(s1);

	insertSet(s1, 1);
	insertSet(s1, 2);
	insertSet(s1, 3);
	insertSet(s1, 4);
	insertSet(s1, 5);

	outputSet(s1);

	initSet(s2);
	insertSet(s2, 6);
	insertSet(s2, 7);
	insertSet(s2, 8);
	insertSet(s2, 9);
	insertSet(s2, 0);

	outputSet(s2);

	initSet(set);
	unionSet(s1, s2, set);

	outputSet(set);


	interseSet(s1, s2, set);
	outputSet(set);


	differenceSet(s1, s2, set);
	outputSet(set);



	return 0;
}


