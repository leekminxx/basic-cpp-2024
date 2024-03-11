#include <iostream>
using namespace std;

void cal(int _n1, int _n2)   // void 쓰면 함수내에서 바로 출력하겠다 출력값없음 ,두 정수에 대한 사칙연산을 수행하고 결과를 출력하는 함수
{
	if (!_n2) throw _n2;    // 두 번째 정수가 0이면 예외를 발생시킴
	cout << " +: " << _n1 + _n2 << endl;
	cout << " -: " << _n1 - _n2 << endl;
	cout << " *: " << _n1 * _n2 << endl;
	cout << " /: " << _n1 / _n2 << endl;
}
int main(int argc, int* argv[])
{

	int n1, n2;   
	cout << "정수 2개를 입력하세요 : " << endl;
	cin >> n1;
	cin >> n2;
	try {
		cal(n1, n2);
	}
	catch (int exception) {
		cout << "0으로 나눌 수 없습니다." << endl;
	}
	return 0;
}
/*
배열 : 검색 <--> 수정

vector
자동으로 메모리가 할당. templet
*/