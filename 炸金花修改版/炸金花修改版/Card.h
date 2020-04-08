#pragma once
#include"flower.h"
class Card
{
public:
	friend class flower;//将flower作为Card的友元类
	Card() {}
	Card(flower&, flower&, flower&);
	Card(const Card &);
	static void Sort(Card&);//从大到小排序
	int Confirm(Card&);//看3张牌是对子,顺子还是什么（confirm：确认）
	bool FC_is_true(Card&);//花色是否一致
	static void Ratio_size(Card&, Card&);//静态成员函数：可以直接由：类名+::+函数名调用
	string Card_lv(int);//可以和Confirm联系起来（作用是确定名称）
private:
	flower a;
	flower b;
	flower c;
};