#include <iostream>
using namespace std;

class Point  // 포인트에 대한 클래스 정의
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {  }  // xpos 및 ypos에 대한 기본값이 있는 생성자
	friend ostream& operator<<(ostream& os, const Point& pos);  // Point 개체를 표시하기 위해 오버로드된 출력 스트림 연산자

	void* operator new (size_t size)  //동적 메모리 할당을 위한 오버로드된 새 연산자
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete (void* adr) // 동적으로 할당된 메모리를 해제하기 위한 오버로드된 삭제 연산자
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)  // Point 개체를 표시하기 위해 오버로드된 출력 스트림 연산자
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);  // 오버로드된 new 연산자를 사용하여 동적 Point 개체 만들기
	cout << *ptr;  //오버로드된 출력 스트림 연산자를 사용하여 Point 개체 표시
	delete ptr;  //오버로드된 삭제 연산자를 사용하여 동적 Point 객체 삭제
	return 0;
}
