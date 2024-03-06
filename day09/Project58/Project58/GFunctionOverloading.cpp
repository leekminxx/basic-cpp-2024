#include <iostream>
using namespace std;

class Point   // Point 클래스 선언
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)  //xpos 및 ypos에 대한 기본값이 있는 생성자
	{  }
	void ShowPosition() const  //Point의 위치를 ​​표시하는 멤버 함수
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);  //더하기 연산자에 대한 친구 함수 선언
};

Point operator+(const Point& pos1, const Point& pos2)  //Point 객체에 대한 추가 연산자 정의
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void) //점 개체 만들기
{   
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;  //두 개의 Point 객체를 추가하고 결과를 pos3에 저장
	// Point 객체의 위치 표시
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
