#pragma once
#include<iostream>
#include<string>
using namespace std;
class flower
{
public:
	flower() { value = 2; FC_lv = 2; name = "����"; }
	flower(int v, int f, string n);
	flower(int v, string n);
	flower & operator=(const flower & object);//����=�����
	friend bool operator>(const flower &, const flower&);//���������
	friend bool operator<(const flower &, const flower&);//���������
	friend bool operator==(const flower &, const flower&);//����==�����
	flower(const flower &);//���ƹ��캯��
	friend ostream & operator<<(ostream & os, const flower & f);//����<<�����
	int show_value();//��ȡ�˿���ֵ
	int show_FC_lv();//��ȡ��ɫ�ȼ�
	string show_name();
	static void Swap(flower&, flower&);//����2��flower��ֵ
	~flower() {};
private:
	int value;//�˿���ֵ
	int FC_lv;//��ɫ�ȼ�
	string name;//��ɫ
};