#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public: //기본값과 print 문이 있는 생성자
	AAA(int n = 0) : num(n)  // 정수 하나를 입력으로 갖는 생성자
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)  //객체 하나를 입력으로 갖는 생성자

	{
		cout << "AAA(const AAA & ref)" << endl;
	}
	AAA& operator=(const AAA& ref)  // 대입연산자 오버로딩 
	{
		num = ref.num;
		cout << "operator=(const AAA &ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref)
		: mem(ref)
	{  }
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref)
	{
		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "*********************" << endl;
	BBB obj2(obj1);
	cout << "*********************" << endl;
	CCC obj3(obj1);
	return 0;
}
// 배열이름 ary는 배열의 시작주소이다.
int ary[3]: // 배열선언부에서 배열 인덱스에 있는 숫자는 방의 크기
ary[2]; // 코드 실행에서 배열 인덱스에 있는 숫자는 방 번호를 나타낸다.

ary[0] = 10;  //0번방 , 첫번째방의 데이터
*(ary + 0) = 10;  //*(배열의 시작주소 + 0) = 10

*(ary + 1) = 20; == ary[1] = 20;    //1번방에다 20을 집어넣어라 .

ary의 주소가 0x0011 이라면 다음방 , 1번방(두번째방) 주소는 0x0015이다.

int* p;
*p;


