/*
 * SeekPatch.cpp
 *
 *  Created on: 2018年4月6日
 *      Author: libo
 */

#include "SeekPath.h"

// 定义常量 m行 n列
const int m=6, n=8;
// 定义保存迷宫数据的数组
int maze[m+2][n+2];
// 定义保存访问标记的数组
int mark[m+2][n+2];
// 行下标 0,1,2,3, 分别表示东南西北方向 （上北、下南、左西、右东）
int do_move[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};

bool SeekPath(int x, int y) {
	// i 作为循环变量，代表从当前位置移到下一个位置的方向
	int i;

	// g 和 h 用作下一个位置的行坐标和列坐标
	int g, h;

	// 到达出口点返回 true 结束递归
	if ((x == m) && (y == n)) {
		return true;
	}
	for (i=0; i<4; i++) {
		//求出下一个位置的行坐标和列坐标
		g = x + do_move[i][0];
		h = y + do_move[i][1];
		// 若下一个位置可通行同时没有被访问过，则从该位置起寻找
		if ((maze[g][h] == 0) && (mark[g][h]) == 0) {
			// 设置 mark 数组中对应位置为1，表示已经访问过
			mark[g][h] = 1;

			// 当条件成立时，表明从 (g, h) 到终点存在
			// 通路，应输入该位置坐标，同时返回true结束递归
			// 否则进入下一轮循环，向下一个方向试探
			if (SeekPath(g, h)) {
				cout << "(" << g << "," << h << "), ";
				return true;
			} else {
				cout << "^(" << g << "," << h << "), ";
				return false;
			}
		}
	}
	// 从当前位置(x,y)没有通向终点的路径，返回 false
	return false;
}

/**
 * 测试迷宫
 */
void testSeekPath() {
	int i, j;
	srand((unsigned)time(NULL));
	// 初始化迷宫
	for (i=0; i<m+2; i++) {
		for (j=0; j<n+2; j++) {
			if (i==0 || i==m+1 || j==0 || j==n+1) {
				maze[i][j] = 1;
			} else if((i==1 && j==1) || (i==m && j==n)) {
				maze[i][j] = 0;
			} else {
				maze[i][j] = rand() % 2;
			}
			cout << maze[i][j] << " ";

			// 初始化 mark 数组
			mark[i][j] = 0;
		}
		cout << endl;
	}
	cout << endl;

	// 置入口点对应的访问标记为1
	mark[1][1] = 1;


	if (SeekPath(1, 1)) {
		cout << "(1,1) <-- 成功通过" << endl;
	} else {
		cout << "(1,1) <-- 没有通路" << endl;
	}
}



