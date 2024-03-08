#include <iostream>
#include <cstring>
using namespace std;

template <typename T>  // 두 값의 최대값을 찾는 함수 템플릿
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>  // 문자열 길이에 따라 최대값을 찾기 위한 char* 전문화
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>  // 사전식 순서에 따라 최대값을 찾기 위한 const char* 전문화
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}


int main(void)  // 다양한 데이터 유형으로 Max 함수 테스트
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	// char 배열을 사용하여 Max 함수 테스트

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	return 0;
}
