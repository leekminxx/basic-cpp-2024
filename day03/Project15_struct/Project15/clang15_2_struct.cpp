#include <iostream>
/*
* c++ 타입의 구조체: 클래스멤버로 멤버변수와 멤버함수 가진다
*/
class human { //human 구조체 => 내가 만든 사용자 정의 자료형
public:
	char name[20]; // 속성 멤버변수(name, age, job)
	int age;
	char job[20];

void showHuman() {
	printf("name: %s, age: %d, job: %s\n", name, age, job);
}

} Human; // 앞으로 human 구조체를 Human으로 사용

int main() {
	/*int a = 10;
	human h1 = { "Hong", 50, "의적" }; //Human타입의 변수를 선언하고 초기화를 시킨다
	h1.showHuman();*/

	human h1 = {"hong", 50, "의적"};
	return 0;

}