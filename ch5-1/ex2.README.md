# Chapter 05-1 실습과제2 소스코드 설명

---

## 📋 문제 요약

함수 호출문 `res = GetLatterString(s1, s2)` 를 참고하여  
`GetLatterString` 함수의 **선언과 정의를 추가**하시오.  
- 값에 의한 호출 사용
- 매개변수, 리턴값 모두 `string` 객체

---

## 💻 소스코드 및 설명
```cpp
#include <iostream>
#include <string>
using namespace std;
```
> - `<iostream>` : `cout`, `endl` 등 입출력 스트림 사용을 위해 포함  
> - `<string>` : `string` 클래스 사용을 위해 포함  
> - `using namespace std` : `std::` 접두사 없이 표준 라이브러리 사용

---

```cpp
string GetLatterString(string s1, string s2);
```
> **함수 선언 (프로토타입)**  
> - 컴파일러에게 이 함수가 존재함을 미리 알려준다  
> - 매개변수가 `string` 객체이므로 **값에 의한 호출** 방식  
> - 리턴값도 `string` 객체  
> - `main()` 보다 위에 선언해야 `main()` 안에서 호출 가능

---

```cpp
int main() {
```
> 프로그램의 시작점. `main()` 함수 정의 시작.

---

```cpp
    string s1("hello");
```
> `string` 클래스의 생성자를 호출하여 `s1` 객체를 `"hello"` 로 초기화

---

```cpp
    string s2("world");
```
> `string` 클래스의 생성자를 호출하여 `s2` 객체를 `"world"` 로 초기화

---

```cpp
    string res;
```
> 함수의 반환값을 저장할 `string` 객체 선언  
> 초기값은 빈 문자열 `""`

---

```cpp
    res = GetLatterString(s1, s2);
```
> **값에 의한 호출로 함수 실행**  
> - `s1`, `s2` 의 **값(문자열 내용)이 복사**되어 매개변수에 전달됨  
> - 스택에 `s1`, `s2` 의 복사본이 새로 생성됨  
> - 함수가 반환한 `string` 객체(임시 객체)가 `res` 에 대입됨

---

```cpp
    cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다." << endl;
```
> 결과 출력  
> - `res` 에 저장된 사전 순 뒤 문자열을 화면에 출력  
> - `endl` 로 줄바꿈 및 버퍼 플러시

---

```cpp
}
```
> `main()` 함수 종료. `return 0` 은 생략 가능 (C++에서 `main`은 자동으로 0 반환)

---

```cpp
string GetLatterString(string s1, string s2)
{
```
> **함수 정의**  
> - 매개변수 `string s1`, `string s2` : 값에 의한 호출이므로 호출 시 **복사본이 생성**됨  
> - 원본 `main()` 의 `s1`, `s2` 와는 **별개의 독립적인 객체**  
> - 리턴 타입 `string` : 함수 종료 시 `string` 객체를 반환

---

```cpp
    if (s1 > s2)
```
> **`string` 의 `>` 연산자로 사전 순(lexicographic) 비교 수행**  
> - `string` 클래스는 `>`, `<`, `==` 등 비교 연산자가 내장되어 있음  
> - 문자열을 앞 글자부터 순서대로 비교 (`'h'` vs `'w'` → ASCII 값으로 비교)  
> - `'w'(119) > 'h'(104)` 이므로 `s1("hello") > s2("world")` 는 **거짓**

---

```cpp
        return s1;
```
> `s1` 이 `s2` 보다 사전 순으로 뒤에 올 경우 `s1` 을 반환  
> - 반환 시 컴파일러가 **임시 객체**를 자동 생성하여 반환값을 저장  
> - 지역 변수 `s1` 은 함수 종료 후 소멸하지만, 임시 객체를 통해 값이 안전하게 전달됨

---

```cpp
    else
        return s2;
```
> `s1 <= s2` 인 경우 `s2` 를 반환  
> - `s1 == s2` 인 경우에도 `s2` 가 반환됨  
> - 마찬가지로 임시 객체를 통해 반환값이 `res` 에 전달됨

---

```cpp
}
```
> `GetLatterString()` 함수 종료  
> - 매개변수 `s1`, `s2` (복사본) 는 스택에서 소멸

---

## 📊 함수 호출 흐름 정리

```
main()                          GetLatterString()
──────────────────────────────────────────────────
string s1 = "hello"
string s2 = "world"
                  ─── 값 복사 ──▶   string s1 = "hello" (복사본)
                  ─── 값 복사 ──▶   string s2 = "world" (복사본)

                                    if("hello" > "world") → false
                                    return s2 → "world"

                  ◀── 임시객체 ───  "world"
res = "world"
```

---

## ✅ 실행 결과
<img width="837" height="156" alt="스크린샷 2026-05-03 171351" src="https://github.com/user-attachments/assets/7046bcd4-59d7-4e74-8ea2-ca06b0804d0b" />


## 📌 핵심 정리

| 항목 | 내용 |
|------|------|
| 호출 방식 | **값에 의한 호출 (call by value)** |
| 복사 발생 | ✅ `s1`, `s2` 의 복사본이 스택에 생성됨 |
| 원본 변경 여부 | ❌ 함수 내에서 원본 `s1`, `s2` 는 변경 불가 |
| 비교 연산 | `string` 의 `>` 연산자 — 사전 순(lexicographic) 비교 |
| 반환 방식 | 임시 객체가 자동 생성되어 호출자에게 값 전달 |

---

