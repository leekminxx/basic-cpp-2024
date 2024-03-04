/*
RemoteControlŬ����, SamsungTv Ŭ����, LgTv Ŭ������ �����ϰ�,
remote -> on()�� ȣ���ϸ� ����� TV�� ���� "�Ｚ TV on" �Ǵ� "LG TV on"�� ��µǵ��� ���α׷��� �ϼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void On()
    {}
};

class SamsungTV : public RemoteControl
{
public:
    virtual void On() {
        cout << "�Ｚ TV on" << endl;
    }
};

class LgTv : public RemoteControl
{
public:
    virtual void On() {
        cout << "���� TV on" << endl;
    }
};



int main(void)
{
    RemoteControl* handler = new SamsungTV();      // SamsungTV ��ü ����!
    handler->On();                           // SamsungTv Ŭ������ On() ȣ��

    handler = new LgTv();                     // ������ ������ LgTv ��ü ����
    handler->On();                           // LgTv Ŭ������ On() ȣ��
    delete handler;                           // �޸� ��� �� �ݳ�!

    return 0;
}