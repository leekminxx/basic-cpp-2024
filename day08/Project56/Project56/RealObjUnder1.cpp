// ����Լ��� �����Լ��� ���ۿ���


#include <iostream>
using namespace std;

class Data  // �����Ϳ� ���� Ŭ���� ����
{
private:
	int data; // �����͸� �����ϴ� ���� ��� ����
public:   // ������ ������ �����͸� �ʱ�ȭ�ϴ� ������
	Data(int num) : data(num)
	{  }
	void ShowData()  // �������� ���� ���� ǥ���ϴ� ��� �Լ�
	{
		cout << "Data: " << data << endl;
	}
	void Add(int num)  //�������� ���� ���� �־��� ���ڸ� �߰��ϴ� ��� �Լ�
	{
		data += num;
	}
};

int main(void)
{
	Data obj(15);  //�ʱⰪ�� 15�� Data Ŭ������ ��ü�� �����մϴ�.
	obj.Add(17);  //��ü�� �����Ϳ� 17�� �߰��մϴ�.
	obj.ShowData();  //�������� ���� ���� ǥ���մϴ�.
	return 0;
}