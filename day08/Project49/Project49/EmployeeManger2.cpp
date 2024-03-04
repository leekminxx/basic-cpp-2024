#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char name[100]; // ������ �̸��� ������ �迭
public:
    // ������: �̸��� �Ű������� �޾� name �迭�� �����մϴ�.
    Employee(const char* name) {
        strcpy_s(this->name, name);
    }

    // ������ �̸��� ����ϴ� ��� �Լ�
    virtual void ShowYourName() const {
        cout << "name: " << name << endl;
    }

    // �޿��� ��ȯ�ϴ� ���� ���� �Լ�. �� �Լ��� �Ļ� Ŭ�������� �����Ǿ�� �մϴ�.
    virtual int GetPay() const = 0;

    // �޿� ������ ����ϴ� ���� ���� �Լ�. �� �Լ��� �Ļ� Ŭ�������� �����Ǿ�� �մϴ�.
    virtual void ShowSalaryInfo() const = 0;

    // ���� �Ҹ���: �Ļ� Ŭ���������� ��ü ���� �� �������� �Ҹ��� ȣ���� �����մϴ�.
    virtual ~Employee() {}
};

class PermanentWorker : public Employee {
private:
    int salary; // ������ �޿��� �����ϴ� ����
public:
    // ������: �̸��� �޿� ������ �޾� �ʱ�ȭ�մϴ�. Employee�� �����ڸ� ȣ���մϴ�.
    PermanentWorker(const char* name, int money) : Employee(name), salary(money) { }

    // GetPay �������̵�: �� ������ �޿��� ��ȯ�մϴ�.
    int GetPay() const override {
        return salary;
    }

    // ShowSalaryInfo �������̵�: ������ �̸��� �޿� ������ ����մϴ�.
    void ShowSalaryInfo() const override {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};


class EmployeeHandler {
private:
    Employee* empList[50]; // ���� ��ü �����͸� ������ �迭
    int empNum; // ���� ����� ������ ��
public:
    // ������: empNum�� 0���� �ʱ�ȭ�մϴ�.
    EmployeeHandler() : empNum(0) { }

    // ���� ��ü�� �迭�� �߰��մϴ�.
    void AddEmployee(Employee* emp) {
        empList[empNum++] = emp;
    }

    // ����� ��� ������ �޿� ������ ����մϴ�.
    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    // ����� ��� ������ �޿��� ���� ����ϰ� ����մϴ�.
    void ShowTotalSalary() const {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }

    // �Ҹ���: �������� �Ҵ�� ��� ���� ��ü�� �����մϴ�.
    ~EmployeeHandler() {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};


int main(void) {
    EmployeeHandler handler; // ���� ������ ��ü ����

    // ���ο� PermanentWorker ��ü�� �����ϰ� ���� �����ڿ� �߰��մϴ�.
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // ����� ��� ������ �޿� ������ ����մϴ�.
    handler.ShowAllSalaryInfo();

    // ����� ��� ������ �޿� ���� ����մϴ�.
    handler.ShowTotalSalary();

    return 0; // ���α׷� ����
}
