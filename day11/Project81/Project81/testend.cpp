/*
	5���� 
*/

#define 
#include <iostream>
using namespace std;
class Grade {
	char* name;          // �����͸� ����ϰ� �ִ� 
	int ko;
	int eng;
	int math;
	Grade(const char* name, int ko, int eng, int math) {
		new char[strlen(name) + 1];  //strlen ���ڸ��Ͻ�Ű���� 
		strcpy(this->name, name);
		this->ko = ko;
		this->eng = eng;
		this->math = math;

	}
	~Grade() {
		printf("�Ҹ��� ȣ��\n");
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
	Grade* gradeAry[3];   // ��ü ������  �迭 

	char name[20] = {};  // �迭 Ÿ�� 
	int inko = 0;
	int inEng = 0;
	int inMath = 0;

	// 1. �Է��� �޴´�
	for (int i = 0; i < 3; i++) {
		cout << "�̸�: ";
		cin >> name;
		cout << "��������: ";
		cin >> inko;
		cout << "��������: ";
		cin >> inEng;
		cout << "��������: ";
		cin >> inMath;

		//cout << name << inko << inEng << inMath << endl;
		// 2. ��ü���� : 5���� ��ü�� ����(2). ��ü�迭 or ��ü ������ �迭 
		gradeAry[i] = new Grade(name, inko, inEng, inMath);
	}
	/*
	for (int i = 0; i < 3; i++) {
		//cout << " ���� : " gradeAry[i] - sum() << " ���� : " << gradeAry[i] - > avr() << endl;
		printf("i��° �л� ���� : %d , ���� : %1|f\n", gradeAry[i] - sum , gradeAry[i] - avr())
	}
		*/
		
		


		
	cout << gradeAry[0]->getKo() << endl;

	for (int i = 0; i < 3; i++) {
		printf("��ü �Ҵ� �Ҹ��� ȣ��\n");
		delete gradeAry[i];
	}
	return 0;
};