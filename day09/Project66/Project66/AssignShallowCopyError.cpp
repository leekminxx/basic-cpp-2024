#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)  //�̸��� ���̿� ���� �Ű������� �ִ� ������
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	/*
	Person& Person::operator=(const Person& ref)  //���� �Ҵ� ������
	{
		delete []name;

		int len=strlen(ref.name)+1;  //��ü �Ҵ� Ȯ��
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}
	*/

	void ShowPersonInfo() const  //���� ������ ǥ���ϴ� ��� �Լ�
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person()  //�Ҵ�� �޸𸮸� �����ϴ� �Ҹ���
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);  //Person Ŭ������ �ν��Ͻ� �����
	Person man2("Yoon ji yul", 22);
	man2 = man1;   //���� �Ҵ� ������ ���
	man1.ShowPersonInfo();  //�� �ν��Ͻ� ��ο� ���� ���� ǥ��
	man2.ShowPersonInfo();
	return 0;
}