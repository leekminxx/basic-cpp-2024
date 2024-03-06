#include <iostream>
using namespace std;

class Point  //Point 클래스 선언
{
private:
	int xpos, ypos;
public:  
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) //xpos 및 ypos에 대한 기본값이 있는 생성자
	{  }  
	void ShowPosition() const  //Point의 위치를 ​​표시하는 멤버 함수
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	} 
	Point operator*(int times) //Point 객체에 대한 오버로드된 곱셈 연산자
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2); // 점 개체 만들기
	Point cpy;
	// pos에 3을 곱하고 그 결과를 cpy에 할당
	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();
	return 0;
}