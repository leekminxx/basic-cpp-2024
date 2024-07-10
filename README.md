# Basic-cpp-2024
IoT 시스템개발자 심화 프로그래밍 언어 학습리포지토리

## 1일차
<p>c++ 의 기본구조중하나인 함수는 재사용 가능한 코드 블록으로 변수를 사용하여 데이터를 저장하고 조작하는 중요한 요소이기때문에 중요하게 보기!!</p>

- 개발환경 설치
	- Visual Studio 2022 Community 설치

- 함수 정의의 구성 요소 및 주요 포인트❗
> 반환 타입(Return Type):함수가 반환하는 값의 데이터 타입을 지정 반환값이 없는 경우 'void' 사용

> 함수 이름(Function Name):함수를 호출할 때 사용하는 이름 

> 매개변수 목록(Parameter List): 함수가 입력으로 받을 수 있는 값 , 각 매개변수는 타입과 이름으로 구성 **매개변수가 없는동안 '( )' 사용**
> 함수 몸체(Function Body): 중괄호' {} ' 안에 함수가 수행할 작업을 정의 변수 선언 , 제어문 , 기타 함수 호출

- 반환 값이 없는 함수(void)
	```c++
	void sayHello() {
    std::cout << "Hello, World!" << std::endl;}
	// 'Hello , World' 를 출력하고 , 마우런 값을 반환하지 않음
	```	

- 매개변수가 있는 함수
	```c++
	void printNumber(int num) {
    std::cout << "The number is: " << num << std::endl;}
	// 이 함수는 정수 'num'을 입력으로 받아서 출력
	```

- 반환 값이 있는 함수 
	```c++
	int add(int a, int b) {
    return a + b;}
	// 두 개의 정수 'a' 와 'b' 를 입력으로 받아 그 합을 반환 
	```

- 제어문
	- 선택 제어문 요약
		> if 문: 조건이 참일 때 코드를 실행.
		
		> else 문: if 문의 조건이 거짓일 때 코드를 실행.
		
		> else if 문: 여러 조건을 순차적으로 검사.
		
		> switch 문: 하나의 변수 값에 따라 여러 경로 중 하나를 선택. | 'case' 키워드를 사용하여서 각 경로를 정의하고 , 'break' 키워드로 각 경로를 종료
		
	- 반복 제어문 | 중첩 반복문[반복문 안에 또 다른 반복문 사용] (반복 제어문을 사용하면 코드의 재사용성과 가독성을 높일 수 있으며, 반복적인 작업을 간결하게 처리할 수 있음)
		> for 반복문: 반복 횟수가 정해진 경우 사용.
		
		> while 반복문: 조건이 참인 동안 반복. 조건을 처음에 검사.

		> do-while 반복문: 조건이 참인 동안 반복. 최소 한 번은 실행.
	
- 지역변수 = 로컬변수 
	> 선언되어진 범위 안에서만 사용이 가능(static 영역에 저장) 해당 블록이 종료되면 소멸합니다.
	```c++
	#include <iostream>
	int main() {
		int num = 10; // num은 main 함수 내에서만 유효한 지역 변수
		std::cout << "Value of num: " << num << std::endl;
		return 0;
	} // 'num' 변수는 'main' 함수 내에서 선언된 지역 변수 main 함수가 끝나면 num변수는 더이상 유효하지 않음
	```

## 2일차
<p>C ++ 의 중요한 개념들로 클래스 내부의 메소드 , 기본값을 가지는 함수 , 참조를 사용하는 함수 , 네임스페이스 , 전역변수와 , 지역변수 C에서의 메모리 관리 , 비트 AND 연산자와 논리 AND 연산자에 대해 정리하고 
지금까지의 내용은 프로그래밍에서 필수적이고 효율적인 코드 작성을 위해 잘 이해하고 활용하는것이 중요!!</p>

- class 안에 들어 가는 함수 = Method
	```c++
	class MyClass {
	public:
    	void myMethod() {
        	std::cout << "This is a method." << std::endl;
    	}
	};
	// 클래스 내부에 정의된 함수를 메소드 라고 하고 메소드는 클래스의 인스턴스와 연관된 동작을 정의
	```

