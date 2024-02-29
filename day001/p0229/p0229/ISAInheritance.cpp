#include <iostream>
#include <string>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����դ��ϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(char* name, int initchag)
		: Computer(name), Battery(initchag)
	{ }
	void Charging() { Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void Movingcal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�. " << endl;
			return;
		}
		cout << "�̵��ϸ鼭";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TableNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TableNotebook(char* name, int initchag, char* pen)
		:NotebookComp(name, initchag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ� ." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TableNotebook tn("������", 5, "ISE-241-242");
	nc.Movingcal();
	tn.Write("ISE-241-242");
	return 0;
}
