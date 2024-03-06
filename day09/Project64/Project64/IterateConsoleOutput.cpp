/*#include <iostream>	

namespace mystd
{
	using namespace std;

	class ostream  //사용자 정의 ostream 클래스 정의
	{
	public:
		ostream& operator<< (char* str)  // 문자열 출력을 위한 오버로드된 연산자
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<< (char str)  // 단일 문자를 출력하기 위한 오버로드된 연산자
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<< (int num)  // 정수 출력을 위한 오버로드된 연산자
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<< (double e)  // double을 출력하기 위한 오버로드된 연산자
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator<< (ostream& (*fp)(ostream& ostm))  // 조작자를 처리하기 위한 오버로드된 연산자(예: endl)
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm)  //사용자 정의 endl 함수 정의
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	ostream cout;  // 커스텀 cout 객체 선언
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;  // 사용자 정의 cout 객체를 사용하여 double, newline, 정수 및 newline 출력
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
class Myclass {
	int num;
private:
	int xpos;
public:
	Myclass(int x = 0) : xpos()
	{}
	void print() {
	cout << " num " << xpos << endl;
	}

};

int main()
{
	Myclass a(10);  // value : 10
	a.print();

	Myclass b(a);
	b.print();     // value : 10

	Myclass c= b;
	c.print();      // value : 10

	Myclass d = a + b + c;
	d.print();       // value : 10
	
	return 0;
}


*/

#include <iostream>
using namespace std;

class Myclass {
private:
	int num;
	int xpos;

public:
	Myclass(int x = 0) : xpos(x) {}

	void print() {
		cout << "value: " << xpos << endl;
	}

	Myclass operator+(const Myclass& other) const {
		Myclass result;
		result.xpos = xpos + other.xpos;
		return result;
	}
};

int main() {
	Myclass a(10);  // value: 10
	a.print();

	Myclass b(a);
	b.print();     // value: 10

	Myclass c = b;
	c.print();      // value: 10

	Myclass d = a + b + c;
	d.print();       // value: 30

	return 0;
}
