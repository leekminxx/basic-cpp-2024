/*
*Parent class
class Product : id , price , producer
*Child class
class Book : ISBN , author , title  // 978-89-001-0001-1
class Handphone : model , RAM
class COmputer : model , cpu , RAM
*객체 포인터 배열 사용 : product[100]
*string 클래스 사용 가나ㅡㅇ

*메인화면
------상품관리 프로그램-----
1 상품추가 2상품출력 3상품검색 0종료
>

1또는 2또는 3을 선택한 경우
1책 2핸드폰 3컴퓨터
선택 목록을 띄워 해당 상품을 선택한 후에 추가 , 출력 , 또는 검색 실행된다.
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
		cout << "-------상품관리 프로그램--------" << endl;
		cout << "1. 상품추가 2. 상품출력 3. 상품검색 0. 종료" << endl;
		cout << " > ";
	
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "1. 책 2. 핸드폰 3. 컴퓨터" << endl;
			cout << "선택 목록을 띄워 해당 상품을 선택한 후에 추가, 출력, 또는 검색 실행된다." << endl;
			cout << " > ";

			int productType;
			cin >> productType;

			if (productCount < A_PRODUCTS) {
				string id, producer;
				double price;

				cout << "상품 ID: ";
				cin >> id;
				cout << "상품 가격:";
				cin >> price;
				cout << "상품 생산자: ";
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
					cout << "model이름:";
					cin >> model;
					cout << "RAM (gbyte)";
					cin >> RAM;

					_product[productCount] = new Handphone(id, price, producer, model, RAM);
					break;
				}
				case 3: {
					string model, CPU;
					int RAM;
					cout << "model 이름:";
					cin >> model;
					cout << "CPU 이름:";
					cin >> CPU;
					cout << "RAM (gbyte)";
					cin >> RAM;

					_product[productCount] = new Computer(id, price, producer, model, CPU, RAM);
					break;
					continue;
				}
					  productCount++;
					  cout << "_____상품 추가 " << endl;
					  break;
		case 2: {
		    if (productCount > 0) {
			cout << " 상품 목록 : " << endl;
			for (int i = 0; i < productCount++; i++) {
			_product[i]->Showinfo();
			}
			}

		else
			cout << " 출력목록이 없음 " << endl;
		}
		break;
		}
		case 3: {
			cout << "찾을 상품을 검색하세요." << endl;
			cin >> id;
			

			}
			break;
		}
		case 0: {
			for (int i = 0; i < productCount; i++) {
				delete _product[i];
			}
			cout << "종료하겠습니다." << endl;
			return 0;
		}
			break;

			}
		}
return 0;
		}
	}
}