/*
 * SetOrder.cpp
 *
 *  Created on: 2018年4月4日
 *      Author: libo
 */

#include "SetOrder.h"

/**
 * 初始化集合
 */
void initSet(Set &s) {
	s.maxSize = 10;

	s.set = new ElemType[10];

	if (!s.set) {
		cout << "动态可分配的存空间用完，退出运行" << endl;
		exit(1);
	}

	s.len = 0;
}

/**
 * 清楚集合中所有元素
 */
void clearSet(Set &s) {
	if (s.set != NULL) {
		delete []s.set;
		s.set = NULL;
	}
	s.maxSize = 0;
}

/**
 * 集合长度
 */
int lengthSet(Set &s) {
	return s.len;
}

/**
 * 判断集合是否为空
 */
bool emptySet(Set &s) {
	return s.len == 0;
}

/**
 * 判断一个元素是否在集合中
 */
bool inSet(Set &s, ElemType item) {
	int i;
	for (i=0; i<s.len; i++) {
		if (s.set[i] == item) {
			return true;
		}
	}
	return false;
}

/**
 * 输出集合中所有元素
 */
void outputSet(Set &s) {
	int i;
	for (i=0; i<s.len; i++) {
		cout << s.set[i] << " ";
	}
	cout << endl;
}

/**
 * 从集合中查找一个元素
 */
bool findSet(Set &s, ElemType &item) {
	int i;
	for (i=0; i<s.len; i++) {
		if (s.set[i] == item) {
			break;
		}
	}

	if (i < s.len) {
		item = s.set[i];
		return true;
	}
	return false;
}

/**
 * 修改集合中一个指定元素
 */

bool modifySet(Set &s, const ElemType &item) {
	int i;
	for (i=0; i<s.len; i++) {
		if (s.set[i] == item) {
			break;
		}
	}

	if (i < s.len) {
		s.set[i] = item;
		return true;
	}
	return false;
}

/**
 * 向集合插入一个元素
 */

bool insertSet(Set &s, ElemType item) {
	int i;
	for (i=0; i<s.len; i++) {
		if (s.set[i] == item) {
			return false;
		}
	}

	if (s.len == s.maxSize) {
		int k = sizeof(ElemType);
		// 集合动态存储空间扩展为原来的 2倍，原内容不变
		s.set = (ElemType *)realloc(s.set, 2 * s.maxSize * k);

		if (s.set == NULL) {
			cout << "动态可分配存储空间不足，退出运行" << endl;
			exit(1);
		}
		s.maxSize = 2 * s.maxSize;
	}

	s.set[s.len] = item;
	s.len++;
	return true;
}

/**
 * 从集合中删除一个元素
 */

bool deleteSet(Set &s, ElemType &item) {
	int i;
	for (i=0; i<s.len; i++) {
		if (s.set[i] == item) {
			break;
		}
	}

	if (i < s.len) {
		item = s.set[i];
		// 用最后一个元素填补
		s.set[i] = s.set[s.len-1];
		s.len--;

		if (float(s.len)/s.maxSize < 0.4 && s.maxSize > 10) {
			int k = sizeof(ElemType);
			s.set = (ElemType *)realloc(s.set, k*s.maxSize/2);
			s.maxSize = s.maxSize/2;
		}
		return true;
	}
	return false;
}

/**
 * 求两个集合的并集
 */
void unionSet(Set &s1, Set &s2, Set &s) {
	int i;
	if (s.maxSize < s1.maxSize) {
		delete []s.set;
		s.set = new ElemType[s1.maxSize];
		s.maxSize = s1.maxSize;
	}

	for (i=0; i<s1.len; i++) {
		s.set[i] = s1.set[i];
	}

	s.len = s1.len;
	for (i=0; i<s2.len; i++) {
		insertSet(s, s2.set[i]);
	}
}

/**
 * 求两个集合交集
 */
void interseSet(Set &s1, Set &s2, Set &s) {
	int i;
	ElemType x;
	s.len = 0;
	for (i=0; i<s2.len; i++) {
		x = s2.set[i];
		if (findSet(s1, x)) {
			s.set[s.len] = x;
			s.len++;

			if (s.len == s.maxSize) {
				int k = sizeof(ElemType);
				s.set = (ElemType *)realloc(s.set, 2*k*s.maxSize);
				s.maxSize = 2 * s.maxSize;
			}
		}
	}
}


/**
 * 求两个集合差集
 */
void differenceSet(Set &s1, Set &s2, Set &s) {
	int i;
	ElemType x;
	s.len = 0;
	for (i=0; i<s1.len; i++) {
		x = s2.set[i];
		if (!findSet(s2, x)) {
			s.set[s.len] = x;
			s.len++;

			if (s.len == s.maxSize) {
				int k = sizeof(ElemType);
				s.set = (ElemType *)realloc(s.set, 2 * k * s.maxSize);
				s.maxSize = 2 * s.maxSize;
			}
		}
	}
}













