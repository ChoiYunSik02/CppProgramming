# ch7-2 실습과제 1 — 복소수 덧셈 연산자 (`+`) 중복 설명

---

## 줄별 코드 설명

```cpp
class Complex {
```
> 실수부와 허수부를 갖는 복소수를 표현하는 클래스 선언

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
```
> 기본값이 0인 생성자 선언. 인자 없이 생성하면 `(0, 0)` 으로 초기화됨

```cpp
        this->real = real;
        this->img = img;
```
> `this->` 로 멤버변수와 매개변수 이름 충돌 해결 후 초기화

```cpp
    Complex operator+(Complex op2);
```
> `+` 연산자 함수 선언. 오른쪽 피연산자를 `op2`로 받고 새 `Complex` 객체를 반환

```cpp
void Complex::show() {
    cout << " " << real << "+" << img << "j" << endl;
}
```
> 복소수를 `실수부+허수부j` 형식으로 출력하는 멤버함수

```cpp
Complex Complex::operator+(Complex op2) {
```
> `+` 연산자 함수 정의. `x + y` 는 `x.operator+(y)` 로 컴파일러가 변환하여 호출

```cpp
    Complex tmp;
```
> 연산 결과를 담을 임시 객체 생성. 기본 생성자에 의해 `(0, 0)` 으로 초기화됨

```cpp
    tmp.real = this->real + op2.real;
```
> 왼쪽 피연산자(`this`)의 실수부와 오른쪽 피연산자(`op2`)의 실수부를 더해 저장
> `x(2,3) + y(-5,10)` → `2 + (-5) = -3`

```cpp
    tmp.img  = this->img  + op2.img;
```
> 마찬가지로 허수부끼리 더해 저장
> `3 + 10 = 13`

```cpp
    return tmp;
```
> 계산 결과 임시 객체를 반환. 원본 `x`, `y` 는 변경되지 않음

```cpp
    Complex x(2, 3), y(-5, 10), sum;
```
> `x = (2+3j)`, `y = (-5+10j)`, `sum = (0+0j)` 객체 생성

```cpp
    sum = x + y;
```
> `x.operator+(y)` 호출 → `sum = (-3+13j)` 대입

```cpp
    cout << "두 복소수의 합은";
    sum.show();
```
> 결과 출력. `show()` 가 `" -3+13j"` 를 이어서 출력

---

## 실행 결과
<img width="819" height="135" alt="image" src="https://github.com/user-attachments/assets/bbedd8a9-5d1f-4f7a-8543-fc7b4f36a0b6" />


## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| 연산자 중복 | 기존 연산자를 사용자 정의 클래스에 맞게 재정의 |
| `a + b` → `a.operator+(b)` | 컴파일러가 객체 연산을 멤버함수 호출로 변환 |
| 반환 타입 `Complex` | 새 임시 객체 반환, 원본 불변 |
