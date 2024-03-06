#include <iostream>
using namespace std;

class Point  //Point에 대한 클래스 정의
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)  // 기본값을 사용하여 xpos 및 ypos를 초기화하는 생성자
	{  }
	Point operator+(const Point& pos) const  // Point 객체에 대해 오버로드된 추가 연산자(+)
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}
	friend ostream& operator<<(ostream& os, const Point& pos);  // Point에 대한 출력 스트림 연산자를 오버로드하는 Friend 함수
};

ostream& operator<<(ostream& os, const Point& pos)  // Point에 대한 오버로드된 출력 스트림 연산자
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class Adder  // Adder에 대한 Functor 클래스 정의
{
public:
	int operator()(const int& n1, const int& n2)  // 정수 덧셈을 위해 오버로드된 함수 호출 연산자()
	{
		return n1 + n2;
	}
	double operator()(const double& e1, const double& e2)  // 이중 덧셈을 위해 오버로드된 함수 호출 연산자()
	{
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2)  // 포인트 추가를 위해 오버로드된 함수 호출 연산자()
	{
		return pos1 + pos2;
	}
};

int main(void)
{
	Adder adder;  // Adder functor 클래스의 객체를 생성
	cout << adder(1, 3) << endl;  // 펑터를 사용하여 정수 덧셈   
	cout << adder(1.5, 3.7) << endl; // 펑터를 사용하여 이중 덧셈
	cout << adder(Point(3, 4), Point(7, 9));  // 펑터를 사용하여 포인트 추가
	return 0;
}

// 