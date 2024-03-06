#include <iostream>
using namespace std;

class Number  // Number에 대한 클래스 정의
{
private:
	int num;
public:  
	Number(int n) : num(n) {  }    // num을 초기화하는 생성자
	void ShowData() { cout << num << endl; }   // num 값을 표시하는 멤버 함수

	Number* operator->()   // 객체의 주소를 반환하는 오버로드된 화살표 연산자(->)
	{
		return this;
	}

	Number& operator*()    // 객체에 대한 참조를 반환하는 오버로드된 역참조 연산자(*)
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);       //초기값이 20인 Number 클래스의 객체를 만듬
	num.ShowData();       //ShowData 멤버 함수를 사용하여 초기값 표시

	(*num) = 30;          // 역참조 연산자(*)를 사용하여 값을 30으로 수정
	num->ShowData();      // ShowData 멤버 함수를 호출하려면 화살표 연산자(->)를 사용
	(*num).ShowData();    // ShowData 멤버 함수를 호출하려면 역참조 연산자(*)를 다시 사용

	return 0;
}
// 스마트포인트(객체) 자동적으로 메모리를 반환해줌 