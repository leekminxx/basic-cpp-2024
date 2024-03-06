#include <iostream>
using namespace std;

class First //�۽�ƮŬ���� ����
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)  //num1 �� num2�� ���� �⺻���� ���� ������
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }  //�����͸� ǥ���ϴ� ��� �Լ�
};

class Second  //Second Ŭ���� ����
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)  //num3 �� num4�� ���� �⺻���� ���� ������
	{  }
	void ShowData() { cout << num3 << ", " << num4 << endl; }  // �����͸� ǥ���ϴ� ��� �Լ�

	Second& operator=(const Second& ref)   //�� ��° Ŭ������ ���� �����ε�� �Ҵ� ������
	{
		cout << "Second& operator=()" << endl;   
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)  //First �� Second Ŭ������ �ν��Ͻ� ����
{
	First fsrc(111, 222);  ////First �� Second Ŭ������ �ν��Ͻ� ����
	First fcpy; 
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;  //�Ҵ� ������ ���
	scpy = ssrc;
	fcpy.ShowData();  //ShowData �Լ��� ����Ͽ� ������ ǥ��
	scpy.ShowData();

	First fob1, fob2;  //First �� Second Ŭ������ �߰� �ν��Ͻ� ����
	Second sob1, sob2;
	fob1 = fob2 = fsrc;  //����� �Ҵ� ������
	sob1 = sob2 = ssrc;

	fob1.ShowData();  //�ν��Ͻ��� ������ ǥ��
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}