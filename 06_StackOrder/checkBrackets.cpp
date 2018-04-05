/*
 * checkBrackets.cpp
 *
 *  Created on: 2018年4月5日
 *      Author: libo
 */

/**
 * 检测程序中大括号、方括号、圆括号是否配对
 */
#include "checkBrackets.h"

int bracketsCheck(char* fname) {
	ifstream ifstr(fname, ios::in);

	if (!ifstr) {
		cerr << "文件不存在" << endl;
		exit(1);
	}

	Stack a;
	initStack(a);

	char ch;

	while (ifstr>>ch) {

		if (ch == 39) {
			// 单引号内的字符不参与配对比较
			while (ifstr>>ch) {
				if (ch == 39) {
					break;
				}
			}
			if (!ifstr) {
				return 0;
			}
		} else if (ch == 34) {
			// 双引号内的字符不参与配对比较
			while (ifstr>>ch) {
				if (ch == 34) {
					break;
				}
			}

			if (!ifstr) {
				return 0;
			}
		}
		cout << ch;
		switch (ch) {
			case '{':
			case '[':
			case '(':
				push(a, ch);
				break;
			case '}':
				if (peek(a) == '{') {
					pop(a);
				} else {
					return 0;
				}
				break;
			case ']':
				if (peek(a) == '[') {
					pop(a);
				} else {
					return 0;
				}
				break;
			case ')':
				if (peek(a) == '(') {
					pop(a);
				} else {
					return 0;
				}
				break;
		}
	}

	if (emptyStack(a)) {
		return 1;
	} else {
		return 0;
	}

}



