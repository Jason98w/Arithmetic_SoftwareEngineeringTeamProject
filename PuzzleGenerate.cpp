/*
------------------------
谢蜜雪 学号：1120161761
------------------------
*/
#pragma once

#include "stdafx.h"
#include "fraction.h"
#include "PuzzleGenerate.h"
#include <iostream>
#include <stdio.h>
#include <random>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

char symbols[6][3] = { "+", "-", "*", "/", "^", "**"};
vector <string> puzzle(1000);
//char puzzle[1000][100];
string filepath = "";
ofstream out;

int RandomSymbolGenerate(char type)
{
	int rand_symbol;
	rand_symbol = rand();
	if (type == 'A') //普通模式，运算符只有 +， -, *, / 四种
	{
		rand_symbol = rand_symbol % 4;
	}
	if (type == 'B') //高阶模式1，运算符有 +， -, *, /，^ 五种
	{
		rand_symbol = rand_symbol % 5;
	}
	if (type == 'C') //高阶模式2，运算符有 +， -, *, /，** 五种
	{
		rand_symbol = rand_symbol % 5;
		if (rand_symbol == 4) rand_symbol += 1;
	}
	return rand_symbol;
}

int RandIntegerGeneate()
{
	int number = rand();
	if (number < 0) number = 0;
	return number;
}

fraction& RandFractionGeneate()
{
	int rand_numerator = rand();
	if (rand_numerator < 0) rand_numerator = 0;
	int rand_denominator = rand();
	if (rand_denominator <= 0) rand_denominator = 1; //分母不能为0
	fraction number(rand_numerator, rand_denominator);
	return number;
}
 
void PuzzleGenerate(char* argv, int N, char type)
{
	filepath = argv;
	int l = filepath.length() - 14;
	filepath.erase(l);
	filepath += "puzzle.txt";

	//memset(puzzle,'\0',sizeof(puzzle));
	int i, j, number_type, operator_num, k = 0, L;
	string str;
	fraction frac;
	default_random_engine e;
	uniform_int_distribution<unsigned> u(2, 10);
	for (i = 0; i < N; i++)
	{
		L = 0;
		operator_num = u(e); //随机生成运算符个数（2到10之间）
		number_type = rand() % 2;
		int left_bracket = 0;
		puzzle[k] = "";
		if (number_type == 0) //整数题目
		{
			for (j = 0; j < operator_num; j++)
			{
				puzzle[k] += to_string(RandIntegerGeneate()); //生成随机整数
				str = symbols[RandomSymbolGenerate(type)];
				puzzle[k] += " ";
				puzzle[k] += str;
				puzzle[k] += " ";
			}
			puzzle[k] += to_string(RandIntegerGeneate()); //生成随机整数
		}
		else //分数题目
		{
			for (j = 0; j < operator_num; j++)
			{
				frac = RandFractionGeneate(); //生成随机分数
				puzzle[k] += to_string(frac.GetNumerator());
				puzzle[k] += "/";
				puzzle[k] += to_string(frac.GetDenominator());
				str = symbols[RandomSymbolGenerate(type)];
				puzzle[k] += " ";
				puzzle[k] += str;
				puzzle[k] += " ";
			}
			frac = RandFractionGeneate(); //生成随机分数
			puzzle[k] += to_string(frac.GetNumerator());
			puzzle[k] += "/";
			puzzle[k] += to_string(frac.GetDenominator());
		}
		k++;
	}

	//将题目输出到puzzle.txt文件中
	out.open(filepath, ios::trunc); //清空puzzle.txt的原有内容
	for (i = 0; i < N; i++)
	{
		out << puzzle[i] <<endl;
	}
	out.close();
}
