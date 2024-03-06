/*
5명의 이름과 국 , 영 , 수 3과목을 입력받아 학생별 총점과 평균 , 그리고 과목별 총점과 평균을 구하시오.
class Grade{
	char *name;
	int kr;
	int math;
	int english;
}
*/

#include <iostream>
#include <cstring>
using namespace std;

class Grade {
private:
	char* name;
	int kr;
	int math;
	int english;
public:
	Grade(const char* aname, int akr, int amath, int aenglish) : kr(akr) , math(amath) , english(aenglish) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
	}
	~Grade() {
		delete[] name;
	}
	void promath() const {
		int total = kr + math + english;
		double average = static_cast<double>(total) / 3;

		cout << "Name" << name << " , ";
		cout << "Total" << total << ", ";
		cout << "Average" << average << endl;
	}
	int  get 









};