- Default 
	```c++
	void printMessage(std::string message = "Hello, World!") {
    std::cout << message << std::endl;
	}

	int main() {
		printMessage(); // 기본값인 "Hello, World!" 출력
		printMessage("Custom Message"); // "Custom Message" 출력
		return 0;
	}
	// C++ 에서는 함수의 매개변수에 기본값을 지정할 수 있는데 기본값이 지정된 매개변수는 함수 호출시 생략이 가능하고 생략된 경우에는 기본값이 사용됨
	```
- ❗Reference 함수
	> 장점 : 효율적인 메모리 사용 , 원본 데이터 수정가능 , 복잡한 객체의 처리용이 , **함수의 다형성**
	
	> 단점 : 부작용의 위험 , 의도하지 않은 수정 방지 어려움 , **메모리 관리 문제** , **언어 의존성**
	```c++
	void modifyValue(int& x) {
	x = 20;
	}

	int main() {
		int num = 10;
		modifyValue(num);
		std::cout << "Modified value: " << num << std::endl; // 20 출력
		return 0;
	}
	// main 함수에서 'num' 변수를 선언하고 초기값을 10으로 설정 
	// modifyValue(num);를 호출하면 num 변수의 참조가 modifyValue 함수에 전달
	// 함수 내에서 x는 num 변수를 참조하고 있으므로, x = 20;는 곧 num = 20;과 동일한 효과를 가지고있음
	// 따라서, 함수 호출 이후 num 변수의 값은 20으로 변경
	// std::cout << "Modified value: " << num << std::endl;는 num의 새로운 값을 출력하며, 결과는 20
	```

- ❗반환형 Reference Type
	> 반환형이 참조 타입인 함수는 함수가 호출된 후에도 반환된 값이 데이터에 대한 참조로 유지
	변수의 복사본을 반환하는 대신 , 원본 변수에 직접 접근할 수 있게 함
	```c++
	int& returnReference(int& x) { 
    return x;   
	}
	// int& returnReference(int& x)는 반환형과 매개변수 모두 참조 타입
	//return x;는 입력된 x를 반환합니다. 여기서 x는 참조 타입이므로, 반환된 x는 원본 변수를 참조
	```
	> 예제 코드
	```c++
	#include <iostream>

	int& returnReference(int& x) {
		return x;
	}

	int main() {
		int num = 10;
		int& ref = returnReference(num); // ref는 num을 참조

		std::cout << "Original value: " << num << std::endl; // 10 출력
		ref = 20; // ref를 통해 num의 값을 변경
		std::cout << "Modified value: " << num << std::endl; // 20 출력

		return 0;
	}
	```
- Name Space
	> 이름충돌을 방지하고 코드를 더 구조화된 방식으로 작성 할 수 있도록 도와주는 개념 

	> 장점 : 이름 충돌 방지 : 두개의 다른 라이브러리에서 같은 이름의 함수를 정의할 수 있음 

	> 단점 : 긴 이름 사용하게 됨 : 사용할 때마다 긴 이름을 작성해야 하는 경우가 있음 이 점은 가독성을 떨어뜨릴 수 있음
	```c++
	namespace MyNamespace {
    int value = 100;
    void display() {
        std::cout << "Namespace function" << std::endl;
    }
	}

	int main() {
		MyNamespace::display();
		std::cout << "Namespace value: " << MyNamespace::value << std::endl;
		return 0;
	}
	```
- 전역,지역변수
	> 전역 변수: 모든 함수에서 접근 가능하며, 프로그램 시작부터 종료까지 존재.
	
	> 지역 변수: 선언된 함수나 블록 내에서만 접근 가능하며, 해당 블록이 종료되면 소멸
	```c++
	int globalVar = 10; // 전역 변수

	int main() {
		int localVar = 20; // 지역 변수
		std::cout << "Global: " << globalVar << ", Local: " << localVar << std::endl;
		return 0;
	}
	```
