#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
//转换的公式：类型 B=类型操作符 <类型>(A);
//将A强转化为B的类型
//类型操作符为static_cast,reinterpret_cast,dynamic_cast,const_cast
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
	//基本省略不写
	//1、static_cast用于静态类型的转换(int,char.....)
	//char a = 'c';
	//int b = static_cast<int>(a);
	//2、多态中父类指针指向子类对象(子类指针或引用转化为父类指针或引用)
	//Boy *b=new Boy();
	//Human*hh = static_cast<Human*>(b);
	//3、将空指针转换为目标类型的空指针
	//int*p = static_cast<int*>(NULL);//不用
	//4、将任意类型的表达式转化为void型
	int*p = new int[10];
	void*pp = static_cast<void*>(p);
}
void demo5()
{
	//reinterpret_cast,尽量不用
	//要转化的目标类型必须为指针，引用，函数指针
	//1、数值和指针之间的转化
	int*p = reinterpret_cast<int*>(0X183219390);
	int pp = reinterpret_cast<int>(p);
	//2、不同类型指针之间的转换(能用static_cast不用reinterpret_cast)
	Human*hh = NULL;
	Boy*bb = reinterpret_cast<Boy*>(hh);
	Girl*gg = reinterpret_cast<Girl*>(hh);
	//这两个static_cast也可以实现
	bb = reinterpret_cast<Boy*>(gg);//这个不同类型的指针就不能用static_cast来实现
}
void demo6()
{
	//dynamic_cast动态转换(用于多态),可以进行判断(指针是否为空)，强转是否成功
	//如果将指针换为引用，若强转失败，就会抛出bad_cast的错误
	Human*hh = new Girl();
	hh = new Boy();
	Boy*bb = dynamic_cast<Boy*>(hh);
	if (bb)
	{
		cout << "强转b成功" << endl;
	}
	else{ cout << "强转b失败" << endl; }
	Girl*gg = dynamic_cast<Girl*>(hh);
	if (gg)
	{
		cout << "强转g成功" << endl;
	}
	else{ cout << "强转g失败" << endl; }
}
void demo7()
{
	//const_cast去除const属性
	const int*a = new int[10];
	int*b = const_cast<int*>(a);
	for (int i = 0; i < 10; i++)
	{
		b[i] = i;
	}
	const_cast<int*>(a)[0] = 999;
	//常量字符串不能去除const
	const char*p = "ajdiawidwa";
	const_cast<char*>(p)[0] = 'A';
	cout << *p << endl;
}
