#include <iostream>
using namespace std;

class First //퍼스트클래스 선언
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)  //num1 및 num2에 대한 기본값을 갖는 생성자
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }  //데이터를 표시하는 멤버 함수
};

class Second  //Second 클래스 선언
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)  //num3 및 num4에 대한 기본값을 갖는 생성자
	{  }
	void ShowData() { cout << num3 << ", " << num4 << endl; }  // 데이터를 표시하는 멤버 함수

	Second& operator=(const Second& ref)   //두 번째 클래스에 대한 오버로드된 할당 연산자
	{
		cout << "Second& operator=()" << endl;   
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)  //First 및 Second 클래스의 인스턴스 생성
{
	First fsrc(111, 222);  ////First 및 Second 클래스의 인스턴스 생성
	First fcpy; 
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;  //할당 연산자 사용
	scpy = ssrc;
	fcpy.ShowData();  //ShowData 함수를 사용하여 데이터 표시
	scpy.ShowData();

	First fob1, fob2;  //First 및 Second 클래스의 추가 인스턴스 생성
	Second sob1, sob2;
	fob1 = fob2 = fsrc;  //연결된 할당 연산자
	sob1 = sob2 = ssrc;

	fob1.ShowData();  //인스턴스의 데이터 표시
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}