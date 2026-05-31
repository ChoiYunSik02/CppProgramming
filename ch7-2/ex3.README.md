# ch7-2 실습과제 3번 — 복소수 복합 대입 연산자 (`+=`) 중복 설명

---

## 줄별 코드 설명

```cpp
class Complex {
```
> 복소수를 표현하는 클래스 선언

```cpp
    int real;
```
> 복소수의 실수부를 저장하는 `private` 멤버변수

```cpp
    int img;
```
> 복소수의 허수부를 저장하는 `private` 멤버변수

```cpp
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img = img;
    }
```
> 기본값 0인 생성자. `this->` 로 멤버변수와 매개변수 이름 충돌 해결

```cpp
    Complex& operator+=(Complex op2);
```
> `+=` 연산자 함수 선언. 반환 타입이 `Complex&` (참조형) 인 점이 `+` 와의 핵심 차이

```cpp
void Complex::show() {
    cout << real << "+" << img << "j" << endl;
}
```
> 복소수를 `실수부+허수부j` 형식으로 출력

```cpp
Complex& Complex::operator+=(Complex op2) {
```
> `+=` 연산자 함수 정의 시작. `b += a` 는 `b.operator+=(a)` 로 변환됨

```cpp
    this->real = this->real + op2.real;
```
> 임시 객체 없이 자기 자신(`this`)의 실수부를 직접 수정
> `b(1,1) += a(3,5)` → `real = 1 + 3 = 4`

```cpp
    this->img  = this->img  + op2.img;
```
> 자기 자신의 허수부도 직접 수정
> `img = 1 + 5 = 6`

```cpp
    return *this;
```
> 수정된 자기 자신을 참조로 반환
> 참조 반환이므로 `(b += a) += a` 처럼 연쇄 사용 가능

```cpp
    Complex a(3, 5), b(1, 1);
```
> `a = (3+5j)`, `b = (1+1j)` 객체 생성

```cpp
    a.show();
    b.show();
```
> 연산 전 `3+5j`, `1+1j` 출력

```cpp
    b += a;
```
> `b.operator+=(a)` 호출 → `b` 가 `(4+6j)` 로 변경됨. `a` 는 그대로 `(3+5j)`

```cpp
    a.show();
    b.show();
```
> 연산 후 `a` 는 변경 없이 `3+5j`, `b` 는 `4+6j` 출력

---

## 실행 결과
<img width="818" height="182" alt="image" src="https://github.com/user-attachments/assets/1a04cb5b-16d4-44ce-a98f-4645f4e1028e" />


## `+` vs `+=` 비교

| 항목 | `operator+` | `operator+=` |
|------|-------------|--------------|
| 원본 변경 | ❌ 변경 안 함 | ✅ 왼쪽 피연산자 직접 변경 |
| 반환 타입 | `Complex` (새 임시 객체) | `Complex&` (자기 자신 참조) |
| `*this` 사용 | ❌ | ✅ |

---

## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| `operator+=` | 왼쪽 피연산자 자신을 직접 수정하는 복합 대입 연산자 |
| 참조 반환 (`Complex&`) | `*this` 반환으로 연쇄 연산 지원 |
| `*this` | 현재 객체 자신을 역참조하여 반환 |
