/*
----------------------------------------------------
谢蜜雪 学号：1120161761
杨冰琪 学号：1120161762
日期：2019/1/12
实现功能：生成N个四则运算题目和求解题目的主函数入口
---------------------------------------------------
*/


/*
------------------------------------------------------------------------------------
生成运算题目的命令行格式：Arithmetic.exe -p N type
N为生成的题目个数（1<= N <=1000)；
type为题目的类型：A为普通四则运算，B为加入乘方^的四则运算, C为加入乘方**的四则运算

求解运算题目的命令行格式为：Arithmetic_Main.exe -a file_path
file_path为存放题目的文件地址
------------------------------------------------------------------------------------
*/

#pragma once

#include "stdafx.h"
//#include "fraction.h"
#include "PuzzleGenerate.h"
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char * argv[])
{
	double totaltime;
	clock_t start_time, finish_time;
	start_time = clock();

	int N = 0; //题目数量

	if (argc == 4 && strcmp(argv[1], "-p") == 0) //生成运算题目命令
	{
		if (strlen(argv[3]) != 1) //题目类型type长度不合法
		{
			cout << "命令行格式有误！";
			return 0;
		}
		if (argv[3][0] != 'A' && argv[3][0] != 'B' && argv[3][0] != 'C') //题目类型type包含非法字符
		{
			cout << "命令行格式有误！";
			return 0;
		}
		int len = strlen(argv[2]);
		int L = 0;
		while ( L < len)
		{
			if (argv[2][L] < '0' || argv[2][L] > '9') //题目数量N包含非法字符
			{
				cout << "命令行格式有误！";
				return 0;
			}
			N = N * 10 + argv[2][L] - '0';
			L++;
		}
		if (N < 1 || N > 1000) //题目数量N超出范围
		{
			cout << "命令行格式有误！";
			return 0;
		}
		PuzzleGenerate(argv[0], N, argv[3][0]);
	}

	else if (strcmp(argv[1], "-a") == 0) //求解题目命令
	{

	}

	finish_time = clock();
	totaltime = ((double)(finish_time)-(double)start_time) / CLOCKS_PER_SEC;
	cout << "程序的运行时间为" << totaltime << "秒！" << endl;
	return 0;
}
