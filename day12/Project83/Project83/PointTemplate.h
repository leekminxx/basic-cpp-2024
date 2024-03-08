#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_

template <typename T>  // T 유형의 좌표를 가진 Point에 대한 템플릿 클래스 정의
class Point
{
private:
	T xpos, ypos;   
public:
	Point(T x = 0, T y = 0);  // x와 y의 기본값을 갖는 생성자
	void ShowPosition() const;  // 좌표를 표시하는 멤버 함수
};

template <typename T>  // Point 클래스의 생성자 구현
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{  }

template <typename T>   // 좌표를 표시하기 위한 멤버 함수 구현
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

#endif