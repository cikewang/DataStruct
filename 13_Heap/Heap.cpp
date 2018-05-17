/*
 * Heap.cpp
 *
 *  Created on: 2018年5月17日
 *      Author: libo
 */

#include "Heap.h"

/**
 * 初始化
 */
void initHeap(Heap &HBT) {
	// 初始化定义数组长度为10，以后可增减
	HBT.maxSize = 10;
	// 动态分配存储堆的数组空间
	HBT.heap = new ElemType[HBT.maxSize];

	if (!HBT.heap) {
		cout << "用户动态分配的内存空间用完，退出运行！" << endl;
		exit(1);
	}
	// 设置len域的初值0
	HBT.len = 0;
}

/**
 * 清除堆
 */
void clearHeap(Heap &HBT) {
	if (HBT.heap != NULL) {
		delete[] HBT.heap;
		HBT.heap = NULL;
		HBT.len = 0;
		HBT.maxSize = 0;
	}
}


/**
 * 检测堆是否为空
 */
bool emptyHeap(Heap &HBT) {
	return HBT.len == 0;
}


/**
 * 插入堆
 */
void insertHeap(Heap &HBT, ElemType item) {

	// 堆满时重新分配大一倍的存储空间并进行相应操作
	if (HBT.len == HBT.maxSize) {
		// 计算每个元素存储空间长度
		int k = sizeof(ElemType);
		// 动态分配存储空间扩展为原来的2倍，原内容保存不变
		HBT.heap = (ElemType *)realloc(HBT.heap, 2*HBT.maxSize*k);
		if (HBT.heap == NULL) {
			cout << "动态可分配的存储空间用完，退出运行！" << endl;
			exit(1);
		}
		// 把堆空间大小修改为新的长度
		HBT.maxSize *=2;
	}

	// 用 i 指向待调整元素的位置，初始指向新元素所在的堆尾位置
	int i = HBT.len;
	// 寻找新元素的最终位置，每次使双亲元素下移一层
	while (i!=0) {
		// j 指向下标为 i 的元素的双亲元素
		int j = (i-1)/2;
		// 比较调整结束退出循环
		if (item >= HBT.heap[i]) {
			break;
		}
		// 改变调整元素的位置为其双亲位置
		HBT.heap[i] = HBT.heap[j];
		i=j;
	}

	// 把新元素调整到最终位置，并使堆的长度增1
	HBT.heap[i] = item;
	HBT.len++;
}

/**
 * 从小根堆 HBT 中删除堆顶元素并返回
 */
ElemType deleteHeap(Heap &HBT) {
	// 若为空堆，则显示出错错误信息并退出运行
	if (HBT.len == 0) {
		cout << "堆为空，退出运行" << endl;
		exit(1);
	}

	// 将堆顶元素暂存在 temp 以便返回
	ElemType temp = HBT.heap[0];
	// 推长度减1
	HBT.len--;
	// 若删除后边为空堆则返回
	if (HBT.len == 0) {
		return temp;
	}
	// 将待调整的堆尾元素暂存 x 中
	ElemType x = HBT.heap[HBT.len];
	// 用i 指向调整元素的位置，初始化指向堆顶位置
	int i = 0;
	// 将 j 指向 i的左孩子位置，初始指向下标1的位置
	int j = 1;
	// 寻找待调整元素的最终位置
	while (j <= HBT.len-1) {
		// 若右孩子存在并且较小，应使 j 指向右孩子
		if (j < HBT.len-1 && HBT.heap[j] > HBT.heap[j+1]) {
			j++;
		}
		// 若条件成立则调整结束，退出循环
		if (x <= HBT.heap[j]) {
			break;
		}
		// 孩子元素上移到双亲结点
		HBT.heap[i] = HBT.heap[j];
		// 使 i 和  j 分别指向下一层结点
		i = j;
		j = 2*i+1;

	}
	// 把待调整元素放到最终位置
	HBT.heap[i] = x;
	// 返回原堆顶元素
	return temp;
}
