#include <iostream>
using namespace std;

class RemoteControl
	void on() {
	cout << "tv�� �մϴ�" << endl;
    }
};

class SamsungTv : public RemoteControl {
	void on() {
		cout << " �Ｚ  tv �� �մϴ�." << endl;
	}
};

class LgTv : public RemoteControl {
	void on() {
		cout << " Lg tv �� �մϴ�." << endl;
	}
};

int main()
{
	RemoteControl* remote = new SamsungTv();
	remote->on();

	remote = new LgTv();
	remote->on();

	delete remote;
}