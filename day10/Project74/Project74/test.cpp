/*
5���� �̸��� �� , �� , �� 3������ �Է¹޾� �л��� ������ ��� , �׸��� ���� ������ ����� ���Ͻÿ�.
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