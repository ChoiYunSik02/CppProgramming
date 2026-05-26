# ch7-1장 실습과제 2번 - 소스코드 설명

---

## 문제 요약

- `실수부(real)`와 `허수부(img)`를 멤버 변수로 갖는 복소수 `Complex` 클래스를 구현한다.
- **생성자**, **`show()` 멤버 함수**, **전역 함수 `ComplexAdd()`** 를 작성한다.
- `ComplexAdd()`는 `Complex` 클래스의 **프렌드 함수**로 선언한다.

---

## 소스 코드 줄별 설명

```cpp
#include <iostream>
using namespace std;
```
표준 입출력 헤더를 포함하고, `std::` 접두사를 생략할 수 있도록 네임스페이스를 선언한다.

---

```cpp
class Complex {
```
복소수를 표현하는 클래스 선언을 시작한다.

```cpp
    int real;
    int img;
```
복소수의 실수부(`real`)와 허수부(`img`)를 저장하는 `private` 멤버 변수이다. 클래스 외부에서 직접 접근할 수 없다.

---

```cpp
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img  = img;
        cout << "복소수 " << real << "+ " << img << "j 생성" << endl;
    }
```
생성자이다. 매개변수로 받은 실수부와 허수부를 멤버 변수에 저장하고, 어떤 복소수가 생성되었는지 콘솔에 출력한다. 기본값을 `0`으로 설정해 인자 없이도 `Complex sum;` 형태로 생성이 가능하다.

---

```cpp
    void show() {
        cout << " " << real << "+" << img << "j" << endl;
    }
```
복소수를 `실수부+허수부j` 형식으로 콘솔에 출력하는 멤버 함수이다.

---

```cpp
    friend Complex ComplexAdd(Complex x, Complex y);
```
전역 함수 `ComplexAdd`를 프렌드로 선언한다. 이 선언 덕분에 `ComplexAdd`는 클래스 외부 함수임에도 `private` 멤버인 `real`과 `img`에 직접 접근할 수 있다.

---

```cpp
Complex ComplexAdd(Complex x, Complex y) {
    Complex result;
```
두 복소수를 더하는 전역 프렌드 함수이다. 먼저 기본 생성자로 `result` 객체를 만든다. 이때 `"복소수 0+ 0j 생성"`이 출력되며, 이것이 실행 결과의 네 번째 줄에 해당한다.

```cpp
    result.real = x.real + y.real;
    result.img  = x.img  + y.img;
```
두 복소수의 실수부끼리, 허수부끼리 각각 더해 `result`에 대입한다. 프렌드 함수이므로 `private` 멤버에 직접 접근이 가능하다.

```cpp
    return result;
}
```
합산이 완료된 `result` 객체를 반환한다.

---

```cpp
int main() {
    Complex x(2, 3);
```
복소수 `2+3j` 객체를 생성한다. 생성자가 호출되어 `"복소수 2+ 3j 생성"`이 출력된다 (1번째 줄).

```cpp
    Complex y(-5, 10);
```
복소수 `-5+10j` 객체를 생성한다. `"복소수 -5+ 10j 생성"`이 출력된다 (2번째 줄).

```cpp
    Complex sum;
```
합산 결과를 담을 객체를 기본 생성자로 생성한다. `"복소수 0+ 0j 생성"`이 출력된다 (3번째 줄).

```cpp
    sum = ComplexAdd(x, y);
```
`ComplexAdd`를 호출한다. 함수 내부에서 `result(0+0j)`가 생성되며 네 번째 줄이 출력되고, 계산된 `-3+13j`가 `sum`에 대입된다.

```cpp
    cout << "두 복소수의 합은";
    sum.show();
```
안내 문자열을 출력한 뒤, `sum.show()`로 최종 결과 `-3+13j`를 출력한다.

```cpp
    return 0;
}
```
프로그램을 정상 종료한다.

---

## 실행 결과
<img width="821" height="208" alt="image" src="https://github.com/user-attachments/assets/99037811-49b1-4d2a-8659-fcdcfbce3800" />


---

## 핵심 포인트 정리

| 요소 | 설명 |
|------|------|
| `Complex(int real=0, int img=0)` | 기본값 파라미터로 인자 없는 생성도 지원 |
| `friend Complex ComplexAdd(...)` | 전역 함수를 프렌드로 선언해 `private` 멤버 접근 허용 |
| `Complex result;` (기본 생성자) | `result`를 `0+0j`로 먼저 만든 뒤 값을 대입해야 4번째 줄이 올바르게 출력됨 |
| `show()` | 복소수를 `실수+허수j` 형태로 콘솔 출력 |
