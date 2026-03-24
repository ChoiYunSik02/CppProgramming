# 3-4장 실습과제2

---

## 소스 코드 설명

```cpp
// **********************************************
// 제 목 : 3-4장 실습과제 2번
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
class Circle {
```
`Circle`이라는 이름의 클래스를 선언한다.

---

```cpp
private:
    int radius; // 수정된 코드, private로 멤버 변수 보호
```
멤버 변수 `radius`를 `private`으로 선언한다.  
`private` 멤버는 클래스 외부에서 직접 접근이 불가능하며, 클래스 내부의 멤버 함수를 통해서만 접근할 수 있다.  
기존 코드에서 `public`으로 선언되어 있던 것을 `private`으로 수정하여 **정보 은닉(Information Hiding)** 원칙을 적용한 것이다.

---

```cpp
// int radius; // 기존 코드
```
수정 전 코드로, `radius`를 `public`으로 선언했던 방식이다.  
외부에서 `waffle.radius = 5`처럼 직접 접근이 가능하여 객체지향 원칙에 위배된다.

---

```cpp
public:
    Circle();
    Circle(int r);
    int getRadius();
```
`public` 접근 지정자 아래에 두 개의 생성자와 `getRadius()` 멤버 함수를 선언한다.  
생성자는 객체 생성 시 외부에서 호출되므로 반드시 `public`으로 선언해야 한다.  
`getRadius()`는 `private` 멤버 변수 `radius`의 값을 외부에서 읽을 수 있도록 제공하는 **getter 함수**이다.

---

```cpp
Circle::Circle() { radius = 1; } // 위임
```
매개변수가 없는 기본 생성자이다.  
객체 생성 시 인자를 전달하지 않으면 이 생성자가 호출되며, `radius`를 기본값 `1`로 초기화한다.  
주석에 명시된 것처럼 **위임 생성자**로, 기본 초기화 역할을 담당한다.

---

```cpp
Circle::Circle(int r) { radius = r; } // 타켓
```
정수형 매개변수 `r`을 받는 생성자이다.  
객체 생성 시 전달된 인자 값을 `radius`에 저장하여 초기화한다.  
주석에 명시된 것처럼 **타겟 생성자**로, 실질적인 초기화 로직을 포함한다.

---

```cpp
int Circle::getRadius() { return radius; } // 멤버 변수 값 읽기
```
멤버 변수 `radius`의 값을 반환하는 getter 함수이다.  
`private`으로 보호된 `radius`를 외부에서 간접적으로 읽을 수 있는 유일한 방법이다.

---

```cpp
Circle waffle1;
```
매개변수 없는 기본 생성자를 호출하여 `waffle1` 객체를 생성한다.  
`radius`는 기본값인 `1`로 초기화된다.

---

```cpp
Circle waffle2(5); // 생성자를 이용한 멤버변수 설정
```
정수 `5`를 인자로 전달하여 `waffle2` 객체를 생성한다.  
매개변수가 있는 생성자가 호출되어 `radius`가 `5`로 초기화된다.

---

```cpp
// waffle.radius = 5; // 기존코드, 멤버 변수 값 호출 에러
```
수정 전 코드로, 외부에서 `radius`에 직접 접근하던 방식이다.  
`radius`가 `private`으로 수정된 이후에는 컴파일 에러가 발생하므로 주석 처리하였다.

---

```cpp
cout << "원의 반지름은 " << waffle1.getRadius() << endl;
cout << "원의 반지름은 " << waffle2.getRadius() << endl;
```
각 객체의 `getRadius()` 함수를 호출하여 `radius` 값을 출력한다.  
`private` 멤버인 `radius`에 직접 접근하지 않고, getter 함수를 통해 간접적으로 접근하는 올바른 방식이다.

---

```cpp
return 0;
```
`main` 함수가 정상 종료되었음을 운영체제에 알린다.

---

## 실행 결과
<img width="820" height="147" alt="스크린샷 2026-03-24 222514" src="https://github.com/user-attachments/assets/32b90fb4-4329-4908-9850-3125a4b13940" />

