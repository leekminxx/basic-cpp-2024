#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()  //  �⺻ Ŭ������ ���� �Լ�  ( ���ٰ��� ������ ��üŸ������ �ٲ�) �����ǵǴ� �տ� virtual �پ����� 
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()  // �⺻ Ŭ������ ���� �Լ� ������
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second  // �Ļ� Ŭ���� 2, Second���� ��ӵ�
{
public:  // �⺻ Ŭ������ ���� �Լ� ������
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();  //���� �޸� �Ҵ��� ����Ͽ� �� ��° Ŭ������ ��ü ���� , ���������� ����Ű�� Third��ü  MyFunc ȣ�� virtual �������·� ������ָ� 
	Second* sptr = tptr;   //tptr�� ������ ��ü�� ����Ű�� �⺻ Ŭ������ ���� ������
	First* fptr = sptr;   // tptr �� sptr�� ������ ��ü�� ����Ű�� �⺻ Ŭ������ ���� ������
	// �� �����͸� ����Ͽ� �����ǵ� ���� �Լ� ȣ��
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;  //�޸� ������ �����ϱ� ���� �������� �Ҵ�� ��ü�� �����մϴ�.
	return 0;
}
