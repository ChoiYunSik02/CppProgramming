# ch7-1장 실습과제 1번 정리

---

## 1. 프렌드 함수(friend function)가 왜 필요한가?

### 핵심 개념

C++는 **캡슐화(encapsulation)** 원칙에 따라 클래스의 `private` 멤버는 해당 클래스의 멤버 함수만 접근할 수 있다.  
그런데 **클래스의 멤버 함수로 만들기에는 적합하지 않지만**, 클래스의 `private` 멤버에 자유롭게 접근해야 하는 경우가 생긴다.

이런 상황을 해결하기 위해 C++은 `friend` 키워드로 선언된 **프렌드 함수** 개념을 제공한다.

---

### 프렌드 함수가 필요한 이유 (3가지)

#### ① 외부 함수(전역 함수)에서 private 멤버 접근이 필요할 때

```cpp
class Rect {
    int width, height; // private 멤버
public:
    Rect(int w, int h) : width(w), height(h) {}
    friend bool equals(Rect r, Rect s); // 전역 함수를 프렌드로 선언
};

bool equals(Rect r, Rect s) {
    // 프렌드 함수이므로 private 멤버 width, height에 접근 가능
    return (r.width == s.width && r.height == s.height);
}
```

→ `equals()`는 `Rect`의 멤버 함수가 아니지만, `private` 멤버인 `width`, `height`에 접근할 수 있다.

---

#### ② 다른 클래스의 멤버 함수에서 접근이 필요할 때

두 클래스가 서로 긴밀하게 협력해야 할 때, 한 클래스의 멤버 함수를 다른 클래스의 프렌드로 선언하면 된다.

```cpp
class RectManager {
public:
    bool equals(Rect r, Rect s); // Rect의 프렌드로 선언될 함수
};

class Rect {
    int width, height;
public:
    friend bool RectManager::equals(Rect r, Rect s); // 특정 멤버함수만 프렌드 선언
};
```

---

#### ③ 연산자 중복(operator overloading) 구현 시

연산자 함수는 특성상 **클래스 멤버 함수로 정의하기 어려운 경우**가 있다.  
예를 들어 `2 + 객체`처럼 왼쪽 피연산자가 기본 타입(int)인 경우, 멤버 함수로는 구현 불가능하므로 프렌드 함수로 구현해야 한다.

```cpp
class Color {
    int r, g, b;
public:
    friend Color operator+(Color op1, Color op2); // 연산자 함수를 프렌드로 선언
};
```

---

### 요약

| 구분 | 일반 외부 함수 | 프렌드 함수 |
|------|--------------|------------|
| 클래스 멤버 여부 | ❌ 아님 | ❌ 아님 |
| private 접근 | ❌ 불가 | ✅ 가능 |
| 선언 위치 | 클래스 외부 | 클래스 내부에 `friend` 키워드로 선언 |
| 용도 | 일반 전역 함수 | 연산자 함수, 클래스 간 협력 함수 등 |

> **결론:** 프렌드 함수는 캡슐화를 최소한으로 허용하면서, 꼭 필요한 외부 함수에게만 선택적으로 private 접근 권한을 주기 위해 필요하다.

---

## 2. 다형성(Polymorphism)의 의미와 종류

### 다형성이란?

**다형성(Polymorphism)** 이란 "하나의 이름(인터페이스)으로 여러 가지 형태의 동작을 수행할 수 있는 성질"을 말한다.  
객체지향 프로그래밍(OOP)의 4대 특성(캡슐화, 상속, 추상화, **다형성**) 중 하나이다.

쉽게 말하면: **같은 이름의 함수나 연산자가 상황에 따라 다르게 동작**하는 것이다.

---

### 다형성의 종류

#### ① 함수 중복 (Function Overloading) — 컴파일 타임 다형성

같은 이름의 함수를 **매개변수의 타입이나 개수**를 다르게 하여 여러 개 정의하는 것.

```cpp
void print(int x)    { cout << "정수: " << x; }
void print(double x) { cout << "실수: " << x; }
void print(string x) { cout << "문자열: " << x; }

print(10);       // → 정수: 10
print(3.14);     // → 실수: 3.14
print("hello");  // → 문자열: hello
```

→ **컴파일 시점**에 어떤 함수를 호출할지 결정된다 (정적 바인딩).

---

#### ② 연산자 중복 (Operator Overloading) — 컴파일 타임 다형성

기존 연산자(`+`, `-`, `==` 등)를 **사용자 정의 타입(클래스)에 맞게 재정의**하는 것.

```cpp
int a = 2, b = 3;
c = a + b;         // 정수 덧셈 → 5

string s1 = "C", s2 = "++";
c = s1 + s2;       // 문자열 연결 → "C++"

Color x(BLUE), y(RED);
z = x + y;        // 색 혼합 → VIOLET (사용자 정의)
```

→ 같은 `+` 연산자가 피연산자 타입에 따라 다르게 동작한다.

---

#### ③ 가상 함수 / 런타임 다형성 (Virtual Function) — 실행 타임 다형성

부모 클래스의 포인터로 자식 클래스의 객체를 가리킬 때, **실제 객체의 타입에 따라 다른 함수가 호출**되는 것.

```cpp
class Animal {
public:
    virtual void speak() { cout << "..."; }
};
class Dog : public Animal {
public:
    void speak() override { cout << "멍멍!"; }
};
class Cat : public Animal {
public:
    void speak() override { cout << "야옹!"; }
};

Animal* a = new Dog();
a->speak(); // → 멍멍! (런타임에 Dog::speak 호출)
```

→ **실행 시점**에 어떤 함수를 호출할지 결정된다 (동적 바인딩).

---

### 다형성 종류 요약

| 종류 | 결정 시점 | C++ 구현 방법 |
|------|----------|--------------|
| 함수 중복 | 컴파일 타임 | Function Overloading |
| 연산자 중복 | 컴파일 타임 | Operator Overloading |
| 런타임 다형성 | 실행 타임 | virtual 함수 + 상속 |

> **결론:** 다형성은 코드의 **재사용성과 확장성**을 높이는 객체지향의 핵심 특성이며,  
> C++에서는 함수 중복, 연산자 중복, 가상 함수를 통해 구현된다.
