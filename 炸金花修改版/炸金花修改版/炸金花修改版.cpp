// 炸金花修改版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"flower.h"
#include"Card.h"
#include <iostream>
const int J = 11;
const int Q = 12;
const int K = 13;
const int A = 14;
using namespace std;
int main()
{
	int shuzu[13]{ 2,3,4,5,6,7,8,9,10,J,Q,K,A };
	string name[4]{ "黑桃","红桃","梅花","方块" };
	int num_storage[10];//存储num
	string name_storage[10];//存储花色名
	//产生随机数,并将相关信息存储到num_storage和name_storage里面
	int i = 0;
	while (i < 6)
	{
		srand(i+6);//种子可修改
		int value_n = rand() % 13;//num
		int value_s = rand() % 4;//name
		cout <<"第"<< i+1<<"次:产生的是" << name[value_s] << shuzu[value_n] << endl;
		name_storage[i] = name[value_s];
		num_storage[i] = shuzu[value_n];
		i++;
	}
	flower a(num_storage[0], name_storage[0]);
	flower b(num_storage[1], name_storage[1]);
	flower c(num_storage[2], name_storage[2]);
	flower d(num_storage[3], name_storage[3]);
	flower e(num_storage[4], name_storage[4]);
	flower f(num_storage[5], name_storage[5]);
	Card g(a, b, c);
	Card h(d, e, f);
	Card::Ratio_size(g, h);
	return 0;
}
