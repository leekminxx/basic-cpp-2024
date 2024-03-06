#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)  //이름과 나이에 대한 매개변수가 있는 생성자
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	/*
	Person& Person::operator=(const Person& ref)  //복사 할당 연산자
	{
		delete []name;

		int len=strlen(ref.name)+1;  //자체 할당 확인
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}
	*/

	void ShowPersonInfo() const  //개인 정보를 표시하는 멤버 함수
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person()  //할당된 메모리를 해제하는 소멸자
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);  //Person 클래스의 인스턴스 만들기
	Person man2("Yoon ji yul", 22);
	man2 = man1;   //복사 할당 연산자 사용
	man1.ShowPersonInfo();  //두 인스턴스 모두에 대한 정보 표시
	man2.ShowPersonInfo();
	return 0;
}