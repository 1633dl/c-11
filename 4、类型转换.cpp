#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
//ת���Ĺ�ʽ������ B=���Ͳ����� <����>(A);
//��Aǿת��ΪB������
//���Ͳ�����Ϊstatic_cast,reinterpret_cast,dynamic_cast,const_cast
class Human
{
public:
	Human(){}
	virtual void fun() = 0;
};
class Boy :public Human
{
public:
	Boy(){}
	void fun(){}
};
class Girl :public Human
{
public:
	Girl(){}
	void fun(){}
};

void demo4()
{
	//����ʡ�Բ�д
	//1��static_cast���ھ�̬���͵�ת��(int,char.....)
	//char a = 'c';
	//int b = static_cast<int>(a);
	//2����̬�и���ָ��ָ���������(����ָ�������ת��Ϊ����ָ�������)
	//Boy *b=new Boy();
	//Human*hh = static_cast<Human*>(b);
	//3������ָ��ת��ΪĿ�����͵Ŀ�ָ��
	//int*p = static_cast<int*>(NULL);//����
	//4�����������͵ı��ʽת��Ϊvoid��
	int*p = new int[10];
	void*pp = static_cast<void*>(p);
}
void demo5()
{
	//reinterpret_cast,��������
	//Ҫת����Ŀ�����ͱ���Ϊָ�룬���ã�����ָ��
	//1����ֵ��ָ��֮���ת��
	int*p = reinterpret_cast<int*>(0X183219390);
	int pp = reinterpret_cast<int>(p);
	//2����ͬ����ָ��֮���ת��(����static_cast����reinterpret_cast)
	Human*hh = NULL;
	Boy*bb = reinterpret_cast<Boy*>(hh);
	Girl*gg = reinterpret_cast<Girl*>(hh);
	//������static_castҲ����ʵ��
	bb = reinterpret_cast<Boy*>(gg);//�����ͬ���͵�ָ��Ͳ�����static_cast��ʵ��
}
void demo6()
{
	//dynamic_cast��̬ת��(���ڶ�̬),���Խ����ж�(ָ���Ƿ�Ϊ��)��ǿת�Ƿ�ɹ�
	//�����ָ�뻻Ϊ���ã���ǿתʧ�ܣ��ͻ��׳�bad_cast�Ĵ���
	Human*hh = new Girl();
	hh = new Boy();
	Boy*bb = dynamic_cast<Boy*>(hh);
	if (bb)
	{
		cout << "ǿתb�ɹ�" << endl;
	}
	else{ cout << "ǿתbʧ��" << endl; }
	Girl*gg = dynamic_cast<Girl*>(hh);
	if (gg)
	{
		cout << "ǿתg�ɹ�" << endl;
	}
	else{ cout << "ǿתgʧ��" << endl; }
}
void demo7()
{
	//const_castȥ��const����
	const int*a = new int[10];
	int*b = const_cast<int*>(a);
	for (int i = 0; i < 10; i++)
	{
		b[i] = i;
	}
	const_cast<int*>(a)[0] = 999;
	//�����ַ�������ȥ��const
	const char*p = "ajdiawidwa";
	const_cast<char*>(p)[0] = 'A';
	cout << *p << endl;
}
