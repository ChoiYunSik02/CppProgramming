# ch6-1장 실습과제 3 — Rectangle 클래스 (생성자 3개 중복)

---

## 📄 소스코드 (줄별 설명)

```cpp
#include <iostream>
```
> `cout` 등 입출력 기능을 사용하기 위한 헤더 파일을 포함한다.

```cpp
using namespace std;
```
> `std::cout` 처럼 매번 `std::`를 붙이지 않아도 되도록 선언한다.

---

```cpp
class Rectangle {
```
> `Rectangle` 클래스 선언 시작. 사각형을 표현하는 클래스다.

```cpp
private:
```
> 이하 멤버 변수들은 클래스 외부에서 직접 접근 불가 — **캡슐화** 원칙.

```cpp
    int width;
```
> 사각형의 **폭**을 저장하는 멤버 변수.

```cpp
    int height;
```
> 사각형의 **높이**를 저장하는 멤버 변수.

```cpp
public:
```
> 이하 멤버 함수(생성자, show)들은 클래스 외부에서 호출 가능.

```cpp
    Rectangle() { width = 1; height = 1; }
```
> **[생성자 1]** 매개변수 없는 기본 생성자.
> `Rectangle rect0;` 처럼 인자 없이 객체를 생성하면 호출된다.
> 폭과 높이를 모두 1로 초기화한다.

```cpp
    Rectangle(int a) { width = a; height = 1; }
```
> **[생성자 2]** 정수 1개를 받는 생성자.
> `Rectangle rect1(10);` 처럼 인자 1개로 객체를 생성하면 호출된다.
> 폭은 `a`로, 높이는 기본값 1로 초기화한다.

```cpp
    Rectangle(int a, int b) { width = a; height = b; }
```
> **[생성자 3]** 정수 2개를 받는 생성자.
> `Rectangle rect2(10, 20);` 처럼 인자 2개로 객체를 생성하면 호출된다.
> 폭은 `a`로, 높이는 `b`로 초기화한다.

```cpp
    void show();
```
> 멤버 함수 `show()`의 **선언**만 클래스 내부에 작성하고, 정의는 외부에서 한다.

```cpp
};
```
> `Rectangle` 클래스 선언 끝. 반드시 `;` 을 붙여야 한다.

---

```cpp
void Rectangle::show() {
```
> 클래스 **외부**에서 `show()` 함수를 정의한다.
> `Rectangle::` 은 이 함수가 `Rectangle` 클래스의 멤버임을 나타내는 **스코프 연산자(::)** 다.

```cpp
    cout << "사각형 폭은 " << width << " 높이는 " << height << endl;
```
> 멤버 변수 `width`와 `height` 값을 출력한다.
> `width`, `height`는 `private`이지만 멤버 함수 내부이므로 접근 가능하다.

```cpp
}
```
> `show()` 함수 끝.

---

```cpp
int main() {
```
> 프로그램 실행의 시작점.

```cpp
    Rectangle rect0;
```
> **생성자 1** 호출 — 인자가 없으므로 `Rectangle()`이 실행된다.
> `width=1`, `height=1`로 초기화된다.
> ⚠️ `Rectangle rect0();` 로 쓰면 **함수 선언**으로 해석되는 오류(Most Vexing Parse)가 발생하므로 괄호를 쓰지 않는다.

```cpp
    rect0.show();
```
> `rect0` 객체의 `show()`를 호출한다. → `사각형 폭은 1 높이는 1` 출력.

```cpp
    Rectangle rect1(10);
```
> **생성자 2** 호출 — 인자가 1개(10)이므로 `Rectangle(int a)`가 실행된다.
> `width=10`, `height=1`로 초기화된다.

```cpp
    rect1.show();
```
> `rect1` 객체의 `show()`를 호출한다. → `사각형 폭은 10 높이는 1` 출력.

```cpp
    Rectangle rect2(10, 20);
```
> **생성자 3** 호출 — 인자가 2개(10, 20)이므로 `Rectangle(int a, int b)`가 실행된다.
> `width=10`, `height=20`으로 초기화된다.

```cpp
    rect2.show();
```
> `rect2` 객체의 `show()`를 호출한다. → `사각형 폭은 10 높이는 20` 출력.

```cpp
    return 0;
```
> `main()` 함수가 정상 종료됨을 운영체제에 알린다.

```cpp
}
```
> `main()` 함수 끝.

---

## 📌 실행 결과
<img width="808" height="168" alt="image" src="https://github.com/user-attachments/assets/42d4521a-0025-4ad4-b977-62ee59fa2422" />


## 📝 핵심 정리

| 생성자 | 호출 형태 | width | height |
|--------|-----------|-------|--------|
| `Rectangle()` | `Rectangle rect0;` | 1 | 1 |
| `Rectangle(int a)` | `Rectangle rect1(10);` | 10 | 1 |
| `Rectangle(int a, int b)` | `Rectangle rect2(10, 20);` | 10 | 20 |

- 생성자도 **함수 중복(오버로딩)** 이 가능하다. 인자의 개수로 어느 생성자를 호출할지 결정된다.
- 멤버 함수를 클래스 외부에서 정의할 때는 반드시 `클래스명::함수명` 형식을 사용한다.
- 기본 생성자 호출 시 `객체명()` 가 아닌 `객체명` 으로 선언해야 한다.
