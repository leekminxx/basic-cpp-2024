#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)  //기본값이 있는 생성자
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }  //데이터를 표시하는 멤버 함수

	First& operator=(const First& ref)  //기본 클래스에 대한 복사 할당 연산자
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public: // 기본 클래스 생성자를 호출하는 초기화 목록이 있는 생성자
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4)
	{  }
	void ShowData()  // 기본 클래스 데이터를 포함한 데이터를 표시하는 멤버 함수
	{
		First::ShowData();   //기본 클래스 데이터를 포함한 데이터를 표시하는 멤버 함수
		cout << num3 << ", " << num4 << endl;
	}

	
	Second& operator=(const Second &ref)
	{
		cout<<"Second& operator=()"<<endl;
		First::operator=(ref);
		num3=ref.num3;
		num4=ref.num4;
		return *this;
	}
	

};


int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}