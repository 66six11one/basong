#include"Card.h"
Card::Card(flower & object1, flower & object2, flower & object3)
{
	a = object1;
	b = object2;
	c = object3;
}
Card::Card(const Card & object)
{
	a = object.a;
	b = object.b;
	c = object.c;
}
void Card::Sort(Card & object)
{
	if (object.a<object.b)
	{
		flower::Swap(object.a, object.b);
	}
	if (object.a<object.c)
	{
		flower::Swap(object.a, object.c);
	}
	if (object.b<object.c)
	{
		flower::Swap(object.b, object.c);

	}
}
bool Card::FC_is_true(Card & object)
{
	if (object.a.show_name()==object.b.show_name()&&object.a.show_name() == object.c.show_name()&&object.b.show_name() == object.c.show_name())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Card::Confirm(Card & object)
{
	//规则是：三张>同花顺>对子（同花）>同花>顺子>对子
	//2 3 4 5 6 7 8 9 10 J Q K A(J10,Q11,K12,A13)
	Sort(object);//对3张牌进行排序
	int max = 0;//3张牌的最大值
	bool yes = false;
	int sum = (object.a.show_value() + object.c.show_value()) / 2;//1和3之和的一半（用于顺子）
	int shuzu[3]{ object.a.show_value(),object.a.show_value(), object.a.show_value() };
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (shuzu[i] < shuzu[j])
			{
				max = shuzu[j];
			}
			if (shuzu[i] == shuzu[j])
			{
				yes = true;
			}
		}
	}
	//一:考虑对象分别是对子还是什么
	if (object.a == object.b&&object.b == object.c&&FC_is_true(object) == false)//豹子
	{
		return 14;
	}
	else if (sum = object.b.show_value() && FC_is_true(object) == true)//同花顺
	{
		return 13;
	}
	else if (yes == true && FC_is_true(object) == true)//对子豹
	{
		return 12;
	}
	else if (FC_is_true(object) == true)//同花
	{
		return 11;
	}
	else if (sum == object.b.show_value() && FC_is_true(object) == false)//顺子
	{
		return 10;
	}
	else if (yes == true && FC_is_true(object) == false)//对子
	{
		return 9;
	}
	else if (max == 13)
	{
		return 8;
	}
	else if (max == 12)
	{
		return 7;
	}
	else if (max == 11)
	{
		return 6;
	}
	else if (max == 10)
	{
		return 5;
	}
	else if (max == 9)
	{
		return 4;
	}
	else if (max == 8)
	{
		return 3;
	}
	else if (max == 7)
	{
		return 2;
	}
	else if (max == 6)
	{
		return 1;
	}
	else if (max == 5)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
string Card::Card_lv(int value)
{
	switch (value)
	{
	case -1:
		return "参数值错误\n";
		break;
	case 0:
		return "当前为5大\n";
		break;
	case 1:
		return "当前为6大\n";
		break;
	case 2:
		return "当前为7大\n";
		break;
	case 3:
		return "当前为8大\n";
		break;
	case 4:
		return "当前为9大\n";
		break;
	case 5:
		return "当前为10大\n";
		break;
	case 6:
		return "当前为J大\n";
		break;
	case 7:
		return "当前为Q大\n";
	case 8:
		return "当前为K大\n";
		break;
	case 9:
		return "当前为A大\n";
	case 10:
		return "当前为对子\n";
		break;
	case 11:
		return "当前为顺子\n";
		break;
	case 12:
		return "当前为同花\n";
		break;
	case 13:
		return "当前为对子豹\n";
		break;
	case 14:
		return "当前为豹子\n";
		break;
	}
}
void Card::Ratio_size(Card & object1, Card & object2)
{
	Sort(object1);
	Sort(object2);
	int ob1[3]{ object1.a.show_value(),object1.b.show_value(),object1.c.show_value() };
	int ob2[3]{ object2.a.show_value(),object2.b.show_value(),object2.c.show_value() };
	int ob1_FV[3]{ object1.a.show_FC_lv(),object1.b.show_FC_lv(),object1.c.show_FC_lv() };
	int ob2_FV[3]{ object2.a.show_FC_lv(),object2.b.show_FC_lv(),object2.c.show_FC_lv() };
	string ob1_name[3]{object1.a.show_name(),object1.b.show_name(), object1.c.show_name()};
	string ob2_name[3]{ object2.a.show_name(),object2.b.show_name(), object2.c.show_name() };
	//一：比较返回值得大小
	int one = object1.Confirm(object1);
	int two = object2.Confirm(object2);
	if (one < two)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << ob2[i]<<" ";
		}
		cout << "大" << endl;
	}
	else if (one == two)//返回值相等
	{
		int i = 0;
		while (i < 3)
		{
			if (ob1[i] > ob2[i])//ob1的最大值大
			{
				string s = object1.Card_lv(object1.Confirm(object1));
				cout << endl;
				cout << s;
				for (int i = 0; i < 3; i++)
				{
					cout << ob1_name[i] << ob1_FV[i] << " ";
				}
				cout << "大" << endl;
				break;
			}
			else if (ob1[i] == ob2[i])
			{
				if (ob1_FV[i] > ob2_FV[i])
				{
					string s = object1.Card_lv(object1.Confirm(object1));
					cout << endl;
					cout << s;
					for (int i = 0; i < 3; i++)
					{
						cout << ob1_name[i] << ob1_FV[i] << " ";
					}
					cout << "大" << endl;
					break;
				}
				else if (ob1_FV[i] < ob2_FV[i])
				{
					string s = object2.Card_lv(object2.Confirm(object2));
					cout << endl;
					cout << s;
					for (int i = 0; i < 3; i++)
					{
						cout << ob1_name[i] << ob1_FV[i] << " ";
					}
					cout << "大" << endl;
					break;
				}
				else
				{
					i++;
				}
			}
			else//ob2的最大值大
			{
				string s = object2.Card_lv(object2.Confirm(object2));
				cout << endl;
				cout << s;
				for (int i = 0; i < 3; i++)
				{
					cout << ob1_name[i] << ob1_FV[i] << " ";
				}
				cout << "大" << endl;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			cout << ob1_name[i] << ob1_FV[i] << " ";
		}
		cout << "大" << endl;
	}

}

