#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray   // 바운드 검사를 사용하여 동적으로 할당된 배열에 대한 클래스 정의
{
private:
	int* arr;  //동적으로 할당된 배열에 대한 포인터
	int arrlen;  // 배열의 길이
public: 
	BoundCheckIntArray(int len) :arrlen(len)  // 주어진 길이로 배열을 초기화하는 생성자
	{
		arr = new int[len];   //배열에 메모리를 동적으로 할당
	}
	int& operator[] (int idx)  //바운드 검사를 통해 배열 요소 액세스를 위한 오버로드된 연산자
	{
		if (idx < 0 || idx >= arrlen)  // 인덱스가 범위를 벗어났는지 확인
		{
			cout << "Array index out of bound exception" << endl;
			BoundCheckIntArray::~BoundCheckIntArray();
			exit(1);  //인덱스가 범위를 벗어나면 프로그램을 종료
		}

		return arr[idx];  //주어진 인덱스에 있는 배열 요소에 대한 참조를 반환
	}
	~BoundCheckIntArray()  //객체가 파괴될 때 동적으로 할당된 메모리를 해제하는 소멸자
	{
		delete[]arr;  //어레이에서 사용하는 메모리 할당 해제
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);  //길이가 5인 BoundCheckIntArray 유형의 'arr' 객체를 생성

	for (int i = 0; i < 5; i++)   // 루프를 사용하여 배열 채우기
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;

	return 0;
}
