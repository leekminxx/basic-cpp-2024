#include <iostream>
using namespace std;

template <typename T>   //�Ϲ� �߰��� ���� �Լ� ���ø�
T Add(T num1, T num2)
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)  //�� ������ ���ϱ� ���� �����ε�� �Լ�
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)  //�� ���� double�� �߰��ϱ� ���� �����ε�� �Լ�
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)  // ����� ������ �����ݴϴ�.
{
	cout << Add(5, 7) << endl;
	cout << Add(3.7, 7.5) << endl;
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(3.7, 7.5) << endl;
	return 0;
}
