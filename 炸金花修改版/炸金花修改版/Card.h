#pragma once
#include"flower.h"
class Card
{
public:
	friend class flower;//��flower��ΪCard����Ԫ��
	Card() {}
	Card(flower&, flower&, flower&);
	Card(const Card &);
	static void Sort(Card&);//�Ӵ�С����
	int Confirm(Card&);//��3�����Ƕ���,˳�ӻ���ʲô��confirm��ȷ�ϣ�
	bool FC_is_true(Card&);//��ɫ�Ƿ�һ��
	static void Ratio_size(Card&, Card&);//��̬��Ա����������ֱ���ɣ�����+::+����������
	string Card_lv(int);//���Ժ�Confirm��ϵ������������ȷ�����ƣ�
private:
	flower a;
	flower b;
	flower c;
};