#include<iostream>
#include<string>
#include<vector>
#include<memory>//智能指针头文件
using namespace std;
class Person
{
public:
	Person(){}
	Person(string name, int age){ this->name = name; this->age = age; }
	~Person(){cout << "mcaosmc"<<endl;}
	int get_(){ return 999; }
	string name;
	int age;
};
class DELETE_MESSAGE
{
public:
	void operator()(Person*pp)
	{
		pp->get_();
		delete pp;
	}
};
//auoto_ptr指针,不能定义为全局变量或者一个指针(无意义)
//不要把智能指针赋值给另一个智能指针(auto_ptr相当于调用reset()，赋值的指针失去管理权)
void demo8()
{
	auto_ptr<int>aa(new int[10]);//当这个智能指针的生命周期结束后，调用析构函数释放内存
	auto_ptr<Person>pp(new Person());
	pp->get_();//调用指针指向对象的成员函数
	Person*temp=pp.release();//release会将智能指针取消托管，指向的内存需要自己来释放
	delete temp;
	//reset()能将智能指针重置，根据传入的参数对比，若地址不同，就释放原来的内存，接管传入的参数
	pp.reset();
	pp.reset(new Person());

	//存在问题1：不能将同一块内存交给两个智能指针
	{
		string* name = new string("casoiasmoa");
		auto_ptr<string>a1(name);
		{
			//过了a2的生命周期后就会把这段内存释放掉，a1就失效了
			auto_ptr<string>a2(name);
		}
	}
	auto_ptr<string>a1(new string("faoifja"));
	auto_ptr<string>a2(new string("faoifsfsfja"));
	//问题2：STL容器中不能使用auto_ptr，因为STL容器中要求赋值和复制
	vector<auto_ptr<string>>vv;
	vv.emplace_back(a1);
	vv.emplace_back(a2);
	vv[1] = vv[0];//不能进行危险的指针赋值
	//问题3：不支持数组
}
//unique_ptr 禁止了左值赋值和构造
void demo9()
{
	unique_ptr<string>u1(new string("dwodawd"));
	unique_ptr<string>u2(new string("dpppppppd"));
	//u1 = u2;//禁止，可以使用move
	//unique_ptr可以支持数组
	unique_ptr<int[]>u3(new int[10]);
	u3[0] = 999;
	//可以使用自定义的删除器(仿函数)来释放unique_ptr指向的内存,不常用
	unique_ptr<Person, DELETE_MESSAGE>u4(new Person());
	//unique_ptr可以主动释放内存
	u1 = NULL;//u1.reset();
	//通过reserve()转让内存管理权，只会把unique_ptr的指向置为空,和auto_ptr相同
}
//shared_ptr 包装了一个记录指针数量的变量，当这个计数为0时就才释放内存,出了生命周期会释放
//所以shared_ptr可以保证多个指针指向一块内存(指针可以相互赋值)
void demo10()
{
	shared_ptr<Person>s1(new Person());
	shared_ptr<Person>s2 = s1;//赋值不同于unique_ptr，相当于两个智能指针指向同一块内存
	//可以添加自己的删除器(仿函数)
	//shared_ptr<Person>s2(new Person(), DELETE_MESSAGE());
	int a=s1.use_count();//当前管控s1指向内存的智能指针的数量
	cout << a << endl;
	//通过make_shared来初始化shared_ptr(较为重要)
	shared_ptr<Person>s3 = make_shared<Person>("张三",100);
	//主动放弃内存管理权
	s1 = NULL;
	Person*person = new Person("张三", 100);
	s2.reset(person);//调用reset()会使智能指针放弃原来内存的管理权,指向传入指针指向的内存
	//注意：reset()传入的参数必须是普通指针，不是智能指针
	//通过reset放弃原来内存的管理时，计数会-1

	//swap()可以将两个智能指针指向改变
}
//shared_ptr的问题
class Girl;
class Boy;
class Boy
{
public:
	shared_ptr<Girl>g_friend;
};
class Girl
{
public:
	shared_ptr<Boy>b_friend;
};
void question1()
{
	shared_ptr<Boy>bs = make_shared<Boy>(new Boy);
	shared_ptr<Girl>gs = make_shared<Girl>(new Girl);
	//将两个指针分别赋值给两个对象的成员变量
	//这个函数结束后，由于开辟的内存被两个对象的成员变量保存,所以不会直接释放
	bs->g_friend = gs;
	gs->b_friend = bs;
}
//弱指针weak_ptr配合shared_ptr使用，不能访问内存中的内容
void demo11()
{
	weak_ptr<Person>w1;
	shared_ptr<Person>s1(new Person());
	weak_ptr<Person>w2(s1);//可以将shared_ptr赋值或拷贝构造给weak_ptr
	w1 = s1;//但是weak_ptr只是给一个记录,不会增加shared_ptr的记录次数
	//可以将weak_ptr转化为shared_ptr
	s1 = w2.lock();
	//因为weak_ptr不会增加shared_ptr的记录次数，所以不会出现shared_ptr循环指向的问题
	//需要访问内存时，weak_ptr可以调用lock()变为shared_ptr来访问
}
int main()
{
	system("pause");
	return 0;
}