#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()  //  기본 클래스의 가상 함수  ( 접근가능 범위가 객체타입으로 바뀜) 재정의되는 앞에 virtual 붙어있음 
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()  // 기본 클래스의 가상 함수 재정의
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second  // 파생 클래스 2, Second에서 상속됨
{
public:  // 기본 클래스의 가상 함수 재정의
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();  //동적 메모리 할당을 사용하여 세 번째 클래스의 객체 생성 , 실질적으로 가르키는 Third객체  MyFunc 호출 virtual 가상형태로 만들어주면 
	Second* sptr = tptr;   //tptr과 동일한 객체를 가리키는 기본 클래스에 대한 포인터
	First* fptr = sptr;   // tptr 및 sptr과 동일한 객체를 가리키는 기본 클래스에 대한 포인터
	// 각 포인터를 사용하여 재정의된 가상 함수 호출
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;  //메모리 누수를 방지하기 위해 동적으로 할당된 객체를 삭제합니다.
	return 0;
}
