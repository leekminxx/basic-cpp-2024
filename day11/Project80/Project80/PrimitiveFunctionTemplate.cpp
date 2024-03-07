#include <iostream>
using namespace std;
// �Լ� ���ø� ShowData�� �� ���� ���� �Ű����� T1�� T2�� ����ϰ� T1�� T2�� ĳ���õ� �Է� ���� ǥ���մϴ�.
template <class T1, class T2>  
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)  // �پ��� ���ø� �μ��� �Է� ���� ����Ͽ� ShowData �Լ��� ������ �����ݴϴ�.
{
	ShowData<char, int>(65); // ShowData<char, int> - char �� int�� ĳ���õ� �Է� ��(65)�� ǥ���մϴ�.
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);  // ShowData<char, double> - Displaying the input value (68.9) casted to char and double.
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}