- C에서 메모리 관리
	> 스택 : 지역 변수와 매개변수가 저장되는 영역.
	
	> HEAP : 사용자에게 동적으로 할당되는 메모리 영역. malloc()으로 할당받고, free()로 해제
		= Malloc() -> free()반환 = 사용을 할려면 Malloc으로 할당을 받는다
	
	> data 영역: 전역 변수, 정적 변수, 상수, 문자 리터럴이 저장되는 영역.
	
	- // A & B = 비트 And 연산자
	```c
	int A = 5; // 0101
	int B = 3; // 0011
	int result = A & B; // 0001
	// 둘다 참인값이여야 1을 출력하는데 A,B 둘다 0의 값이 아닌 1이기 때문에 둘다 참 즉 result 는 참
	```
	- // A && B = 논리 And 연산자 = 논리 곱
	> 논리 AND 연산자는 두 개의 논리 값을 받아 두 값이 모두 참일 경우에만 참을 반환하는 연산자

	> 논리 AND 연산자는 두 조건이 모두 참(true)일 때만 결과가 참이 됩니다. 하나라도 거짓(false)이면 결과는 거짓
	```c++
	#include <iostream>

	int main() {
		bool A = true;
		bool B = false;
		
		if (A && B) {
			std::cout << "Both A and B are true" << std::endl;
		} else {
			std::cout << "Either A or B is false" << std::endl;
		}
		return 0;
	}
	```

<p>C++ 프로그래밍에서 메모리 관리 및 접근 제어, 그리고 파일 분할에 대해 학습한 내용을 정리</p>

## 3일차
### C++ 파일 분할
- C++ 에서는 소스 파일과 헤더 파일을 분리하여 코드를 모듈화하고 재사용성을 높일 수 있음
	> 헤더파일(.h, .hpp) : 클래스의 선언과 함수 프로토타입을 포함
	
	> 소스 파일(.cpp) : 함수와 클래스 멤버의 구현을 포함 

	> ❗코드의 가독성과 유지보수성이 향상됨 헤더 파일에는 보호 매크로('#ifndef', '#define', '#endif') f를 사용하여 중복 포함을 방지 

### 메모리 관리 
- 동적 메모리 할당 및 해제 ( C 언어)
	> C 에서는 'malloc()' 과 'free()' 함수를 사용하여 동적 메모리를 할당하고 해제 

	> malloc(size_t size) : 지정한 크키(size)의 메모리를 할당
	
	> free(void* ptr) : malloc 으로 할당받은 메모리를 해제 
- - -
- 동적 메모리 할당 및 해제 ( C ++ 언어)

	> C++ 에서는 new와 delte를 사용

	> new : 객체나 배열을 동적으로 할당

	> delte : 'new'로 할당된 메모리를 해제

	> 힙(Heep) : 동적 메모리 할당 시 사용되는 메모리 영역 | 'malloc' 또는 ' new ' 를 통해 메모리가 할당되며 , 할당된 메모리는 'free' 또는 'delete' 로 해제해야 함

### 접근제어 지시자 
- C ++ 에서 클래스 멤버의 접근 권한을 지정하기 위해 사용되는 접근 제어 지시자 
	- 접근제어 지시자
		> Public : 공용 멤버 , 클래스 외부에서 접근 할 수 있음

		> Protected : 보호된 멤버로 , 클래스 자체와 이를 상속받은 파생 클래스에서만 접근 할 수 있음

		> Private : 비공개 멤버 , 클래스 내부에서만 접근할 수 있으며 , 파생 클래스에서도 접근할 수 없음
	
