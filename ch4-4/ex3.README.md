# 4-4장 실습과제 3번 - 소스코드 설명

---

```cpp
#include <iostream>
```
`cin`, `cout` 사용을 위한 헤더 파일

```cpp
#include <string>
```
`string` 클래스 사용을 위한 헤더 파일

```cpp
using namespace std;
```
`std::` 접두사 없이 사용 가능하게 설정

---

```cpp
string s;
```
사용자가 입력할 원본 문자열을 저장하는 변수

```cpp
getline(cin, s, '\n');
```
공백 포함 한 줄 전체를 `s`에 저장. `cin >>`을 쓰면 공백 앞에서 끊김

```cpp
int count = 0;
```
`'a'`가 등장한 횟수를 누적할 카운터. 0으로 초기화

---

```cpp
for (int i = 0; i < (int)s.length(); i++)
```
인덱스 0부터 문자열 끝까지 한 글자씩 순회. `s.length()`의 반환 타입은 `size_t`(부호 없는 정수)이므로 `int`와 비교할 때 `(int)`로 캐스팅해 경고 방지

```cpp
if (s[i] == 'a') count++;
```
`s[i]`로 `i`번째 문자에 접근. 소문자 `'a'`인지 비교하여 맞으면 카운터 1 증가. 대문자 `'A'`는 다른 문자이므로 카운트되지 않음

```cpp
cout << "문자 a는 " << count << "개 있습니다." << endl;
```
최종 카운트 결과 출력

---

## 실행 결과
# 4장 실습과제 3번 - 소스코드 설명

---

```cpp
#include <iostream>
```
`cin`, `cout` 사용을 위한 헤더 파일

```cpp
#include <string>
```
`string` 클래스 사용을 위한 헤더 파일

```cpp
using namespace std;
```
`std::` 접두사 없이 사용 가능하게 설정

---

```cpp
string s;
```
사용자가 입력할 원본 문자열을 저장하는 변수

```cpp
getline(cin, s, '\n');
```
공백 포함 한 줄 전체를 `s`에 저장. `cin >>`을 쓰면 공백 앞에서 끊김

```cpp
int count = 0;
```
`'a'`가 등장한 횟수를 누적할 카운터. 0으로 초기화

---

```cpp
for (int i = 0; i < (int)s.length(); i++)
```
인덱스 0부터 문자열 끝까지 한 글자씩 순회. `s.length()`의 반환 타입은 `size_t`(부호 없는 정수)이므로 `int`와 비교할 때 `(int)`로 캐스팅해 경고 방지

```cpp
if (s[i] == 'a') count++;
```
`s[i]`로 `i`번째 문자에 접근. 소문자 `'a'`인지 비교하여 맞으면 카운터 1 증가. 대문자 `'A'`는 다른 문자이므로 카운트되지 않음

```cpp
cout << "문자 a는 " << count << "개 있습니다." << endl;
```
최종 카운트 결과 출력

---

## 실행 결과
<img width="839" height="160" alt="스크린샷 2026-04-13 011659" src="https://github.com/user-attachments/assets/86fb20d0-3a47-4ed7-8f67-ca4c0796b971" />
