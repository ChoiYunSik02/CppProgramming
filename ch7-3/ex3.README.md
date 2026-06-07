# ch7-3 실습과제3 – 프렌드로 구현한 곱셈(*) 연산자 중복

`Power` 클래스에 `int * Power` 연산자를 **프렌드 함수**로 작성

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
> 생성자. 매개변수와 멤버 변수 이름이 같으므로 `this->`로 구분하여 대입한다. 기본값이 0이므로 `Power()` 처럼 인자 없이도 호출 가능하다.

```cpp
	void show();
```
> `kick`, `punch`를 출력하는 멤버 함수를 선언한다. 정의는 클래스 외부에서 한다.

```cpp
	friend Power operator*(int op1, Power op2);
```
> `int * Power` 연산자를 프렌드 함수로 선언한다. `2 * a`처럼 왼쪽 피연산자가 `int`이면 `2.operator*(a)` 변환이 불가능하므로 멤버 함수로는 구현할 수 없다. `friend` 선언으로 외부 전역 함수가 `private` 멤버인 `kick`, `punch`에 접근할 수 있도록 허용한다.

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
Power operator*(int op1, Power op2) {
```
> `int * Power` 프렌드 연산자 함수 정의. `2 * a`는 컴파일러가 `operator*(2, a)`로 변환하여 호출한다.

```cpp
	Power tmp;
```
> 연산 결과를 담을 임시 객체를 생성한다. 기본 생성자에 의해 `kick=0, punch=0`으로 초기화된다.

```cpp
	tmp.kick = op1 * op2.kick;
	tmp.punch = op1 * op2.punch;
```
> 정수 `op1`에 `op2`의 `kick`, `punch`를 각각 곱해 임시 객체에 저장한다. `friend` 선언 덕분에 `private` 멤버에 직접 접근 가능하다.

```cpp
	return tmp;
}
```
> 결과가 담긴 임시 객체를 값으로 리턴한다. 원본 객체 `op2`는 변경되지 않는다.

---

```cpp
int main() {
	Power a(3, 5), b;
```
> `kick=3, punch=5`인 객체 `a`와 기본값 `kick=0, punch=0`인 객체 `b`를 생성한다.

```cpp
	a.show();
	b.show();
```
> `a`는 `kick=3,punch=5`, `b`는 `kick=0,punch=0`을 출력한다.

```cpp
	b = 2 * a;
```
> `operator*(2, a)`가 호출된다. `kick: 2×3=6`, `punch: 2×5=10` 결과가 `b`에 저장된다.

```cpp
	a.show();
	b.show();
```
> `a`는 변화 없이 `kick=3,punch=5`, `b`는 `kick=6,punch=10`을 출력한다.

```cpp
	return 0;
}
```
> 프로그램을 정상 종료한다.

---

## 실행 결과
<img width="826" height="202" alt="image" src="https://github.com/user-attachments/assets/4cbfbd99-34a7-4184-aaa1-1a4e0b3ca90a" />

