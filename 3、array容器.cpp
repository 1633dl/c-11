#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;
//array数组是一个固定数组,不可以改变大小，在原有的数组上增添了一些接口
void demo2()
{
	array<int, 10>aa;
	aa.fill(100);//用特定值填充aa容器
	//用[],at(),迭代器都可以访问
	cout << "数组大小" << aa.size() << endl;
	for (array<int, 10>::const_iterator it = aa.begin(); it != aa.end(); it++)
	{
		cout << *it << " ";
	}
	//可拷贝构造，=运算符重载
	//size()于max_size()等同，empty()无用返回值一直为false
	//front()和bakc()返回数组第一个和最后一个的引用
	aa.front() = 250;
	aa.back() = 999;
	cout << endl;
	for (array<int, 10>::const_iterator it = aa.begin(); it != aa.end(); it++)
	{
		cout << *it << " ";
	}
}
