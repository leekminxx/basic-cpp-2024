#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() // �⺻ Ŭ������ ��� �Լ�
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc()  // �⺻ Ŭ������ ��� �Լ�
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc()  //�⺻ Ŭ������ ���� �Լ� ������
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() //�⺻ Ŭ������ ���� �Լ� ������
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void)
{
	Third obj;  // �� ��° Ŭ������ ��ü ����
	obj.FirstFunc();  //���: FirstFunc()
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
	return 0;
}