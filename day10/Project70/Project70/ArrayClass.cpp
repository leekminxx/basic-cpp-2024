#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray   // �ٿ�� �˻縦 ����Ͽ� �������� �Ҵ�� �迭�� ���� Ŭ���� ����
{
private:
	int* arr;  //�������� �Ҵ�� �迭�� ���� ������
	int arrlen;  // �迭�� ����
public: 
	BoundCheckIntArray(int len) :arrlen(len)  // �־��� ���̷� �迭�� �ʱ�ȭ�ϴ� ������
	{
		arr = new int[len];   //�迭�� �޸𸮸� �������� �Ҵ�
	}
	int& operator[] (int idx)  //�ٿ�� �˻縦 ���� �迭 ��� �׼����� ���� �����ε�� ������
	{
		if (idx < 0 || idx >= arrlen)  // �ε����� ������ ������� Ȯ��
		{
			cout << "Array index out of bound exception" << endl;
			BoundCheckIntArray::~BoundCheckIntArray();
			exit(1);  //�ε����� ������ ����� ���α׷��� ����
		}

		return arr[idx];  //�־��� �ε����� �ִ� �迭 ��ҿ� ���� ������ ��ȯ
	}
	~BoundCheckIntArray()  //��ü�� �ı��� �� �������� �Ҵ�� �޸𸮸� �����ϴ� �Ҹ���
	{
		delete[]arr;  //��̿��� ����ϴ� �޸� �Ҵ� ����
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);  //���̰� 5�� BoundCheckIntArray ������ 'arr' ��ü�� ����

	for (int i = 0; i < 5; i++)   // ������ ����Ͽ� �迭 ä���
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;

	return 0;
}
