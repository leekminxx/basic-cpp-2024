/*
RemoteControl클래스, SamsungTv 클래스, LgTv 클래스를 설계하고,
remote -> on()을 호출하면 연결된 TV에 따라서 "삼성 TV on" 또는 "LG TV on"이 출력되도록 프로그램을 완성하시오.
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
        cout << "삼성 TV on" << endl;
    }
};

class LgTv : public RemoteControl
{
public:
    virtual void On() {
        cout << "엘지 TV on" << endl;
    }
};



int main(void)
{
    RemoteControl* handler = new SamsungTV();      // SamsungTV 객체 생성!
    handler->On();                           // SamsungTv 클래스의 On() 호출

    handler = new LgTv();                     // 포인터 변수에 LgTv 객체 저장
    handler->On();                           // LgTv 클래스의 On() 호출
    delete handler;                           // 메모리 사용 후 반납!

    return 0;
}