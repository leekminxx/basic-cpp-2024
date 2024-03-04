#include <iostream>
#include <string>

using namespace std;

class RemoteControl
private:
    virtual void on()
         

class SamsungTv : public RemoteControl {
public:
    void on() const override {
       cout << "SamsungTv  on" << endl;
    }
};

class LgTv : public RemoteControl {
public:
    void on() const override {
        cout << "LgTv on" << endl;
    }
};

class RemoteControl {
private:

public:
   

int main() {
    
    SamsungTv samsungTv;
    LgTv LgTv;

    RemoteControl remote1(&samsungTv);
    RemoteControl remote2(&lgTv);
    
    remote1.on();  
    remote2.on();  

    return 0;
}
