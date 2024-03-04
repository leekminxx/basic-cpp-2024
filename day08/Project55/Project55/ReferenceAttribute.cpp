#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() // 기본 클래스의 멤버 함수
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc()  // 기본 클래스의 멤버 함수
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc()  //기본 클래스의 가상 함수 재정의
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc() //기본 클래스의 가상 함수 재정의
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void)
{
	Third obj;  // 세 번째 클래스의 객체 생성
	obj.FirstFunc();  //출력: FirstFunc()
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();
	return 0;
}