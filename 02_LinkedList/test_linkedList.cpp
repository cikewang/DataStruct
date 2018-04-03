#include <iostream>
#include <stdlib.h>
using namespace std;

#include "linkedList.h"

void testLinked();


int main(void)
{
	testLinked();

	return 0;
}

void testLinked() {
	LNode *list;
	initList(list);


	insertList(list, 3, 0);
	insertList(list, 5, 0);
	insertList(list, 2, 2);
	insertList(list, 1, 4);
	insertList(list, 4, 4);
	insertList(list, 6, 4);

	traverseList(list);

	ElemType del_item = 2;
	deleteList(list, del_item, 0);
	cout << "删除元素  ： " << (ElemType)del_item << endl;

	traverseList(list);

	cout << "链表排序 " << endl;
	sortList(list);
	traverseList(list);

	cout << "链表逆序" << endl;
	reversLinked(list);
	traverseList(list);

	cout << "链表递归逆序" << endl;
	LNode *s;
	s = reversLinked2(list);
	traverseList(s);
}

