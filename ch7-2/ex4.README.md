# ch7-2 실습과제 4번 — 복소수와 정수 뺄셈 연산자 (`-`) 중복 설명

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
> 기본값 0인 생성자. `b`처럼 인자 없이 생성하면 `(0, 0)` 으로 초기화됨

```cpp
    Complex operator-(int op2);
```
> 오른쪽 피연산자가 `int` 형인 `-` 연산자 선언
> `b = a - 2` 는 `b = a.operator-(2)` 로 컴파일러가 변환하여 호출

```cpp
void Complex::show() {
    cout << real << "+" << img << "j" << endl;
}
```
> 복소수를 `실수부+허수부j` 형식으로 출력

```cpp
Complex Complex::operator-(int op2) {
```
> `-` 연산자 함수 정의 시작. 왼쪽은 `Complex`(`this`), 오른쪽은 `int`(`op2`)

```cpp
    Complex tmp;
```
> 결과를 담을 임시 객체 생성 (`(0,0)` 으로 초기화)

```cpp
    tmp.real = this->real - op2;
```
> 실수부에서 정수를 뺌
> `a(3,5) - 2` → `real = 3 - 2 = 1`

```cpp
    tmp.img  = this->img  - op2;
```
> 허수부에서도 동일하게 정수를 뺌
> `img = 5 - 2 = 3`

```cpp
    return tmp;
```
> 결과를 새 임시 객체로 반환. 원본 `a` 는 변경되지 않음

```cpp
    Complex a(3, 5), b;
```
> `a = (3+5j)`, `b = (0+0j)` 객체 생성

```cpp
    a.show();
    b.show();
```
> 연산 전 `3+5j`, `0+0j` 출력

```cpp
    b = a - 2;
```
> `a.operator-(2)` 호출 → `b = (1+3j)` 대입. `a` 는 `(3+5j)` 그대로 유지

```cpp
    a.show();
    b.show();
```
> 연산 후 `a` 는 변경 없이 `3+5j`, `b` 는 `1+3j` 출력

---

## 실행 결과
<img width="822" height="187" alt="image" src="https://github.com/user-attachments/assets/9adffb74-4333-4e0e-ad8d-c6eca3982f9a" />


## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| 이종 타입 연산자 중복 | 피연산자 타입이 `Complex` 와 `int` 로 서로 다를 때도 중복 가능 |
| 매개변수 타입 | 오른쪽 피연산자 타입에 맞춰 `int op2` 로 선언 |
| 원본 불변 | `+`, `-` 는 새 객체를 반환하므로 원본 `a` 가 바뀌지 않음 |
