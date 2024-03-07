#include <iostream>
using namespace std;
// 함수 템플릿 ShowData는 두 가지 유형 매개변수 T1과 T2를 사용하고 T1과 T2에 캐스팅된 입력 값을 표시합니다.
template <class T1, class T2>  
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)  // 다양한 템플릿 인수와 입력 값을 사용하여 ShowData 함수의 사용법을 보여줍니다.
{
	ShowData<char, int>(65); // ShowData<char, int> - char 및 int로 캐스팅된 입력 값(65)을 표시합니다.
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);  // ShowData<char, double> - Displaying the input value (68.9) casted to char and double.
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}
