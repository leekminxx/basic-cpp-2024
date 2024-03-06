
#include <iostream>

class MyClass {
    int* ptr;

public:
    MyClass(int p) : ptr(new int[100])
    {
        printf("생성자 호출\n");
    }
    ~MyClass()
    {
        printf("소멸자 호출\n");
        delete[] ptr;
    }
};

int main(void)
{
    MyClass* m1 = new MyClass(10);               // 소멸자가 호출되지 않는 문제가 발생한다.
    std::cout << "============================================================" << std::endl;

    std::unique_ptr<MyClass>m2(new MyClass(20)); // 스마트 포인터(unique_ptr<MyClass>) 형태를 통해 소멸자가 호출되지 않던 문제를 해결

    return 0;
}
