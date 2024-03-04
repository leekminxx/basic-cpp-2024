// 멤버함수와 가상함수의 동작원리

#include <iostream>
using namespace std;

// 클래스 Data를 흉내낸 영역
typedef struct Data  //Data 클래스를 모방하는 구조 정의
{
	int data;    // 정수를 저장하는 데이터 멤버
	void (*ShowData)(Data*);  // ShowData 멤버함수 선언
	void (*Add)(Data*, int);  // Add 멤버함수 선언
} Data;

void ShowData(Data* THIS)  // ShowData 멤버함수 정의  , 선언말고 정의 부분에는 정확히 THIS 가 와야함 
{
	cout << "Data: " << THIS->data << endl;
}
void Add(Data* THIS, int num) { // Add 멤버함수 정의 
	THIS->data += num;
}


// 적절히 변경된 main 함수
int main(void)
{  //두 개의 데이터 구조 생성
	Data obj1 = { 15, ShowData, Add };    // Data 구조체 변수 obj1 선언과 초기화 
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17); // Add 함수를 사용하여 obj1의 데이터에 17을 추가합니다.
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
};
