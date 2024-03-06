/*#include <iostream>	

namespace mystd
{
	using namespace std;

	class ostream  //����� ���� ostream Ŭ���� ����
	{
	public:
		ostream& operator<< (char* str)  // ���ڿ� ����� ���� �����ε�� ������
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<< (char str)  // ���� ���ڸ� ����ϱ� ���� �����ε�� ������
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<< (int num)  // ���� ����� ���� �����ε�� ������
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<< (double e)  // double�� ����ϱ� ���� �����ε�� ������
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator<< (ostream& (*fp)(ostream& ostm))  // �����ڸ� ó���ϱ� ���� �����ε�� ������(��: endl)
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm)  //����� ���� endl �Լ� ����
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	ostream cout;  // Ŀ���� cout ��ü ����
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;  // ����� ���� cout ��ü�� ����Ͽ� double, newline, ���� �� newline ���
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
