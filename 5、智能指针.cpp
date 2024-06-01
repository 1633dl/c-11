#include<iostream>
#include<string>
#include<vector>
#include<memory>//����ָ��ͷ�ļ�
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
//auoto_ptrָ��,���ܶ���Ϊȫ�ֱ�������һ��ָ��(������)
//��Ҫ������ָ�븳ֵ����һ������ָ��(auto_ptr�൱�ڵ���reset()����ֵ��ָ��ʧȥ����Ȩ)
void demo8()
{
	auto_ptr<int>aa(new int[10]);//���������ָ����������ڽ����󣬵������������ͷ��ڴ�
	auto_ptr<Person>pp(new Person());
	pp->get_();//����ָ��ָ�����ĳ�Ա����
	Person*temp=pp.release();//release�Ὣ����ָ��ȡ���йܣ�ָ����ڴ���Ҫ�Լ����ͷ�
	delete temp;
	//reset()�ܽ�����ָ�����ã����ݴ���Ĳ����Աȣ�����ַ��ͬ�����ͷ�ԭ�����ڴ棬�ӹܴ���Ĳ���
	pp.reset();
	pp.reset(new Person());

	//��������1�����ܽ�ͬһ���ڴ潻����������ָ��
	{
		string* name = new string("casoiasmoa");
		auto_ptr<string>a1(name);
		{
			//����a2���������ں�ͻ������ڴ��ͷŵ���a1��ʧЧ��
			auto_ptr<string>a2(name);
		}
	}
	auto_ptr<string>a1(new string("faoifja"));
	auto_ptr<string>a2(new string("faoifsfsfja"));
	//����2��STL�����в���ʹ��auto_ptr����ΪSTL������Ҫ��ֵ�͸���
	vector<auto_ptr<string>>vv;
	vv.emplace_back(a1);
	vv.emplace_back(a2);
	vv[1] = vv[0];//���ܽ���Σ�յ�ָ�븳ֵ
	//����3����֧������
}
//unique_ptr ��ֹ����ֵ��ֵ�͹���
void demo9()
{
	unique_ptr<string>u1(new string("dwodawd"));
	unique_ptr<string>u2(new string("dpppppppd"));
	//u1 = u2;//��ֹ������ʹ��move
	//unique_ptr����֧������
	unique_ptr<int[]>u3(new int[10]);
	u3[0] = 999;
	//����ʹ���Զ����ɾ����(�º���)���ͷ�unique_ptrָ����ڴ�,������
	unique_ptr<Person, DELETE_MESSAGE>u4(new Person());
	//unique_ptr���������ͷ��ڴ�
	u1 = NULL;//u1.reset();
	//ͨ��reserve()ת���ڴ����Ȩ��ֻ���unique_ptr��ָ����Ϊ��,��auto_ptr��ͬ
}
//shared_ptr ��װ��һ����¼ָ�������ı��������������Ϊ0ʱ�Ͳ��ͷ��ڴ�,�����������ڻ��ͷ�
//����shared_ptr���Ա�֤���ָ��ָ��һ���ڴ�(ָ������໥��ֵ)
void demo10()
{
	shared_ptr<Person>s1(new Person());
	shared_ptr<Person>s2 = s1;//��ֵ��ͬ��unique_ptr���൱����������ָ��ָ��ͬһ���ڴ�
	//��������Լ���ɾ����(�º���)
	//shared_ptr<Person>s2(new Person(), DELETE_MESSAGE());
	int a=s1.use_count();//��ǰ�ܿ�s1ָ���ڴ������ָ�������
	cout << a << endl;
	//ͨ��make_shared����ʼ��shared_ptr(��Ϊ��Ҫ)
	shared_ptr<Person>s3 = make_shared<Person>("����",100);
	//���������ڴ����Ȩ
	s1 = NULL;
	Person*person = new Person("����", 100);
	s2.reset(person);//����reset()��ʹ����ָ�����ԭ���ڴ�Ĺ���Ȩ,ָ����ָ��ָ����ڴ�
	//ע�⣺reset()����Ĳ�����������ָͨ�룬��������ָ��
	//ͨ��reset����ԭ���ڴ�Ĺ���ʱ��������-1

	//swap()���Խ���������ָ��ָ��ı�
}
//shared_ptr������
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
	//������ָ��ֱ�ֵ����������ĳ�Ա����
	//����������������ڿ��ٵ��ڴ汻��������ĳ�Ա��������,���Բ���ֱ���ͷ�
	bs->g_friend = gs;
	gs->b_friend = bs;
}
//��ָ��weak_ptr���shared_ptrʹ�ã����ܷ����ڴ��е�����
void demo11()
{
	weak_ptr<Person>w1;
	shared_ptr<Person>s1(new Person());
	weak_ptr<Person>w2(s1);//���Խ�shared_ptr��ֵ�򿽱������weak_ptr
	w1 = s1;//����weak_ptrֻ�Ǹ�һ����¼,��������shared_ptr�ļ�¼����
	//���Խ�weak_ptrת��Ϊshared_ptr
	s1 = w2.lock();
	//��Ϊweak_ptr��������shared_ptr�ļ�¼���������Բ������shared_ptrѭ��ָ�������
	//��Ҫ�����ڴ�ʱ��weak_ptr���Ե���lock()��Ϊshared_ptr������
}
int main()
{
	system("pause");
	return 0;
}