#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
//array������һ���̶�����,�����Ըı��С����ԭ�е�������������һЩ�ӿ�
void demo2()
{
	array<int, 10>aa;
	aa.fill(100);//���ض�ֵ���aa����
	//��[],at(),�����������Է���
	cout << "�����С" << aa.size() << endl;
	for (array<int, 10>::const_iterator it = aa.begin(); it != aa.end(); it++)
	{
		cout << *it << " ";
	}
	//�ɿ������죬=���������
	//size()��max_size()��ͬ��empty()���÷���ֵһֱΪfalse
	//front()��bakc()���������һ�������һ��������
	aa.front() = 250;
	aa.back() = 999;
	cout << endl;
	for (array<int, 10>::const_iterator it = aa.begin(); it != aa.end(); it++)
	{
		cout << *it << " ";
	}
}
