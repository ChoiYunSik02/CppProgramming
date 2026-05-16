# ch6-1장 실습과제 2 — big() 함수 중복

---

## 📄 소스코드 (줄별 설명)

```cpp
#include <iostream>
```
> `cout` 등 입출력 기능을 사용하기 위한 헤더 파일을 포함한다.

```cpp
#include <string>
```
> `string` 타입을 사용하기 위한 헤더 파일을 포함한다.

```cpp
using namespace std;
```
> `std::cout`, `std::string` 처럼 매번 `std::`를 붙이지 않아도 되도록 선언한다.

---

```cpp
int big(int a, int b) {
```
> **정수형 big() 함수 정의** — 매개변수가 `int` 두 개이므로 실수형/문자열형 버전과 구별된다.

```cpp
    if (a > b) return a;
```
> `a`가 `b`보다 크면 `a`를 반환한다.

```cpp
    else return b;
```
> `a`가 `b`보다 크지 않으면 `b`를 반환한다.

```cpp
}
```
> 정수형 big() 함수 끝.

---

```cpp
double big(double a, double b) {
```
> **실수형 big() 함수 정의** — 매개변수 타입이 `double`이므로 컴파일러가 int 버전과 자동으로 구별한다.

```cpp
    if (a > b) return a;
```
> `a`가 `b`보다 크면 `a`를 반환한다.

```cpp
    else return b;
```
> `a`가 `b`보다 크지 않으면 `b`를 반환한다.

```cpp
}
```
> 실수형 big() 함수 끝.

---

```cpp
string big(string a, string b) {
```
> **문자열형 big() 함수 정의** — 매개변수 타입이 `string`이므로 앞의 두 버전과 구별된다.

```cpp
    if (a > b) return a;
```
> `string`의 `>` 연산자는 사전순(lexicographic) 비교를 수행한다.
> `a`가 사전순으로 `b`보다 뒤에 오면 `a`를 반환한다.

```cpp
    else return b;
```
> `b`가 사전순으로 `a`보다 뒤에 오면 `b`를 반환한다.

```cpp
}
```
> 문자열형 big() 함수 끝.

---

```cpp
int main() {
```
> 프로그램 실행의 시작점.

```cpp
    int x = big(10, 20);
```
> 인자가 `int` 타입이므로 컴파일러가 **정수형 big()** 을 호출한다.
> 10 < 20이므로 20이 반환되어 `x`에 저장된다.

```cpp
    cout << "큰 정수값은 " << x << endl;
```
> `x`의 값(20)을 출력한다. `endl`은 줄바꿈을 수행한다.

```cpp
    double y = big(3.14, 1.05);
```
> 인자가 `double` 타입이므로 컴파일러가 **실수형 big()** 을 호출한다.
> 3.14 > 1.05이므로 3.14가 반환되어 `y`에 저장된다.

```cpp
    cout << "큰 실수값은 " << y << endl;
```
> `y`의 값(3.14)을 출력한다.

```cpp
    string z = big("hello", "world");
```
> 인자가 문자열 리터럴이므로 컴파일러가 **문자열형 big()** 을 호출한다.
> `'w'`가 `'h'`보다 사전순으로 뒤에 오므로 `"world"`가 반환되어 `z`에 저장된다.

```cpp
    cout << "사전에서 뒤에 나오는 단어는 " << z << endl;
```
> `z`의 값("world")을 출력한다.

```cpp
    return 0;
```
> `main()` 함수가 정상 종료됨을 운영체제에 알린다.

```cpp
}
```
> `main()` 함수 끝.

---

## 📌 실행 결과
<img width="825" height="174" alt="스크린샷 2026-05-17 001002" src="https://github.com/user-attachments/assets/86e3e7a8-0d85-4189-a9b6-a99976df6b62" />


## 📝 핵심 정리

| 함수 | 매개변수 타입 | 호출 예 | 반환값 |
|------|-------------|---------|--------|
| `int big(int, int)` | int | `big(10, 20)` | `20` |
| `double big(double, double)` | double | `big(3.14, 1.05)` | `3.14` |
| `string big(string, string)` | string | `big("hello", "world")` | `"world"` |

- 함수 이름이 같아도 **매개변수 타입이 다르면** 별개의 함수로 취급된다 → **함수 중복(오버로딩)**
- 리턴 타입은 함수 구분 기준이 아니다.