![접근제어 이미지](https://raw.githubusercontent.com/leekminxx/basic-cpp-2024/main/img/CPP01.PNG)

## 4일차
### 클래스(Class) 와 객체(Object)
- 클래스(Class)
	> 멤버변수와 멤버함수로 구성된다.

	> 클래스 내부에는 멤버들의 선언을 작성

	> 멤버함수의 정의를 외부로 뺌(Scope 연산자 사용)

	> 일반적으로 멤버변수 = Private, 멤버함수= Public의 접근제한을 사용

	> 생성자(기능:객체를 생성하고, 초기화)

- 객체(Object)
	> 클래스의 인스턴스이며 , 클래스에서 정의된 구조와 행동을 갖는 실체
	
	> 객체는 클래스의 설계도에 따라 생성된다

- 객체지향 프로그래밍
	- 객체지향 프로그래밍은 데이터를 객체로 취급하여 프로그래밍하는 방식
	> 캡슐화(Encapsulation) : 데이터와 메서드를 하나의 객체로 묶는 것.

	> 상속(Inheritance) : 기존 클래스의 특성을 새로운 클래스가 물려 받음

	> 다형성(Polymorphism) : 동일한 인터페이스를 통해 다른 기능을 수행

	> 추상화(Abstraction) : 복잡한 시스템에서 중요한 부분만을 모델링하는 것.

- 정보은닉
	> 클래스의 내부 상태를 숨기고 , 외부에서 접근할 수 없도록 제한

	> 보통 멤버 변수를 Private 으로 설정하여 외부에서 직접 접근하지 못하게 함

	> Public 멤버 함수를 통해서만 클래스의 데이터를 접근하고 수정할 수 있도록 함

- ❗생성자와 소멸자
	- 생성자
	> 객체가 생성될 때 호출되는 특수한 멤버 함수

	> 객체의 초기화를 담당

	> 클래스 이름과 동일하며 반환 타입이 없음

	- 소멸자 
	> 객체가 소멸될 때 호출되는 특수한 멤버 함수.

	> 객체가 사용하던 자원을 해제

	> 클래스 이름 앞에 '~' 기호가 붙으면서 반환 타입이 없음

	- 예시
	1. SimpleClass sc(20) 
	
	> 주어진 코드는 SimpleClass라는 클래스의 객체 sc를 생성. 
	
	> 이 객체는 생성자에 정수 값 20을 전달하여 초기화
		
	2. SimpleClass *ptr = new SimpleClass()
	> SimpleClass 클래스의 포인터를 생성하고, 동적으로 메모리를 할당하여 객체를 초기화.

	> 여기서 new 연산자는 힙(heap) 메모리에서 동적으로 객체를 생성하고, 해당 객체에 대한 포인터를 반환.

	> SimpleClass *ptr은 SimpleClass 타입을 가리키는 포인터를 선언.

	> new SimpleClass()는 SimpleClass의 기본 생성자를 호출하여 객체를 생성. 이후 반환된 포인터는 ptr에 할당.

	> 따라서 ptr은 힙 메모리에 동적으로 생성된 SimpleClass 객체를 가리키는 포인터

## 5일차
- 멤버 이니셜라이즈
	> 정의 : 객체 생성 전, 선언과 동시에 초기화가 필요한 경우에 사용

	> 용도 : const 변수와 참조 변수의 초기화에 사용
	
- 생성자(클래스 이름과 같은 멤버 함수로 출력x)
	> 특징

	>> 모든 클래스는 디폴트 생성자를 가지고 있음

	>> 멤버 변수를 초기화하는데 담당하고 

	>> 만약 명시적으로 생성자를 작성하면 디폴트 생성자의 호출 불가 -> 디폴트 생성자가 필요한 경우 명시적으로 작성
	
- 생성자 불일치
	> 매개변수가 void형으로 선언되는 디폴트 생성자
	
	> 특징
	>> 생성자가 하나도 정의되어 있지 않을때에만 자동으로 삽입이 됨!
	>> 명시적인 생성자가 존재하면 , 디폴트 생성자는 삽입되지 않음

- Private 생성자
	> 정의 : 생성자들은 모두 Public으로 선언

	>> 특징 : 객체 의 생성이 클래스의 외부에서 진행도기 때문에 생성자는 Public으로 선언

	>> 특정 상황에서는 생성자를 Private으로 선언하여 객체 생성을 제한할 수 있음.
	
- 소멸자 
	> 정의 : 객체가 소멸될 때 자동으로 호출되는 멤버 함수 , 클래스 이름 앞에 '~' 기호가 붙음

	> 특징 : 객체 소멸 시 자원을 해제하는 역할을 가짐

- 메모리 동적할당 
	> 정의 :  'new' 연산자 사용하여 프로그램 실행 중에 메모리를 할당
	```c++
	int* ptr = new int; // 정수형 메모리 할당
	int* arr = new int[10]; // 정수형 배열 메모리 할당
	```	

- 객체 배열
	```c++ 
	// 정적할당
	SoSimple arr[10];
	```

	```c++ 
	//동적으로 할당할 경우
	SoSimple *ptrArr = new SoSimple[10]
	```

> 포인터배열 : 포인터를 저장하는 배열

> 배열 포인터 : 배열을 가리키는 포인터

> 복사 생성자, 디폴트 생성자

## 6일차
- 깊은 복사와 얕은 복사
- 복사 생성자의 호출 시점
	1. 기존에 생성된 객체 => 새로운 객체를 초기화
	2. Call-By-Value 방식의 함수호출 과정에서 객체를 인자로 전달
	3. 객체를 반환 -> 참조형으로는 반환 X
	
- Return Object Dead Time

- friend

- static

- const
	1. 객체와 객체의 특성들
	2. 함수 오버 로딩
	3. 함수의 Friend 선언

- C++ 에서의 Static

## 7일차
```c++
Person class
	char *name; // 이름을 저장하는 동적 할당된 문자열 포인터
	int age; // 나이를 저장하는 정수

int main()
{
    Person p("Hong", 30); // "Hong" 문자열을 가지고 30이라는 나이로 Person 객체 생성
    p.personInfo(); // Person 객체의 정보 출력

    Person copyp(p); // p 객체를 복사하여 새로운 객체 copyp 생성
    copyp.personInfo(); // 복사된 객체 copyp의 정보 출력

    return 0;
}
	```
	
		- name 필드는 힙영역에 메모리를 할당하여 저장
		- 자기 객체를 생성하고 객체 복사를 하시오

- 상속(INHERITANCE)
	- 문법적 이해
	- 유도클래스의 객체생성 과정

- Protected 선언과 세가지 형태의 상속
	
## 8일차
-객체 포인터의 참조관계
	- 오버로딩(Overloading) - 다중정의
	-오버라이딩(Overriding) - 재정의 , 상속관계에서 사용
-가상함수 
	-함수의 오버라이딩과 포인터 형 
	-가상함수
	-순수 가상함수 와 추상클래스 
	-다형성 
-가상 소멸자와 참조자의 참조가능성
	-가상소멸자 
	-맴버함수와 가상함수의 동작원리

## 9일차 
-연산자 오버로딩
	- 멤버함수에 의한 연산자 오버로딩
	- 전역함수에 의한 연산자 오버로딩
	
-단항 연산자의 오버로딩
	-증가 감소 연산자의 오버로딩
	-전위증가와 후위증가의 구분
	-변환형에서의 const 선언과  const 객체 

-교환법칙 문제의 해결 
	-자료형이 다른 두 피연산자를 대상으로 하는 연산 
	-교환법칙의 성립을 위한 구현
-cout , cin endl 이해하고 정리하기 

## 10일차
-디폴트 대입 연산자 ( 문제점 해결)
	- 상속 구조에서의 대입 연산자 호출 
	- 배열요소에 접근할 때 사용하는 [] 연산자 오버로딩 
-배열의 인덱스 연산자 오버로딩
	-const 함수를 이용한 오버로딩의 활용 
	-객체 저장을 위한 배열 클래스의 정의 
-연산자 오버로딩 
	-new연산자 오버로딩에 대한 상세한 이해 
	-delete 연산자 오버로딩에 대한 상세한 이해
	-포인터 연산자 오버로딩
	-연산자의 오버로딩과 펑터 
	
## 11일차
	-임시객체로의 자동 형 변환 연산자
	
	-표준과 표준 string 클래스	
		-표준 string 클래스   
		
	-템플릿에 대한 이해와 함수 템플릿 
		-함수 템플릿과 템플릿 함수 
		-둘 이상의 형(Type) 에 대해 템플릿 선언하기 
		-함수 템플릿의 특수화 
		
## 12일차 
	-클래스 템플릿
		-클래스 템플릿 정의 
		-클래스 템플리의 정의의 분리 
		-파일을 나눌 때의 고려사항 알기 
		-배열 클래스의 템플릿화 
	-Point 클래스 템플릿과 배열 클래스 템플릿 

## 13일차
-예외처리 