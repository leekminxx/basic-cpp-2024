#include <iostream>
using namespace std;
// 함수 템플릿 Max는 동일한 유형 T의 값 두 개를 취하고 그 중 최대값을 반환합니다.
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;   // 정수와 함께 Max 사용: 11 및 15
	cout << Max('T', 'Q') << endl;  // 문자 'T' 및 'Q'와 함께 Max 사용 , 알파벳순서를 보고 
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;
	return 0;
}
