#include <iostream>
using namespace std;
// �Լ� ���ø� Max�� ������ ���� T�� �� �� ���� ���ϰ� �� �� �ִ밪�� ��ȯ�մϴ�.
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;   // ������ �Բ� Max ���: 11 �� 15
	cout << Max('T', 'Q') << endl;  // ���� 'T' �� 'Q'�� �Բ� Max ��� , ���ĺ������� ���� 
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;
	return 0;
}
