#include<iostream>
#include<string>
using namespace std;
//explicit�Ǳ�ʾ������ʾ�ģ����ܽ�����ʽת��
class Human
{
public:
	explicit Human(int age){ this->age = age; }
	explicit Human(int age, string name){ this->age = age; this->name = name; }
private:
	string name;
	int age;
};