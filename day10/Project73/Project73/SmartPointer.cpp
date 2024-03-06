#include <iostream>
using namespace std;

class Point  //Point에 대한 클래스 정의
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)  //기본값을 사용하여 xpos 및 ypos를 초기화하는 생성자
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()  //객체가 파괴될 때 메시지를 표시하는 소멸자
	{
		cout << "Point 객체 소멸" << endl;
	}
	void SetPos(int x, int y)  //Point의 위치를 ​​설정하는 멤버 함수
	{
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);  //Point의 출력 스트림 연산자를 오버로드하는 Friend 함수
};
ostream& operator<<(ostream& os, const Point& pos)  // Point에 대한 오버로드된 출력 스트림 연산자
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr  // SmartPtr에 대한 클래스 정의
{
private:
	Point* posptr; // Point 객체에 대한 포인터
public:
	SmartPtr(Point* ptr) : posptr(ptr)  // 포인트 포인터로 SmartPtr을 초기화하는 생성자
	{  }

	Point& operator*() const  // Point 객체에 액세스하기 위해 오버로드된 역참조 연산자(*)
	{
		return *posptr;
	}
	Point* operator->() const  // Point 객체의 멤버에 액세스하기 위해 오버로드된 화살표 연산자(->)
	{
		return posptr;
	}
	~SmartPtr()  // 동적으로 할당된 Point 객체를 삭제하기 위한 소멸자
	{
		printf("SmartPtr 객체 소멸\n");
		delete posptr;
	}
};

int main(void)
{						//힙영역
	SmartPtr sptr1(new Point(1, 2));  // 동적으로 할당된 Point 객체를 사용하여 SmartPtr 객체를 생성
	SmartPtr sptr2(new Point(2, 3));  // 메모리 동적 할당되어있음
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1;					  // 오버로드된 출력 스트림 연산자를 사용하여 Point 객체를 표시
	cout << *sptr2;					  // 
	cout << *sptr3;

	sptr1->SetPos(10, 20);			  // 화살표 연산자(->)를 사용하여 Point 객체의 새 위치를 설정
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;					  // 업데이트된 Point 객체를 표시
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}


// new Point(1, 2) > (10, 20) 값으로 변경됨

// 메모리 공간할당받은걸 자동으로 해제 
