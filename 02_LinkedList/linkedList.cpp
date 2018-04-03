/*
 * linkedList.cpp
 * 单链表
 *  Created on: 2018年4月2日
 *      Author: libo
 */

#include "linkedList.h"

/**
 * 初始化单链表
 */
void initList(LNode* &HL) {
	HL = NULL;
}

/**
 * 删除单链表中的所有节点，使之成为一个空表
 */
void clearList(LNode* &HL) {
	LNode *cp;
	LNode *np;
	cp = HL;
	while (cp != NULL) {
		np = cp->next;
		delete cp;
		cp = np;
	}
	HL = NULL;
}

/**
 * 获取链表长度
 */
int lengthList(LNode *HL) {
	int i=0;
	while(HL != NULL) {
		i++;
		HL = HL->next;
	}
	return i;
}

/**
 * 检测列表是否为空
 */
bool emptyList(LNode *HL) {
	return HL == NULL;
}

/**
 * 得到单链表第pos个结点的元素
 */

ElemType getList(LNode *HL, int pos) {

	if (pos < 1) {
		cerr << "POS 越界" << endl;
		exit(1);
	}

	int i=0;
	while (HL != NULL) {
		i++;
		if (pos == i) {
			break;
		}
		HL = HL->next;
	}
	if (HL != NULL) {
		return HL->data;
	} else {
		cerr << "POS 位置不存在" << endl;
		exit(1);
	}
}

/**
 * 遍历一个单链表
 */
void traverseList(LNode *HL) {
	cout <<"遍历单链表 ：";
	while (HL != NULL) {
		cout << HL->data << " ";
		HL = HL->next;
	}
	cout << endl;
}


/**
 * 从单链表中查找出等于给定值的第一个元素
 */

bool findList(LNode *HL, ElemType &item) {
	while (HL != NULL) {
		if (HL->data == item) {
			item = HL->data;
			return true;
		} else {
			HL = HL->next;
		}
	}
	return false;
}

/**
 * 更新单链表等于给定值的第一个元素
 */

bool updateList(LNode *HL, const ElemType &item) {

	while (HL != NULL) {
		if (HL->data == item) {
			HL->data = item;
			return false;
		} else {
			HL = HL->next;
		}
	}
	return false;
}

/**
 * 单链表插入一个元素
 */
bool insertList(LNode* &HL, ElemType item, int pos) {
	if (pos < -1) {
		cerr << "pos值无效"<< endl;
		return false;
	}

	// 创建新结点
	LNode *newPtr;
	newPtr = new LNode;
	newPtr->data = item;

	// 初始化前驱结点 ap 为空， cp指向当前结点
	LNode *cp = HL;
	LNode *ap = NULL;

	if (pos == 0) {
		// 没有指定 pos 位置时，新插入结点按顺序插入
		while (cp != NULL) {
			if (item < cp->data) {
					break;
			} else {
				ap = cp;
				cp = cp->next;
			}
		}
	} else if (pos == -1) {
		// 获取表尾的前驱后驱结点
		while (cp != NULL) {
			ap = cp;
			cp = cp->next;
		}
	} else {
		// 获取插入的指定位置前驱和后驱结点
		int i=0;
		while (cp != NULL) {
			i++;
			if (i==pos) {
				break;
			} else {
				ap = cp;
				cp = cp->next;
			}
		}

		if (cp == NULL && (i+1) < pos) {
			cout << "pos 值超出单链表长度加1" << endl;
			return false;
		}
	}

	if (ap == NULL) {
		// 插入表头
		newPtr->next = HL;
		HL = newPtr;
	} else {
		// 插入指定位置
		newPtr->next = cp;
		ap->next = newPtr;
	}

	return true;
}

/**
 * 删除指定位置元素
 */
bool deleteList(LNode* &HL, ElemType &item, int pos) {

	if (HL == NULL) {
		cerr << "单链表为空，删除无效" <<endl;
		return false;
	}

	if (pos < -1) {
		cerr << "pos值无效" <<endl;
		return false;
	}

	LNode *cp = HL;
	LNode *ap = NULL;

	if (pos == 0) {
		while (cp != NULL) {
			if (item == cp->data) {
				break;
			} else {
				ap = cp;
				cp = cp->next;
			}
		}
		if (cp == NULL) {
			cout << "列表中没有可删除的结点" << endl;
			return false;
		}
	} else if (pos == -1) {
		while (cp != NULL) {
			ap = cp;
			cp = cp->next;
		}
	} else {
		int i=0;
		while (cp != NULL) {
			i++;
			if (i == pos) {
				item = cp->data;
				break;
			} else {
				ap = cp;
				cp = cp->next;
			}
		}

		if (cp == NULL) {
			cerr << "pos 值无效" << endl;
			return false;
		}
	}

	if (ap == NULL) {
		// 删除表头结点
		HL = HL->next;
	} else {
		// 删除非表头结点，也可以是表尾结点
		ap->next = cp->next;
	}
	// 回收被删除结点的存储空间
	delete cp;

	return true;
}

/**
 * 排序
 */
void sortList(LNode* &HL) {
	LNode *SL;
	initList(SL);

	LNode *r = HL;
	while (r != NULL) {
		LNode *t = r->next;
		LNode *cp = SL;
		LNode *ap = NULL;
		while (cp != NULL) {
			if (r->data < cp->data) {
				break;
			} else {
				ap = cp;
				cp = cp->next;
			}
		}

		if (ap == NULL) {
			r->next = SL;
			SL = r;
		} else {
			r->next = cp;
			ap->next = r;
		}
		r = t;
	}

	// 有引用参数带回新单链表的比表头指针
	HL = SL;
}

/**
 * 单链表逆序
 * @see https://blog.csdn.net/lycnjupt/article/details/47103433
 */
void reversLinked(LNode* &HL) {

	if (HL == NULL) {
		cout << "链表为空" << endl;
		exit(1);
	}

	LNode *next= NULL;
	LNode *prev = NULL;
	LNode *head = HL;

	while (head != NULL) {
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	HL = prev;
}

/**
 * 递归逆序
 */
LNode *reversLinked2(LNode* HL) {

	LNode *newHead= NULL;

	if (HL == NULL || HL->next == NULL) {
		return HL;
	}

	newHead = reversLinked2(HL->next);
	HL->next->next = HL;
	HL->next = NULL;
	return newHead;
}
