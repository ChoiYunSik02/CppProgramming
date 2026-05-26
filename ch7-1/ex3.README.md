# ch7-1장 실습과제 3번 - 소스코드 설명

---

## 문제 요약

- 실습과제 2번의 **전역 함수 `ComplexAdd()`** 를 **`ComplexManager` 클래스의 멤버 함수**로 옮긴다.
- `ComplexManager::ComplexAdd()`를 `Complex` 클래스의 **프렌드 멤버 함수**로 선언한다.
- `main()`에서 `man.ComplexAdd(x, y)` 형태로 호출되어야 한다.

---

## 소스 코드 줄별 설명

```cpp
#include <iostream>
using namespace std;
```
표준 입출력 헤더를 포함하고, `std::` 접두사를 생략할 수 있도록 네임스페이스를 선언한다.

---

```cpp
class Complex;
```
전방 선언(forward declaration)이다. `ComplexManager` 클래스가 `Complex`를 매개변수로 사용하는데, `Complex`가 아직 정의되지 않았으므로 컴파일러에게 이 타입이 존재한다는 것을 미리 알려줘 컴파일 오류를 방지한다.

---

```cpp
class ComplexManager {
public:
    Complex ComplexAdd(Complex x, Complex y);
};
```
복소수 연산을 전담하는 매니저 클래스이다. `ComplexAdd` 멤버 함수를 선언만 해둔다. 실제 구현은 `Complex` 클래스가 완전히 정의된 이후에 작성해야 `private` 멤버에 접근할 수 있다.

---

```cpp
class Complex {
    int real;
    int img;
```
복소수 클래스를 선언한다. 실수부(`real`)와 허수부(`img`)는 `private` 멤버로, 외부에서 직접 접근할 수 없다.

---

```cpp
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img  = img;
        cout << "복소수 " << real << "+ " << img << "j 생성" << endl;
    }
```
생성자이다. 매개변수로 받은 값을 멤버 변수에 저장하고 생성 메시지를 출력한다. 기본값 `0`으로 설정되어 있어 `Complex sum;`처럼 인자 없이도 생성이 가능하다.

---

```cpp
    void show() {
        cout << " " << real << "+" << img << "j" << endl;
    }
```
복소수를 `실수부+허수부j` 형식으로 콘솔에 출력하는 멤버 함수이다.

---

```cpp
    friend Complex ComplexManager::ComplexAdd(Complex x, Complex y);
```
`ComplexManager` 클래스의 멤버 함수 `ComplexAdd` 하나만 선택적으로 프렌드로 선언한다. 클래스 전체가 아닌 특정 함수 하나에만 `private` 접근 권한을 부여해 캡슐화를 최대한 유지한다.

---

```cpp
Complex ComplexManager::ComplexAdd(Complex x, Complex y) {
    Complex result;
```
`ComplexManager`의 멤버 함수 구현부이다. `Complex` 클래스가 완전히 선언된 이후에 작성해야 하므로 클래스 선언 바깥에 위치한다. 기본 생성자로 `result`를 먼저 만들며, 이때 `"복소수 0+ 0j 생성"`이 출력된다 (4번째 줄).

```cpp
    result.real = x.real + y.real;
    result.img  = x.img  + y.img;
```
두 복소수의 실수부끼리, 허수부끼리 각각 더해 `result`에 대입한다. 프렌드 멤버 함수이므로 `private` 멤버에 직접 접근이 가능하다.

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
복소수 `2+3j` 객체를 생성한다. `"복소수 2+ 3j 생성"`이 출력된다 (1번째 줄).

```cpp
    Complex y(-5, 10);
```
복소수 `-5+10j` 객체를 생성한다. `"복소수 -5+ 10j 생성"`이 출력된다 (2번째 줄).

```cpp
    Complex sum;
```
합산 결과를 담을 객체를 기본 생성자로 생성한다. `"복소수 0+ 0j 생성"`이 출력된다 (3번째 줄).

```cpp
    ComplexManager man;
```
복소수 연산을 수행할 `ComplexManager` 객체를 생성한다.

```cpp
    sum = man.ComplexAdd(x, y);
```
`man` 객체의 멤버 함수 `ComplexAdd`를 호출한다. 내부에서 `result(0+0j)`가 생성되며 4번째 줄이 출력되고, 계산된 `-3+13j`가 `sum`에 대입된다.

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
<img width="820" height="209" alt="image" src="https://github.com/user-attachments/assets/d6f19255-50a5-42d3-84a2-cfcbcbf88b16" />


---

## 과제 2번과의 비교

| 항목 | 과제 2번 | 과제 3번 |
|------|----------|----------|
| `ComplexAdd` 위치 | 전역 함수 | `ComplexManager` 클래스 멤버 함수 |
| 프렌드 선언 형태 | `friend Complex ComplexAdd(...)` | `friend Complex ComplexManager::ComplexAdd(...)` |
| 호출 방법 | `ComplexAdd(x, y)` | `man.ComplexAdd(x, y)` |
| 전방 선언 필요 | 불필요 | `class Complex;` 필요 |
