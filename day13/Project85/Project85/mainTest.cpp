#include <iostream>
using namespace std;

void cal(int _n1, int _n2)   // void ���� �Լ������� �ٷ� ����ϰڴ� ��°����� ,�� ������ ���� ��Ģ������ �����ϰ� ����� ����ϴ� �Լ�
{
	if (!_n2) throw _n2;    // �� ��° ������ 0�̸� ���ܸ� �߻���Ŵ
	cout << " +: " << _n1 + _n2 << endl;
	cout << " -: " << _n1 - _n2 << endl;
	cout << " *: " << _n1 * _n2 << endl;
	cout << " /: " << _n1 / _n2 << endl;
}
int main(int argc, int* argv[])
{

	int n1, n2;   
	cout << "���� 2���� �Է��ϼ��� : " << endl;
	cin >> n1;
	cin >> n2;
	try {
		cal(n1, n2);
	}
	catch (int exception) {
		cout << "0���� ���� �� �����ϴ�." << endl;
	}
	return 0;
}
/*
�迭 : �˻� <--> ����

vector
�ڵ����� �޸𸮰� �Ҵ�. templet
*/