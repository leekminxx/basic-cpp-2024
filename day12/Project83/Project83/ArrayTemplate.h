#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>  // BoundCheckArray에 대한 템플릿 클래스 정의
class BoundCheckArray
{
private:
	T* arr;  // 요소를 저장할 동적 배열
	int arrlen;  // 배열의 길이

	BoundCheckArray(const BoundCheckArray& arr) { }   // 원치 않는 복사본을 방지하기 위한 개인 복사본 생성자와 할당 연산자
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
	BoundCheckArray(int len);  // 길이 매개변수가 있는 생성자
	T& operator[] (int idx);   // const가 아닌 객체에 대한 오버로드된 첨자 연산자
	T operator[] (int idx) const;  // const 객체에 대한 오버로드된 첨자 연산자
	int GetArrLen() const;   // 배열의 길이를 검색하는 Getter 함수
	~BoundCheckArray();      // 동적으로 할당된 메모리를 해제하는 소멸자
};

template <typename T>  // 생성자 구현
BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len)
{
	arr = new T[len];
}

template <typename T>  // const가 아닌 객체에 대한 오버로드된 첨자 연산자
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>  // const 객체에 대한 오버로드된 첨자 연산자
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>  // 배열의 길이를 검색하는 Getter 함수
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>  // 동적으로 할당된 메모리를 해제하기 위한 소멸자 구현 템플릿 <유형 이름 T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}

#endif
