/*
 * main.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#include <iostream>
using namespace std;

#include "Permute.h"
#include "SeekPath.h"
#include "Hanoi.h"


int main(void) {

	// 测试全排列
//	testPermute();

	// 测试迷宫
//	testSeekPath();

	// 汉诺塔
	Hanoi(4, 1, 2, 3);

	return 0;
}
