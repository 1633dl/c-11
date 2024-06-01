#include<iostream>
#include<string>
using namespace std;
//explicit是表示类是显示的，不能进行隐式转换
class Human
{
public:
	explicit Human(int age){ this->age = age; }
	explicit Human(int age, string name){ this->age = age; this->name = name; }
private:
	string name;
	int age;
};