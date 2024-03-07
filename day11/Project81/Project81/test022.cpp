#include <iostream>
#include <cstring>
using namespace std;

class Grade {
private:
    char* name;
    int kor;
    int math;
    int eng;
    int total;
    double average;

public:
    // ������: �л��� �̸��� �� ������ ������ �޾� �ʱ�ȭ
    Grade(const char* name, int kor, int math, int eng) {
        // �̸� ����
        size_t len = strlen(name) + 1;
        this->name = new char[len];
        strcpy_s(this->name, len, name);

        // ���� ���� ����
        this->kor = kor;
        this->math = math;
        this->eng = eng;

        // ������ ��� ���
        calculateTotal();
        calculateAverage();
    }

    // �Ҹ���: �������� �Ҵ�� �޸� ����
    ~Grade() {
        delete[] name;
    }

    // ���� ��� �Լ�
    void calculateTotal() {
        total = kor + math + eng;
    }

    // ��� ��� �Լ�
    void calculateAverage() {
        average = total / 3.0;
    }

    // �̸� ��ȯ �Լ�
    const char* getName() const {
        return name;
    }

    // ���� ���� ��ȯ �Լ�
    int getKor() const {
        return kor;
    }

    // ���� ���� ��ȯ �Լ�
    int getMath() const {
        return math;
    }

    // ���� ���� ��ȯ �Լ�
    int getEng() const {
        return eng;
    }

    // ���� ��ȯ �Լ�
    int getTotal() const {
        return total;
    }

    // ��� ��ȯ �Լ�
    double getAverage() const {
        return average;
    }
};

int main() {
    const int NUM_STUDENTS = 5;
    Grade* gradeAry[NUM_STUDENTS];    // �л� ��ü�� ����Ű�� ������ �迭
    int korTotal = 0, mathTotal = 0, engTotal = 0; // �� ������ ������ ������ ���� �ʱ�ȭ

    // 5���� �л� ���� �Է�
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        char name[20];
        int inko, inEng, inmath;

        // ����ڷκ��� �л� ���� �Է� ����
        cout << "�̸�: ";
        cin >> name;
        cout << "����: ";
        cin >> inko;
        cout << "����: ";
        cin >> inmath;
        cout << "����: ";
        cin >> inEng;
        cout << endl;

        // Grade ��ü ���� �� ���� ����
        gradeAry[i] = new Grade(name, inko, inmath, inEng);

        // �� ������ ���� ����
        korTotal += inko;
        mathTotal += inmath;
        engTotal += inEng;
    }

    // �� ������ ��� ���
    double korAverage = static_cast<double>(korTotal) / NUM_STUDENTS;
    double mathAverage = static_cast<double>(mathTotal) / NUM_STUDENTS;
    double engAverage = static_cast<double>(engTotal) / NUM_STUDENTS;

    // 5���� �л� ���� ��� �� �� ������ ������ ��� ���
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "�̸�: " << gradeAry[i]->getName() << endl;
        cout << "����: " << gradeAry[i]->getKor() << ", ����: " << gradeAry[i]->getMath() << ", ����: " << gradeAry[i]->getEng() << endl;
        cout << "����: " << gradeAry[i]->getTotal() << ", ���: " << gradeAry[i]->getAverage() << endl;
        cout << endl;
    }

    // �� ������ ������ ��� ���
    cout << "���� ������ ���� : " << korTotal << ", ��� : " << korAverage << endl;
    cout << "���� ������ ����: " << mathTotal << ", ���: " << mathAverage << endl;
    cout << "���� ������ ����: " << engTotal << ", ���: " << engAverage << endl;

    // Grade ������ �迭 ����
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        delete gradeAry[i];
    }

    return 0;
}


int main()
{

    char nmae[20] = {};
    int inko = 0;
    int inEng = 0;
    int inMath = 0;
    int num = 0;

    cout << "����ó�� �л���: " << endl;
    cin >> num;

    vector<Grade*> gradeAry(num);
    //vector<Grade> gradeAry(num);
    //vector<Grade> gradeAry(num);
    
    // 1. �ϳ��� �Է��� �޴´� -> 5�� �Է�
    for (int i = 0; i < 50; i++) {
        {
            printf("%d��° �л� ����: %d, ����:")
        }
}
