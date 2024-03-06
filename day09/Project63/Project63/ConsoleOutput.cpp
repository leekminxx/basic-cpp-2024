#include <iostream>	

namespace mystd
{
	using namespace std;

	class ostream  //사용자 정의 ostream 클래스 정의
	{
	public:
		void operator<< (const char* str)  // 문자열 출력을 위한 오버로드된 연산자
		{
			printf("%s", str);
		}
		void operator<< (char str) // 단일 문자를 출력하기 위한 오버로드된 연산자
		{
			printf("%c", str);
		}
		void operator<< (int num)  //정수 출력을 위한 오버로드된 연산자
		{
			printf("%d", num);
		}
		void operator<< (double e)  //double을 출력하기 위한 오버로드된 연산자
		{
			printf("%g", e);
		}
		void operator<< (ostream& (*fp)(ostream& ostm))  //조작자를 처리하기 위한 오버로드된 연산자(예: endl)
		{
			fp(*this);
		}
	};

	ostream& endl(ostream& ostm)  //사용자 정의 endl 함수 정의
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	ostream cout;  //커스텀 cout 객체 선언
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;

	cout << "Simple String";  // 사용자 정의 cout 객체를 사용하여 다양한 유형 출력
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);
	return 0;
}