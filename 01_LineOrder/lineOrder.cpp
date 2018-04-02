#include "lineOrder.h"



/**
 * 初始化线性表
 */
void initList(List &L) {
	// 初始化数组长度为10
	L.maxSize = 10;
	// 动态存储空间分配
	L.list = new ElemType[L.maxSize];
	if (L.list == NULL) {
		cout << "动态可分配的存储空间用完，退出运行" << endl;
		exit(1);
	}
	// 设置线性表长度为 0， 即为空表
	L.size = 0;
}

/**
 * 清空线性表
 */
void clearList(List &L) {
	if (L.list != NULL) {
		delete []L.list;
		L.list = NULL;
	}
	L.maxSize = 0;
	L.size = 0;
}


/**
 * 得到线性表长度
 */
int LengthList(List &L) {
	return L.size;
}

/**
 * 检测列表是否为空
 */
bool checkListIsEmpty(List &L) {
	return L.size == 0;
}

/**
 * 获得线性表中指定序号pos 位置的元素
 */
ElemType getList(List &L, int pos) {
	if (pos<1 || pos>L.size) {
		cerr << "pos is out range" << endl;
		exit(1);
	}

	return L.list[pos-1];
}

/**
 * 遍历链表
 */
void traverseList(List &L) {
	int i;
	for (i=0; i<L.size; i++) {
		cout << L.list[i] << ' ';
	}
	cout << endl;
}

/**
 * 从线性表中查找具有给定元素的第一个元素
 */
bool findList(List &L, ElemType &item) {
	int i;
	for (i =0; i<L.size; i++) {
		if (L.list[i] == item) {
			item = L.list[i];
			return true;
		}
	}
	return false;
}

/**
 * 更新线性表中具有给定值的第一个元素
 */
bool updateList(List &L, const ElemType &item) {
	for (int i=0; i<L.size; i++) {
		if (L.list[i] == item) {
			L.list[i] = item;
			return false;
		}
	}
	return false;
}

/**
 * 向线性表指定位置插入一个元素
 */
bool insertList(List &L, ElemType &item, int pos) {
	if (pos < -1 || pos > L.size+1) {
		cout << "pos 值无效" << endl;
		return false;
	}

	// 求出按值有序插入时 item 的插入位置，使之保持到 pos 中
	int i;
	if (pos == 0) {
		for (i=0; i<L.size; i++) {
			if (item < L.list[i]) {
				break;
			}
		}
		// pos 中保持新插入的元素的序号
		pos = i+1;
	} else if(pos == -1) {
		// 得到表尾插入位置，被保存在 pos 中
		pos = L.size+1;
	}
	// 若线性表存储空间用完，则重新分配大一倍的存储空间
	if (L.size == L.maxSize) {
		// 计算每个元素存储空间的长度
		int k = sizeof(ElemType);
		// 线性表动态存储空间扩展为原来的两倍，原内容不变
		L.list = (ElemType*)realloc(L.list, 2*L.maxSize*k);

		if (L.list == NULL) {
			cout << "动态可分配的存储空间用完，退出执行" << endl;
			exit(1);
		}
		// 把线性表空间大小修改为新的长度
		L.maxSize = 2*L.maxSize;
	}

	// 待插入位置及所有后续位置元素，从后向前一次后移一位
	for (i=L.size-1; i>=pos-1; i--) {
		L.list[i+1] = L.list[i];
	}
	// 把 item 的值赋给已空出的，下标为 pos-1 的位置，它为第 pos 个元素位置
	L.list[pos-1] = item;
	// 线性表长度增1
	L.size++;
	return true;
}

/**
 * 从线性表中删除符合给定条件的第1个元素
 */
bool deleteList(List &L, ElemType &item, int pos) {
	// 检测线性表是否为空，若是则无法删除
	if (L.size == 0) {
		cout << "线性表为空" << endl;
	}
	// 检测  pos 是否有效
	if (pos < -1 || pos > L.size) {
		cout << "pos 值无效" << endl;
		exit(1);
	}
	// 求出按值删除时 item 的删除位置，使之保存到 pos 中
	int i;
	if (pos == 0) {

		for (i=0; i<L.size; i++) {
			if (item == L.list[i]) {
				break;
			}
		}
		// 无元素可以删除
		if (i == L.size) {
			return false;
		}
		pos = i+1;
	} else if(pos == -1) {
		// 得到被表尾元素的序号，被保存在 pos 中
		pos = L.size;
	}
	// 把被删除元素赋值给变量参数 item
	item = L.list[pos-1];
	// 将待删除元素位置后的所有元素，从前向后一次前移一位
	for (i=pos; i<L.size; i++) {
		L.list[i-1] = L.list[i];
	}
	// 线性表长度减1
	L.size--;
	// 若线性表存储空间余太多，则进行适当消减
	if (float(L.size/L.maxSize) < 0.4 && L.maxSize > 10) {
		// 计算每个元素存储空间长度
		int k = sizeof(ElemType);
		// 线性表空间动态存储减少原来的一半
		L.list = (ElemType *)realloc(L.list, L.maxSize*k/2);
		// 把线性表空间大小修改为新的长度
		L.maxSize = L.maxSize/2;
	}

	return true;
}

/**
 * 排序
 */
void sortList(List &L) {
	int i, j;
	ElemType x;
	for (i=1; i<L.size; i++) {
		x = L.list[i];
		for (j=i-1; j>=0; j--) {
			if (x<L.list[j]) {
				L.list[j+1] = L.list[j];
			} else {
				break;
			}
		}
		L.list[j+1] = x;
	}
}
