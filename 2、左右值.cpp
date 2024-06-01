#include<iostream>
#include<string>
#include<vector>
using namespace std;
//CPU<->内存<->磁盘
//右值存在于CPU的寄存器中，左值存在于内存中
int& demo1()
{
	int i = 100;
	i++;
	return i;
}
/*
int main()
{
//临时变量的引用返回不能作为其他的变量的返回值
int ii = demo1();//可能不会存在错误，因为原来demo1函数在栈上的内存没被释放
//也不能作为左值使用
demo1() = 1000;
//静态变量和全局变量可以运用以上两种情况(静态变量只能被初始化一次)
system("pause");
return 0;
}
*/