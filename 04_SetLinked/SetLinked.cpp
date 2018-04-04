/*
 * SetLinked.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#include "SetLinked.h"

void initSet(SNode* &HT) {
	HT = NULL;
}

void clearSet(SNode* &HT) {
	SNode *p = HT, *q;

	while(p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}

	HT = NULL;
}

int lengthSet(SNode *HT) {
	int n=0;
	while (HT != NULL) {
		n++;
		HT = HT->next;
	}
	return n;
}

bool emptySet(SNode *HT) {
	return HT == NULL;
}

bool inSet(SNode *HT, ElemType item) {
	while(HT != NULL) {
		if (HT->data == item) {
			return true;
		} else {
			HT = HT->next;
		}
	}
	return false;
}

void outputSet(SNode *HT) {
	while (HT != NULL) {
		cout << HT->data << ' ';
		HT = HT->next;
	}
	cout << endl;
}

bool findSet(SNode *HT, ElemType &item) {
	while (HT != NULL) {
		if (HT->data == item) {
			break;
		} else {
			HT = HT->next;
		}
	}

	if (HT != NULL) {
		item = HT->data;
		return true;
	}
	return false;
}


bool modifySet(SNode *HT, const ElemType item) {
	while (HT != NULL) {
		if (HT->data == item) {
			break;
		} else {
			HT = HT->next;
		}
	}

	if (HT != NULL) {
		HT->data = item;
		return true;
	}
	return false;
}

bool insertSet(SNode* &HT, ElemType item) {
	SNode *tp = new SNode;
	tp->data = item;

	SNode *p = HT;
	while (p != NULL) {
		if (p->data == item) {
			break;
		} else {
			p = p->next;
		}
	}

	if (p == NULL) {
		tp->next = HT;
		HT = tp;
		return true;
	}
	return false;
}

bool deleteSet(SNode* &HT, ElemType &item) {

	SNode *cp = HT, *ap = NULL;
	while (cp != NULL) {
		if (cp->data == item) {
			break;
		} else {
			ap = cp;
			cp = cp->next;
		}
	}

	if (cp == NULL) {
		return false;
	}

	item = cp->data;

	if (ap == NULL) {
		HT = cp->next;
	} else {
		ap->next = cp->next;
	}
	delete cp;
	cp = NULL;

	return true;
}

void unionSet(SNode *HT1, SNode *HT2, SNode* &HT) {
	HT = NULL;

	SNode *p = HT1;
	while (p != NULL) {
		SNode *newp = new SNode;
		newp->data = p->data;
		newp->next = HT;
		HT = newp;

		p = p->next;
	}

	p = HT2;
	while (p != NULL) {
		insertSet(HT, p->data);
		p = p->next;
	}
}

void interseSet(SNode *HT1, SNode *HT2, SNode* &HT) {
	HT = NULL;
	ElemType x;

	SNode *p = HT2;
	while (p != NULL) {
		x = p->data;

		bool b = findSet(HT1, x);
		if (b) {
			insertSet(HT, x);
		}
		p = p->next;
	}
}

void differenceSet(SNode *HT1, SNode *HT2, SNode* &HT) {
	HT = NULL;
	ElemType x;

	SNode *p=HT1;
	while (p != NULL) {
		x = p->data;

		if (!findSet(HT2, x)) {
			insertSet(HT, x);
		} else {
			p = p->next;
		}
	}
}

