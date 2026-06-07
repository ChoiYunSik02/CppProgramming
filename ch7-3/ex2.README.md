# ch7-3 실습과제2 – 프렌드 함수로 구현한 ++ 연산자 중복

`Complex` 클래스에 전위 `++`, 후위 `--` 연산자를 **프렌드 함수**로 작성

---

## 전체 코드 및 설명

```cpp
#include <iostream>
using namespace std;
```
> 표준 입출력 헤더를 포함하고, `std::` 접두사 없이 사용하도록 선언한다.

```cpp
class Complex {
	int real;
	int img;
```
> 복소수 클래스 선언. 실수부 `real`과 허수부 `img`를 `private` 멤버로 갖는다.

```cpp
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;
		this->img = img;
		cout << "복소수 " << real << " - " << -img << "j" << " 생성" << endl;
	}
```
> 생성자. 매개변수를 멤버 변수에 대입하고 복소수 형태로 생성 메시지를 출력한다.

```cpp
	void show();
```
> 복소수를 출력하는 멤버 함수를 선언한다.

```cpp
	friend Complex& operator++(Complex& op);
```
> 전위 `++` 연산자를 프렌드 함수로 선언한다. `friend` 키워드를 붙이면 클래스 외부의 전역 함수가 `private` 멤버인 `real`, `img`에 접근할 수 있다.

```cpp
	friend Complex operator--(Complex& op, int x);
```
> 후위 `--` 연산자를 프렌드 함수로 선언한다. `int x` 더미 매개변수가 있는 것이 후위 연산자의 특징이다.

```cpp
};
```
> 클래스 선언 종료.

---

```cpp
void Complex::show() {
	cout << real << " - " << -img << "j" << endl;
}
```
> 복소수를 `실수 - 허수j` 형식으로 출력한다. `-img`로 내부에 음수로 저장된 허수부를 양수로 변환해 출력한다.

---

```cpp
Complex& operator++(Complex& op) {
```
> 전위 `++` 프렌드 연산자 함수 정의. `++x`는 컴파일러가 `operator++(x)`로 변환한다. 피연산자를 참조(`&`)로 받아야 원본이 수정된다.

```cpp
	op.real++;
	op.img++;
```
> 피연산자 객체의 실수부와 허수부를 각각 1씩 증가시킨다. 멤버 함수가 아닌 외부 함수지만 `friend` 선언 덕분에 `private` 멤버에 접근 가능하다.

```cpp
	return op;
```
> 변경된 객체의 참조를 리턴한다.

```cpp
}
```

---

```cpp
Complex operator--(Complex& op, int x) {
```
> 후위 `--` 프렌드 연산자 함수 정의. `x--`는 컴파일러가 `operator--(x, 0)`으로 변환한다. 첫 번째 매개변수를 참조(`&`)로 받아야 원본이 수정된다.

```cpp
	Complex tmp = op;
```
> 감소시키기 이전의 객체 상태를 `tmp`에 복사해서 보관한다.

```cpp
	op.real--;
	op.img--;
```
> 원본 객체의 실수부와 허수부를 각각 1씩 감소시킨다.

```cpp
	return tmp;
```
> 감소하기 이전 상태인 `tmp`를 값으로 리턴한다.

```cpp
}
```

---

```cpp
int main() {
	Complex x(2, -3);
```
> `real=2`, `img=-3`인 복소수 객체 `x`를 생성한다. 생성자에서 `복소수 2 - 3j 생성`이 출력된다.

```cpp
	++x;
```
> 전위 `++` 연산자 호출. `operator++(x)`로 변환되어 `real: 2→3`, `img: -3→-2`로 변경된다.

```cpp
	cout << "증가결과";
	x.show();
```
> `증가결과` 출력 후 `show()`로 `3 - 2j`를 출력한다.

```cpp
	x--;
```
> 후위 `--` 연산자 호출. `operator--(x, 0)`으로 변환되어 `real: 3→2`, `img: -2→-3`으로 변경된다.

```cpp
	cout << "감소결과";
	x.show();
```
> `감소결과` 출력 후 변경된 `x`를 출력한다. `2 - 3j`가 출력된다.

```cpp
	return 0;
}
```
> 프로그램을 정상 종료한다.

---

## 실행 결과
<img width="824" height="181" alt="image" src="https://github.com/user-attachments/assets/96e3663e-064b-4b28-aa9b-0f0a6b714fe6" />

