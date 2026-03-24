# 실습과제3 - Triangle 클래스 구현 (private 멤버 변수, setter/getter, 소멸자)

---

## 소스 코드 설명

```cpp
// **********************************************
// 제 목 : 3-4장 실습과제 3번
// 날 짜 : 2026년 03월 24일
// 작성자 : 2101091 최윤식
// **********************************************
```
소스 파일의 제목, 작성 날짜, 작성자 정보를 나타내는 주석 헤더이다.

---

```cpp
#include <iostream>
using namespace std;
```
`iostream` 헤더 파일을 포함하여 표준 입출력 기능을 사용할 수 있도록 한다.  
`std` 네임스페이스를 전역으로 선언하여 `cout`, `endl` 등을 접두사 없이 사용한다.

---

```cpp
class Triangle {
```
`Triangle`이라는 이름의 클래스를 선언한다.

---

```cpp
private:
    int width;  // 밑변
    int height; // 높이
```
삼각형의 밑변과 높이를 저장하는 멤버 변수 `width`, `height`를 `private`으로 선언한다.  
`private` 선언으로 외부에서 직접 접근이 불가능하며, setter/getter 함수를 통해서만 접근할 수 있다.  
이는 객체지향의 **정보 은닉(Information Hiding)** 원칙을 따른 것이다.

---

```cpp
public:
    Triangle();
    Triangle(int a, int b);
    ~Triangle();
    void setWidth(int a);
    void setHeight(int b);
    int getWidth();
    int getHeight();
    double getArea();
```
외부에서 접근 가능한 `public` 멤버들을 선언한다.  
생성자 2개, 소멸자 1개, setter 함수 2개, getter 함수 2개, 면적 계산 함수 1개로 구성된다.  
생성자와 멤버 함수는 외부에서 호출되므로 반드시 `public`으로 선언해야 한다.

---

```cpp
Triangle::Triangle() : Triangle(1, 1) { } // 위임 생성자
```
매개변수가 없는 기본 생성자이다.  
`: Triangle(1, 1)` 문법을 사용하여 매개변수가 있는 생성자에게 초기화를 **위임**한다.  
`width = 1`, `height = 1`로 초기화되며, 객체 생성 메시지 출력도 타겟 생성자에서 처리된다.  
이처럼 한 생성자가 다른 생성자를 호출하는 방식을 **위임 생성자(Delegating Constructor)** 라고 한다.

---

```cpp
Triangle::Triangle(int a, int b) : width(a), height(b) { // 타켓 생성자
    cout << "폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
}
```
매개변수 `a`, `b`를 받아 멤버 변수를 초기화하는 생성자이다.  
`: width(a), height(b)` 는 **멤버 초기화 리스트(Member Initializer List)** 문법으로, 생성자 본문 실행 전에 멤버 변수를 초기화한다.  
위임 생성자로부터 호출되는 **타겟 생성자**이며, 실질적인 초기화와 생성 메시지 출력을 담당한다.

---

```cpp
Triangle::~Triangle() { // 소멸자
    cout << "폭" << width << ", " << "높이" << height << " 삼각형 소멸" << endl;
}
```
객체가 메모리에서 해제될 때 자동으로 호출되는 **소멸자(Destructor)** 이다.  
`~Triangle()` 처럼 클래스 이름 앞에 `~`를 붙여 선언한다.  
객체가 소멸되는 시점의 `width`, `height` 값을 출력하여 소멸 사실을 알린다.  
소멸자는 직접 호출하지 않아도 객체의 수명이 끝나는 시점에 컴파일러가 자동으로 호출한다.

---

```cpp
void Triangle::setWidth(int a) { width = a; }  // 밑변변수의 값 쓰기
void Triangle::setHeight(int b) { height = b; } // 높이변수의 값 쓰기
```
`private` 멤버 변수 `width`와 `height`에 새로운 값을 저장하는 **setter 함수**이다.  
객체 생성 이후 외부에서 멤버 변수의 값을 변경할 때 사용한다.

---

```cpp
int Triangle::getWidth() { return width; }   // 밑변변수의 값 읽기
int Triangle::getHeight() { return height; } // 높이변수의 값 읽기
```
`private` 멤버 변수 `width`와 `height`의 현재 값을 반환하는 **getter 함수**이다.  
외부에서 멤버 변수를 직접 참조하지 않고 함수를 통해 간접적으로 읽도록 한다.

---

```cpp
double Triangle::getArea() {
    return (1.0 / 2.0) * width * height;
}
```
삼각형의 넓이를 계산하여 반환하는 함수이다.  
삼각형 넓이 공식 `(밑변 × 높이) / 2`를 적용한다.  
`1.0 / 2.0`으로 실수 나눗셈을 수행하여 결과가 `double` 타입으로 반환된다.

---

```cpp
Triangle tri;
```
매개변수 없는 기본 생성자(위임 생성자)를 호출하여 `tri` 객체를 생성한다.  
내부적으로 타겟 생성자 `Triangle(1, 1)`이 호출되어 `width = 1`, `height = 1`로 초기화되고 생성 메시지가 출력된다.

---

```cpp
tri.setWidth(3);
tri.setHeight(5);
```
setter 함수를 통해 `tri` 객체의 `width`를 `3`, `height`를 `5`로 변경한다.  
`private` 멤버 변수에 직접 접근하지 않고 함수를 통해 값을 설정하는 올바른 방식이다.

---

```cpp
cout << "삼각형의 폭은 " << tri.getWidth() << endl;
cout << "삼각형의 높이는 " << tri.getHeight() << endl;
cout << "삼각형의 면적은 " << tri.getArea() << endl;
```
getter 함수로 `width`, `height` 값을 읽어 출력하고, `getArea()`로 계산된 면적을 출력한다.

---

```cpp
return 0;
```
`main` 함수가 정상 종료되었음을 운영체제에 알린다.  
`return 0` 직후 스택에 쌓인 지역 객체 `tri`의 소멸자가 자동으로 호출된다.

---

## 실행 결과

```
폭1, 높이1 삼각형 생성
삼각형의 폭은 3
삼각형의 높이는 5
삼각형의 면적은 7.5
폭3, 높이5 삼각형 소멸
```

---

## 핵심 개념 정리

| 개념 | 설명 |
|---|---|
| `private` 멤버 변수 | 외부 직접 접근 차단, 정보 은닉 구현 |
| 위임 생성자 | 기본 생성자가 타겟 생성자를 호출하여 초기화를 위임 |
| 멤버 초기화 리스트 | `: width(a), height(b)` 문법으로 생성자 본문 실행 전 멤버 변수 초기화 |
| 소멸자 | 객체 수명 종료 시 자동 호출, `~클래스이름()` 형태로 선언 |
| setter 함수 | 객체 생성 후 멤버 변수 값을 변경하는 함수 |
| getter 함수 | `private` 멤버 변수의 값을 외부에서 읽기 위한 함수 |
