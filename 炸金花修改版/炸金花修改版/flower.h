#pragma once
#include<iostream>
#include<string>
using namespace std;
class flower
{
public:
	flower() { value = 2; FC_lv = 2; name = "黑桃"; }
	flower(int v, int f, string n);
	flower(int v, string n);
	flower & operator=(const flower & object);//重载=运算符
	friend bool operator>(const flower &, const flower&);//无需加引用
	friend bool operator<(const flower &, const flower&);//无需加引用
	friend bool operator==(const flower &, const flower&);//重载==运算符
	flower(const flower &);//复制构造函数
	friend ostream & operator<<(ostream & os, const flower & f);//重载<<运算符
	int show_value();//获取扑克牌值
	int show_FC_lv();//获取花色等级
	string show_name();
	static void Swap(flower&, flower&);//交换2个flower的值
	~flower() {};
private:
	int value;//扑克牌值
	int FC_lv;//花色等级
	string name;//花色
};