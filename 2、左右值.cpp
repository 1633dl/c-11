#include<iostream>
#include<string>
#include<vector>
using namespace std;
//CPU<->�ڴ�<->����
//��ֵ������CPU�ļĴ����У���ֵ�������ڴ���
int& demo1()
{
	int i = 100;
	i++;
	return i;
}
/*
int main()
{
//��ʱ���������÷��ز�����Ϊ�����ı����ķ���ֵ
int ii = demo1();//���ܲ�����ڴ�����Ϊԭ��demo1������ջ�ϵ��ڴ�û���ͷ�
//Ҳ������Ϊ��ֵʹ��
demo1() = 1000;
//��̬������ȫ�ֱ����������������������(��̬����ֻ�ܱ���ʼ��һ��)
system("pause");
return 0;
}
*/