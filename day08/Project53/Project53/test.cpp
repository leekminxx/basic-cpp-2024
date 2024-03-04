#include <iostream>
using namespace std;

class RemoteControl
	void on() {
	cout << "tv¸¦ ÄÕ´Ï´Ù" << endl;
    }
};

class SamsungTv : public RemoteControl {
	void on() {
		cout << " »ï¼º  tv ¸¦ ÄÕ´Ï´Ù." << endl;
	}
};

class LgTv : public RemoteControl {
	void on() {
		cout << " Lg tv ¸¦ ÄÕ´Ï´Ù." << endl;
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