#include <iostream>
#include <string>
using namespace std;

// �θ� Ŭ���� Product ����
class Product {
private:
    int id;
    double price;
    string producer;
public:

    // ������
    Product(int _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

    // ���� ��ȯ
    double getPrice() const {
        return price;
    }

    // ���� ����
    void setPrice(double _price) {
        price = _price;
    }

    // ���� ���
    virtual void print() const = 0; // ���� ���� �Լ�

    // ���� �Ҹ��� �߰�
    virtual ~Product() {}

    // ID ��ȯ
    int getId() const {
        return id;
    }
    // ������ ��ȯ
    string getProducer() const {
        return producer;
    }
};

// �ڽ� Ŭ���� Book ����
class Book : public Product {
private:
    string ISBN;
    string title;

public:
    // ������
    Book(int _id, double _price, string _producer, string _ISBN, string _title)
        : Product(_id, _price, _producer), ISBN(_ISBN), title(_title) {}
    // ��ǰ ���� ���
    virtual void print() const override {
        cout << "Book ID : " << getId() << ", ISBN : " << ISBN << ", Title : " << title << ", Price :" << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// �ڽ� Ŭ���� Handphone ����
class Handphone : public Product {
private:
    string model;
    int RAM;
public:
    // ������
    Handphone(int _id, double _price, string _producer, string _model, int _RAM)
        : Product(_id, _price, _producer), model(_model), RAM(_RAM) {}
    // ��ǰ ���� ���
    virtual void print() const override {
        cout << "Handphone ID: " << getId() << ", Model : " << model << ", RAM : " << RAM << "GB, Price :" << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// �ڽ� Ŭ���� Computer ����
class Computer : public Product {
private:
    string model;
    string cpu;
    int RAM;
public:
    // ������
    Computer(int _id, double _price, string _producer, string _model, string _cpu, int _RAM)
        : Product(_id, _price, _producer), model(_model), cpu(_cpu), RAM(_RAM) {}
    // ��ǰ ���� ���
    virtual void print() const override {
        cout << "Computer ID :x " << getId() << ", Model : " << model << ", CPU : " << cpu << ", RAM : " << RAM << "GB, Price : " << getPrice() << ", Producer : " << getProducer() << endl;
    }
};

// ��ǰ�� �˻��ϴ� �Լ�
void searchProduct(Product* products[], int count, int targetId) {
    for (int i = 0; i < count; ++i) {
        if (products[i]->getId() == targetId) {
            products[i]->print();
            return;
        }
    }
    cout << "�ش� ID�� ��ǰ�� ã�� �� �����ϴ�." << endl;
}

int main() {
    Product* products[100]; // ��ü ������ �迭

    int choice;
    int count = 0; // ���� �߰��� ��ǰ ��

    // ���� �޴� ���
    while (true) {
        cout << "��ǰ���� ���α׷�" << endl;
        cout << "1. ��ǰ�߰�  2. ��ǰ���  3. ��ǰ�˻�  0. ����" << endl;
        cout << "����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int subChoice;
            cout << "1. å  2. �ڵ���  3. ��ǻ��" << endl;
            cout << "����: ";
            cin >> subChoice;

            switch (subChoice) {
            case 1: {
                int id;
                double price;
                string producer, ISBN, title;
                cout << "å ���� �Է�" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "ISBN: ";
                cin >> ISBN;
                cout << "����: ";
                cin >> title;
                products[count++] = new Book(id, price, producer, ISBN, title);
                cout << "å�� �߰��Ǿ����ϴ�." << endl;
                break;
            }
            case 2: {
                int id, RAM;
                double price;
                string producer, model;
                cout << "�ڵ��� ���� �Է�" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "��: ";
                cin >> model;
                cout << "RAM (GB): ";
                cin >> RAM;
                products[count++] = new Handphone(id, price, producer, model, RAM);
                cout << "�ڵ����� �߰��Ǿ����ϴ�." << endl;
                break;
            }
            case 3: {
                int id, RAM;
                double price;
                string producer, model, cpu;
                cout << "��ǻ�� ���� �Է�" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "����: ";
                cin >> price;
                cout << "������: ";
                cin >> producer;
                cout << "��: ";
                cin >> model;
                cout << "CPU: ";
                cin >> cpu;
                cout << "RAM (GB): ";
                cin >> RAM;
                products[count++] = new Computer(id, price, producer, model, cpu, RAM);
                cout << "��ǻ�Ͱ� �߰��Ǿ����ϴ�." << endl;
                break;
            }
            default:
                cout << "�߸��� �����Դϴ�." << endl;
            }
            break;
        }
        case 2: {
            cout << "�߰��� ��ǰ ���:" << endl;
            for (int i = 0; i < count; ++i) {
                products[i]->print();
            }
            break;
        }
        case 3: {
            int targetId;
            cout << "�˻��� ��ǰ�� ID�� �Է��ϼ���: ";
            cin >> targetId;
            searchProduct(products, count, targetId);
            break;
        }
        case 0: {
            // �޸� ����
            for (int i = 0; i < count; ++i) {
                delete products[i];
            }
            return 0;
        }
        default:
            cout << "�߸��� �����Դϴ�." << endl;
        }
    }

    return 0;
}