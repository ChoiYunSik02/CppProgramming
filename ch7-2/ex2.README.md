# ch7-2 실습과제 2번 — 복소수 곱셈 연산자 (`*`) 중복 설명

---

## 복소수 곱셈 공식

```
(a + bj)(c + dj)
= ac + adj + bcj + bdj²      (j² = -1)
= (ac - bd) + (ad + bc)j
```

---

## 줄별 코드 설명

```cpp
class Complex {
```
> 실수부와 허수부를 갖는 복소수 클래스 선언

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
    Complex operator*(Complex op2);
```
> `*` 연산자 함수 선언. `x * y` 는 `x.operator*(y)` 로 변환되어 호출됨

```cpp
void Complex::show() {
    cout << " " << real << "+" << img << "j" << endl;
}
```
> 복소수를 `실수부+허수부j` 형식으로 출력

```cpp
Complex Complex::operator*(Complex op2) {
```
> `*` 연산자 함수 정의 시작. `this` = 왼쪽 피연산자, `op2` = 오른쪽 피연산자

```cpp
    Complex tmp;
```
> 결과를 담을 임시 객체 생성 (`(0,0)` 으로 초기화)

```cpp
    tmp.real = this->real * op2.real - this->img * op2.img;
```
> 복소수 곱셈 공식의 실수부: `ac - bd`
> `x(2,3) * y(-5,10)` → `2*(-5) - 3*10 = -10 - 30 = -40`

```cpp
    tmp.img  = this->real * op2.img  + this->img * op2.real;
```
> 복소수 곱셈 공식의 허수부: `ad + bc`
> `2*10 + 3*(-5) = 20 - 15 = 5`

```cpp
    return tmp;
```
> 계산된 결과 객체 반환. 원본 `x`, `y` 는 변경 없음

```cpp
    Complex x(2, 3), y(-5, 10), sum;
```
> `x = (2+3j)`, `y = (-5+10j)`, `sum = (0+0j)` 객체 생성

```cpp
    sum = x * y;
```
> `x.operator*(y)` 호출 → `sum = (-40+5j)` 대입

```cpp
    cout << "두 복소수의 곱은";
    sum.show();
```
> 결과 출력

---

## 실행 결과
<img width="816" height="138" alt="image" src="https://github.com/user-attachments/assets/871814d4-9d25-4d01-a0e7-90a9acd6cb9e" />


## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| 복소수 곱셈 공식 | `(ac-bd) + (ad+bc)j` |
| `j² = -1` | 허수 단위의 핵심 성질, 실수부 부호 반전 주의 |
| `operator*` | `a * b` → `a.operator*(b)` 로 컴파일러 변환 |
