# ch07-4 실습과제1 - Complex 클래스 소스코드 설명(>> / << 연산자 중복)

---

```cpp
#include <iostream>
```
> 표준 입출력 라이브러리 포함. `cin`, `cout`, `istream`, `ostream` 사용을 위해 필요하다.

```cpp
using namespace std;
```
> `std::` 접두사 없이 표준 라이브러리를 사용할 수 있게 한다.

```cpp
class complex {
```
> 복소수를 표현하는 `complex` 클래스 선언 시작.

```cpp
    int real;
```
> 복소수의 실수부를 저장하는 `private` 멤버 변수.

```cpp
    int img;
```
> 복소수의 허수부를 저장하는 `private` 멤버 변수.

```cpp
public:
```
> 이 아래 멤버들은 클래스 외부에서 접근 가능하다.

```cpp
    complex() {
```
> 기본 생성자 정의 시작. 객체 생성 시 자동 호출된다.

```cpp
        this->real = 0;
```
> 멤버 변수 `real`을 0으로 초기화한다. 쓰레기값 방지를 위해 명시적으로 0 대입.

```cpp
        this->img = 0;
```
> 멤버 변수 `img`를 0으로 초기화한다.

```cpp
    }
```
> 기본 생성자 종료.

```cpp
    void show();
```
> 복소수를 출력하는 멤버 함수 선언. 클래스 외부에서 정의한다.

```cpp
    friend istream& operator>>(istream& op1, complex& op2);
```
> `>>` 연산자를 프렌드 함수로 선언한다. `private` 멤버(`real`, `img`)에 외부 함수가 접근할 수 있게 허용한다.

```cpp
    friend ostream& operator<<(ostream& op1, complex& op2);
```
> `<<` 연산자를 프렌드 함수로 선언한다. `cout << x` 형태로 사용 가능하게 한다.

```cpp
};
```
> 클래스 정의 종료.

---

```cpp
istream& operator>>(istream& op1, complex& op2) {
```
> `>>` 연산자 함수 정의. `op1`은 입력 스트림(`cin`), `op2`는 입력받을 `complex` 객체. `istream&` 반환으로 `cin >> x >> y` 연속 입력이 가능하다.

```cpp
    cout << "실수부:";
```
> 사용자에게 실수부 입력을 안내하는 메시지를 출력한다.

```cpp
    op1 >> op2.real;
```
> 입력 스트림에서 값을 읽어 `op2`의 `real`에 저장한다. `friend` 덕분에 `private` 멤버에 직접 접근 가능하다.

```cpp
    cout << "허수부:";
```
> 사용자에게 허수부 입력을 안내하는 메시지를 출력한다.

```cpp
    op1 >> op2.img;
```
> 입력 스트림에서 값을 읽어 `op2`의 `img`에 저장한다.

```cpp
    return op1;
```
> 입력 스트림(`cin`)을 참조로 반환한다. `cin >> x >> y` 연속 사용이 가능해진다.

```cpp
}
```
> `>>` 연산자 함수 종료.

---

```cpp
ostream& operator<<(ostream& op1, complex& op2) {
```
> `<<` 연산자 함수 정의. `op1`은 출력 스트림(`cout`), `op2`는 출력할 `complex` 객체. `ostream&` 반환으로 `cout << x << y` 연속 출력이 가능하다.

```cpp
    op1 << op2.real;
```
> 실수부를 출력 스트림에 삽입한다.

```cpp
    if (op2.img < 0)
```
> 허수부가 음수인지 확인한다. 음수이면 `-` 부호가 이미 값에 포함되어 있다.

```cpp
        op1 << op2.img << "j" << endl;
```
> 허수부가 음수일 때: 부호가 자동 포함되므로 그대로 출력한다. (예: `-10j`)

```cpp
    else
        op1 << "+" << op2.img << "j" << endl;
```
> 허수부가 양수일 때: `+` 부호를 수동으로 붙여 출력한다. (예: `+10j`)

```cpp
    return op1;
```
> 출력 스트림(`cout`)을 참조로 반환한다. `cout << x << y` 연속 사용이 가능해진다.

```cpp
}
```
> `<<` 연산자 함수 종료.

---

```cpp
void complex::show() {
```
> `show()` 멤버 함수 정의. 멤버 함수이므로 `real`, `img`에 직접 접근 가능하다.

```cpp
    cout << real;
```
> 실수부를 출력한다.

```cpp
    if (img < 0)
        cout << img << "j" << endl;
```
> 허수부가 음수이면 부호 포함 그대로 출력한다.

```cpp
    else
        cout << "+" << img << "j" << endl;
```
> 허수부가 양수이면 `+` 부호를 붙여 출력한다.

```cpp
}
```
> `show()` 함수 종료.

---

```cpp
int main() {
```
> 프로그램 진입점.

```cpp
    complex x, y;
```
> `complex` 객체 `x`, `y`를 생성한다. 기본 생성자 호출로 `real=0, img=0`으로 초기화된다.

```cpp
    cin >> x >> y;
```
> 컴파일러가 `operator>>(operator>>(cin, x), y)`로 변환한다. `x`, `y` 순서로 실수부/허수부를 입력받는다.

```cpp
    cout << x << y;
```
> 컴파일러가 `operator<<(operator<<(cout, x), y)`로 변환한다. `x`, `y`를 순서대로 출력한다.

```cpp
    return 0;
```
> 프로그램이 정상 종료되었음을 운영체제에 반환한다.

```cpp
}
```
> `main` 함수 종료.

---

## 실행 결과

```
실수부:10
허수부:-10
실수부:20
허수부:-20
10-10j
20-20j
```
