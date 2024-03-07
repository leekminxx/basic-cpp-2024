/*
	5명의 
*/

#define 
#include <iostream>
using namespace std;
class Grade {
	char* name;          // 포인터를 사용하고 있다 
	int ko;
	int eng;
	int math;
	Grade(const char* name, int ko, int eng, int math) {
		new char[strlen(name) + 1];  //strlen 문자리턴시키는중 
		strcpy(this->name, name);
		this->ko = ko;
		this->eng = eng;
		this->math = math;

	}
	~Grade() {
		printf("소멸자 호출\n");
		delete[] name;
	}
	int getko(){
	}
	int getEng() {
		  
	}
	void 

};

int main()
{
	Grade* gradeAry[3];   // 객체 포인터  배열 

	char name[20] = {};  // 배열 타입 
	int inko = 0;
	int inEng = 0;
	int inMath = 0;

	// 1. 입력을 받는다
	for (int i = 0; i < 3; i++) {
		cout << "이름: ";
		cin >> name;
		cout << "국어점수: ";
		cin >> inko;
		cout << "영어점수: ";
		cin >> inEng;
		cout << "수학점수: ";
		cin >> inMath;

		//cout << name << inko << inEng << inMath << endl;
		// 2. 객체생성 : 5개의 객체를 생성(2). 객체배열 or 객체 포인터 배열 
		gradeAry[i] = new Grade(name, inko, inEng, inMath);
	}
	/*
	for (int i = 0; i < 3; i++) {
		//cout << " 총점 : " gradeAry[i] - sum() << " 평점 : " << gradeAry[i] - > avr() << endl;
		printf("i번째 학생 총점 : %d , 평점 : %1|f\n", gradeAry[i] - sum , gradeAry[i] - avr())
	}
		*/
		
		


		
	cout << gradeAry[0]->getKo() << endl;

	for (int i = 0; i < 3; i++) {
		printf("객체 할당 소멸자 호출\n");
		delete gradeAry[i];
	}
	return 0;
};