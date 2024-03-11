#include <iostream>
#include <string>
using namespace std;

// �θ� Ŭ����
class Product {
private:
    string id;
    double price;
    string producer;

public:
    // ������
    Product(string _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

    // getter �Լ���
    string getId() const { return id; }
    double getPrice() const { return price; }
    string getProducer() const { return producer; }

    // ��ǰ ���� ���
    virtual void display() {
        cout << "ID: " << id << ", ����: " << price << "��, ������: " << producer << endl;
    }
};

// �ڽ� Ŭ����: å
class Book : public Product {
private:
    string ISBN;
    string author;
    string title;

public:
    // ������
    Book(string _id, double _price, string _producer, string _ISBN, string _author, string _title)
        : Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

    // å ���� ���
    void display() override {
        cout << "ID: " << getId() << ", ����: " << getPrice() << "��, ������: " << getProducer() << ", ISBN: " << ISBN << ", ����: " << author << ", ����: " << title << endl;
    }
};

// �ڽ� Ŭ����: �ڵ���
class Handphone : public Product {
private:
    string model;
    int ram;

public:
    // ������
    Handphone(string _id, double _price, string _producer, string _model, int _ram)
        : Product(_id, _price, _producer), model(_model), ram(_ram) {}

    // �ڵ��� ���� ���
    void display() override {
        cout << "ID: " << getId() << ", ����: " << getPrice() << "��, ������: " << getProducer() << ", ��: " << model << ", RAM: " << ram << "GB" << endl;
    }
};

// �ڽ� Ŭ����: ��ǻ��
class Computer : public Product {
private:
    string model;
    string cpu;
    int ram;

public:
    // ������
    Computer(string _id, double _price, string _producer, string _model, string _cpu, int _ram)
        : Product(_id, _price, _producer), model(_model), cpu(_cpu), ram(_ram) {}

    // ��ǻ�� ���� ���
    void display() override {
        cout << "ID: " << getId() << ", ����: " << getPrice() << "��, ������: " << getProducer() << ", ��: " << model << ", CPU: " << cpu << ", RAM: " << ram << "GB" << endl;
    }
};

// ��ǰ �˻� �Լ�
void searchProduct(Product* products[], string targetId) {
    bool found = false;
    for (int i = 0; products[i] != nullptr; ++i) {
        if (products[i]->getId() == targetId) {
            products[i]->display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "�ش� ID�� ��ǰ�� ã�� �� �����ϴ�." << endl;
    }
}

int main() {
    Product* products[100]; // ��ü ������ �迭
    int choice;
    int productCount = 0; // �߰��� ��ǰ ������ �����ϱ� ���� ����

    do {
        cout << "��ǰ ���� ���α׷�" << endl;
        cout << "1. ��ǰ �߰�  2. ��ǰ ���  3. ��ǰ �˻�  0. ����" << endl;
        cout << "���ϴ� �۾��� �����ϼ���: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int subChoice;
            cout << "1. å  2. �ڵ���  3. ��ǻ��" << endl;
            cout << "�߰��� ��ǰ ������ �����ϼ���: ";
            cin >> subChoice;

            string id, producer;
            double price;
            string model, ISBN, author, title, cpu;
            int ram;

            cout << "ID�� �Է��ϼ���: ";
            cin >> id;
            cout << "������ �Է��ϼ���: ";
            cin >> price;
            cout << "�����縦 �Է��ϼ���: ";
            cin >> producer;

            switch (subChoice) {
            case 1: {
                cout << "ISBN�� �Է��ϼ���: ";
                cin >> ISBN;
                cout << "���ڸ� �Է��ϼ���: ";
                cin >> author;
                cout << "������ �Է��ϼ���: ";
                cin >> title;

                products[productCount] = new Book(id, price, producer, ISBN, author, title);
                productCount++;
                break;
            }
            case 2: {
                cout << "���� �Է��ϼ���: ";
                cin >> model;
                cout << "RAM �뷮�� �Է��ϼ��� (GB ����): ";
                cin >> ram;

                products[productCount] = new Handphone(id, price, producer, model, ram);
                productCount++;
                break;
            }
            case 3: {
                cout << "���� �Է��ϼ���: ";
                cin >> model;
                cout << "CPU�� �Է��ϼ���: ";
                cin >> cpu;
                cout << "RAM �뷮�� �Է��ϼ��� (GB ����): ";
                cin >> ram;

                products[productCount] = new Computer(id, price, producer, model, cpu, ram);
                productCount++;
                break;
            }
            default:
                cout << "��ȿ���� ���� �����Դϴ�!" << endl;
            }
            break;
        }
        case 2: {
            cout << "��ǰ ��� ���:" << endl;
            for (int i = 0; i < productCount; ++i) {
                products[i]->display();
            }
            break;
        }
        case 3: {
            string targetId;
            cout << "�˻��� ��ǰ�� ID�� �Է��ϼ���: ";
            cin >> targetId;
            searchProduct(products, targetId);
            break;
        }
        case 0:
            cout << "�����մϴ�..." << endl;
            break;
        default:
            cout << "��ȿ���� ���� �����Դϴ�!" << endl;
        }
    } while (choice != 0);

    // ���� �޸� ����
    for (int i = 0; i < productCount; ++i) {
        delete products[i];
    }

    return 0;
}