#include <iostream>
using namespace std;

template <typename T>   //일반 추가를 위한 함수 템플릿
T Add(T num1, T num2)
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)  //두 정수를 더하기 위한 오버로드된 함수
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)  //두 개의 double을 추가하기 위한 오버로드된 함수
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)  // 기능의 사용법을 보여줍니다.
{
	cout << Add(5, 7) << endl;
	cout << Add(3.7, 7.5) << endl;
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(3.7, 7.5) << endl;
	return 0;
}
