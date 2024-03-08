/*
*Parent class
class Product : id , price , producer
*Child class
class Book : ISBN , author , title  // 978-89-001-0001-1
class Handphone : model , RAM
class COmputer : model , cpu , RAM
*��ü ������ �迭 ��� : product[100]
*string Ŭ���� ��� �����Ѥ�

*����ȭ��
------��ǰ���� ���α׷�-----
1 ��ǰ�߰� 2��ǰ��� 3��ǰ�˻� 0����
>

1�Ǵ� 2�Ǵ� 3�� ������ ���
1å 2�ڵ��� 3��ǻ��
���� ����� ��� �ش� ��ǰ�� ������ �Ŀ� �߰� , ��� , �Ǵ� �˻� ����ȴ�.
*/

#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string id;
	double price;
	string producer;
public:
	Product(const string& _id, double& _price, const string& _producer)
		: id(_id), price(_price), producer(_producer) {}

	virtual void Showinfo() const = 0;
};

class Book : public Product {
private:
	string ISBN;
	string author;
	string title;

public:
	Book(const string& _id, double& _price, const string& _producer, const string& _ISBN, const string& _author, const string& _title)
		: Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

	void Showinfo() const override {
		cout << "Book - ID: " << id << ", Price " << price << ", Producer:" << producer << "ISBN" << ISBN << ", Author" << author << ", Title" << title << endl;
	}
};

class Handphone : public Product {
private:
	string model;
	int RAM;
public:
	Handphone(const string& _id, double& _price, const string& _producer, const string& _model, int& _RAM)
		: Product(_id, _price, _producer), model(_model), RAM(_RAM) {}

	void Showinfo() const override {
		cout << "Handphone -ID : " << id << ", Price" << price << ", Producer" << producer << ", Model" << model << ", RAM" << RAM << "(gbyte)" << endl;
	}
};


class Computer : public Product {
private:
	string model;
	string CPU;
	int RAM;
public:
	Computer(const string& _id, double& _price, const string& _producer, const string& _model, const string& _CPU, int& _RAM)
		: Product(_id, _price, _producer), model(_model), CPU(_CPU), RAM(_RAM) {}
	void Showinfo() const override {
		cout << "Computer-ID :" << id << ",Price" << price << ", Producer" << producer << ", Model" << model << ", CPU " << CPU << ", RAM" << RAM << "(gbyte)" << endl;
	}
};

int main(void) {
	const int A_PRODUCTS = 100;
	Product* _product[A_PRODUCTS];
	int productCount = 0;

	while (true) {
		cout << "-------��ǰ���� ���α׷�--------" << endl;
		cout << "1. ��ǰ�߰� 2. ��ǰ��� 3. ��ǰ�˻� 0. ����" << endl;
		cout << " > ";
	
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "1. å 2. �ڵ��� 3. ��ǻ��" << endl;
			cout << "���� ����� ��� �ش� ��ǰ�� ������ �Ŀ� �߰�, ���, �Ǵ� �˻� ����ȴ�." << endl;
			cout << " > ";

			int productType;
			cin >> productType;

			if (productCount < A_PRODUCTS) {
				string id, producer;
				double price;

				cout << "��ǰ ID: ";
				cin >> id;
				cout << "��ǰ ����:";
				cin >> price;
				cout << "��ǰ ������: ";
				cin >> producer;

				switch (productType) {
				case 1: {
					string ISBN, author, title;
					cout << "ISBN";
					cin >> ISBN;
					cout << "author";
					cin >> author;
					cout << title;
					cin >> title;

					_product[productCount] = new Book(id, price, producer, ISBN, author, title);
					break;
				}
				case 2:
				{
					string model;
					int RAM;
					cout << "model�̸�:";
					cin >> model;
					cout << "RAM (gbyte)";
					cin >> RAM;

					_product[productCount] = new Handphone(id, price, producer, model, RAM);
					break;
				}
				case 3: {
					string model, CPU;
					int RAM;
					cout << "model �̸�:";
					cin >> model;
					cout << "CPU �̸�:";
					cin >> CPU;
					cout << "RAM (gbyte)";
					cin >> RAM;

					_product[productCount] = new Computer(id, price, producer, model, CPU, RAM);
					break;
					continue;
				}
					  productCount++;
					  cout << "_____��ǰ �߰� " << endl;
					  break;
		case 2: {
		    if (productCount > 0) {
			cout << " ��ǰ ��� : " << endl;
			for (int i = 0; i < productCount++; i++) {
			_product[i]->Showinfo();
			}
			}

		else
			cout << " ��¸���� ���� " << endl;
		}
		break;
		}
		case 3: {
			cout << "ã�� ��ǰ�� �˻��ϼ���." << endl;
			cin >> id;
			

			}
			break;
		}
		case 0: {
			for (int i = 0; i < productCount; i++) {
				delete _product[i];
			}
			cout << "�����ϰڽ��ϴ�." << endl;
			return 0;
		}
			break;

			}
		}
return 0;
		}
	}
}