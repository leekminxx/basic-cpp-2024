// 멤버함수와 가상함수의 동작원리


#include <iostream>
using namespace std;

class Data  // 데이터에 대한 클래스 정의
{
private:
	int data; // 데이터를 저장하는 전용 멤버 변수
public:   // 제공된 값으로 데이터를 초기화하는 생성자
	Data(int num) : data(num)
	{  }
	void ShowData()  // 데이터의 현재 값을 표시하는 멤버 함수
	{
		cout << "Data: " << data << endl;
	}
	void Add(int num)  //데이터의 현재 값에 주어진 숫자를 추가하는 멤버 함수
	{
		data += num;
	}
};

int main(void)
{
	Data obj(15);  //초기값이 15인 Data 클래스의 객체를 생성합니다.
	obj.Add(17);  //개체의 데이터에 17을 추가합니다.
	obj.ShowData();  //데이터의 현재 값을 표시합니다.
	return 0;
}