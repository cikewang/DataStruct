#include <iostream>
#include <stdlib.h>
using namespace std;

#include "linkedList.h"

int main(void)
{
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

	return 0;
}
