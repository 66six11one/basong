#include"flower.h"
flower::flower(int v, int f, string s)//���캯��
{
	FC_lv = f;
	name = s;
	value = v;
}
flower::flower(int v, string s)
{
	value = v;
	FC_lv = v;
	name = s;
}
flower & flower::operator=(const flower & object)//����=�����
{
	if (this == &object)
	{
		return *this;
	}
	value = object.value;
	FC_lv = object.FC_lv;
	name = object.name;
	return *this;
}
flower::flower(const flower & object)//���ƹ��캯��
{
	value = object.value;
	FC_lv = object.FC_lv;
	name = object.name;
}
bool operator<(const flower & object1, const flower & object2)
{
	if (object1.value < object2.value)//�˿���ֵ��ľʹ�
	{
		return true;
	}
	else if (object1.value == object2.value&&object1.FC_lv < object2.FC_lv)//���˿���ֵ��ͬʱ����ɫ�ȼ���Ĵ�
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>(const flower & object1, const flower & object2)
{
	if (object1.value > object2.value)
	{
		return true;
	}
	else if (object1.value == object2.value&&object1.FC_lv > object2.FC_lv)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator==(const flower & object1, const flower & object2)
{
	return object1.value == object2.value;
}
ostream & operator<<(ostream & os, const flower & f)
{
	os << "��ǰ��:" << f.name << f.value << endl;
	return os;
}
int flower::show_value()
{
	return value;
}
int flower::show_FC_lv()
{
	return FC_lv;
}
string flower::show_name()
{
	return name;
}
void flower::Swap(flower & object1, flower & object2)
{
	flower f = object1;
	object1 = object2;
	object2 = f;
}
