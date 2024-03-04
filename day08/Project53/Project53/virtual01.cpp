#include <iostream>
using namespace std;

class Base {
public:  //멤버함수
	Base() {};
	~Base() {};
	virtual void func1() { cout << "Base::func1()" << endl; }
	virtual void func2() { cout << "Base::func2()" << endl; }
	void func3() { cout << "Base::func3()" << endl; }
	
};
class Derived : public Base{  //자식함수
public:
	void func1() { cout << "Derived::func1()" << endl; }
	void func3() { cout << "Derived::func2()" << endl; }
	void func4() { cout << "Derived::func3()" << endl; }
	
	Derived() {}
};

int main()
{
	Base b; //Base 타입의 객체변수 
	Derived d; 
	Base* pb = new Derived();  //Base 타입의 객체 포인터

	pb->func1();
	pb->func2();
	pb->func3();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

	cout << endl;
	Derived* pd = &d;
	pd->func1();
	pd->func2();
	pd->func3();
	pd->func4();


	return 0;
}

// 추상클래스 지금 당장 필요하지않은 클래스 미래를 
// 예언해서 만든 클래스 순수 가상함수에 몸체를 작성해서 객체를 생성하라

/*
다형성 
*/

// 가상 소멸자 