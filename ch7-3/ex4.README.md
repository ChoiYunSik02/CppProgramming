# ch7-3 실습과제4 – 프렌드로 구현한 곱셈(*)과 덧셈(+) 연산자 중복

 `Power` 클래스에 `int * Power`, `Power * int`, `Power + Power` 연산자를 모두 **프렌드 함수**로 작성

---

## 전체 코드 및 설명

```cpp
#include <iostream>
using namespace std;
```
> 표준 입출력 헤더를 포함하고, `std::` 접두사 없이 사용하도록 선언한다.

```cpp
class Power {
	int kick;
	int punch;
```
> `Power` 클래스 선언. `kick`과 `punch`를 `private` 멤버 변수로 갖는다.

```cpp
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
```
> 생성자. 기본값이 0이므로 `Power()` 처럼 인자 없이도 호출 가능하다.

```cpp
	void show();
```
> `kick`, `punch`를 출력하는 멤버 함수를 선언한다.

```cpp
	friend Power operator*(int n, Power op);
```
> `int * Power` 연산자를 프렌드 함수로 선언한다. `2 * b`처럼 왼쪽이 `int`이면 멤버 함수로 구현 불가능하므로 프렌드로 작성한다.

```cpp
	friend Power operator*(Power op, int n);
```
> `Power * int` 연산자를 프렌드 함수로 선언한다. `a * 2`처럼 왼쪽이 `Power`인 경우를 처리한다.

```cpp
	friend Power operator+(Power op1, Power op2);
```
> `Power + Power` 연산자를 프렌드 함수로 선언한다. 두 `Power` 객체의 덧셈을 처리한다.

```cpp
};
```
> 클래스 선언 종료.

---

```cpp
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
```
> `kick`과 `punch` 값을 `kick=X,punch=Y` 형식으로 출력한다.

---

```cpp
Power operator*(int n, Power op) {
```
> `int * Power` 프렌드 연산자 함수 정의. `2 * b`는 컴파일러가 `operator*(2, b)`로 변환하여 호출한다.

```cpp
	Power tmp;
	tmp.kick = n * op.kick;
	tmp.punch = n* op.punch;
	return tmp;
}
```
> 정수 `n`에 `op`의 `kick`, `punch`를 각각 곱한 새 임시 객체를 리턴한다.

---

```cpp
Power operator*(Power op, int n) {
```
> `Power * int` 프렌드 연산자 함수 정의. `a * 2`는 컴파일러가 `operator*(a, 2)`로 변환하여 호출한다.

```cpp
	Power tmp;
	tmp.kick = op.kick * n;
	tmp.punch = op.punch * n;
	return tmp;
}
```
> `op`의 `kick`, `punch`에 각각 정수 `n`을 곱한 새 임시 객체를 리턴한다.

---

```cpp
Power operator+(Power op1, Power op2) {
```
> `Power + Power` 프렌드 연산자 함수 정의. `① + ②`는 컴파일러가 `operator+(①, ②)`로 변환하여 호출한다.

```cpp
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}
```
> 두 객체의 `kick`, `punch`를 각각 더한 새 임시 객체를 리턴한다.

---

```cpp
int main() {
	Power a(1, 1), b(2, 2), c;
```
> `a(kick=1, punch=1)`, `b(kick=2, punch=2)`, `c(kick=0, punch=0)` 객체를 생성한다.

```cpp
	c.show();
```
> `c`의 초기값 `kick=0,punch=0`을 출력한다.

```cpp
	c = a * 2 + 2 * b;
```
> 연산자 우선순위(`*` > `+`)에 따라 아래 순서로 계산된다.
> - ① `a * 2` → `operator*(a, 2)` → `Power(2, 2)`
> - ② `2 * b` → `operator*(2, b)` → `Power(4, 4)`
> - ③ `① + ②` → `operator+(Power(2,2), Power(4,4))` → `Power(6, 6)`

```cpp
	c.show();
```
> 최종 결과 `kick=6,punch=6`을 출력한다.

```cpp
	return 0;
}
```
> 프로그램을 정상 종료한다.

---

## 실행 결과
<img width="818" height="159" alt="image" src="https://github.com/user-attachments/assets/5c818c28-ceb6-495e-8103-9296a55a4e22" />

