#include <iostream>
using namespace std;

class Point  // ����Ʈ�� ���� Ŭ���� ����
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {  }  // xpos �� ypos�� ���� �⺻���� �ִ� ������
	friend ostream& operator<<(ostream& os, const Point& pos);  // Point ��ü�� ǥ���ϱ� ���� �����ε�� ��� ��Ʈ�� ������

	void* operator new (size_t size)  //���� �޸� �Ҵ��� ���� �����ε�� �� ������
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete (void* adr) // �������� �Ҵ�� �޸𸮸� �����ϱ� ���� �����ε�� ���� ������
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)  // Point ��ü�� ǥ���ϱ� ���� �����ε�� ��� ��Ʈ�� ������
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);  // �����ε�� new �����ڸ� ����Ͽ� ���� Point ��ü �����
	cout << *ptr;  //�����ε�� ��� ��Ʈ�� �����ڸ� ����Ͽ� Point ��ü ǥ��
	delete ptr;  //�����ε�� ���� �����ڸ� ����Ͽ� ���� Point ��ü ����
	return 0;
}
