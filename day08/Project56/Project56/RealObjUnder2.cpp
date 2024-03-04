// ����Լ��� �����Լ��� ���ۿ���

#include <iostream>
using namespace std;

// Ŭ���� Data�� �䳻�� ����
typedef struct Data  //Data Ŭ������ ����ϴ� ���� ����
{
	int data;    // ������ �����ϴ� ������ ���
	void (*ShowData)(Data*);  // ShowData ����Լ� ����
	void (*Add)(Data*, int);  // Add ����Լ� ����
} Data;

void ShowData(Data* THIS)  // ShowData ����Լ� ����  , ���𸻰� ���� �κп��� ��Ȯ�� THIS �� �;��� 
{
	cout << "Data: " << THIS->data << endl;
}
void Add(Data* THIS, int num) { // Add ����Լ� ���� 
	THIS->data += num;
}


// ������ ����� main �Լ�
int main(void)
{  //�� ���� ������ ���� ����
	Data obj1 = { 15, ShowData, Add };    // Data ����ü ���� obj1 ����� �ʱ�ȭ 
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17); // Add �Լ��� ����Ͽ� obj1�� �����Ϳ� 17�� �߰��մϴ�.
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
};
