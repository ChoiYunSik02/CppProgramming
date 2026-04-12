# 4장 실습과제 2번 - 소스코드 설명

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
string result = "";
```
지금까지 입력된 문자열을 누적해서 저장하는 변수. 빈 문자열로 초기화

```cpp
int count = 1;
```
몇 번째 입력인지 번호를 추적하는 카운터. 1부터 시작

---

```cpp
while (true)
```
`"quit"` 입력 전까지 무한 반복

```cpp
string input;
```
이번 루프에서 입력받을 문자열을 저장하는 임시 변수

```cpp
getline(cin, input, '\n');
```
엔터키까지 한 줄 전체를 `input`에 저장. `cin >>`은 공백 앞에서 끊기지만 `getline`은 공백도 포함해서 읽음

```cpp
if (input == "quit") break;
```
`string`의 `==` 연산자로 문자열 직접 비교. `"quit"`이면 루프 탈출

```cpp
result += "<" + to_string(count) + ">" + input;
```
`to_string(count)`으로 정수를 문자열로 변환한 뒤 `+` 연산자로 조각들을 이어붙임. 예) count=2, input="world" → `"<2>world"` 를 result 뒤에 덧붙임

```cpp
count++;
```
다음 입력을 위해 번호 1 증가

```cpp
cout << "이어진 문자열: " << result << endl;
```
현재까지 누적된 전체 문자열 출력

---

## 실행 결과
<img width="824" height="255" alt="스크린샷 2026-04-13 010129" src="https://github.com/user-attachments/assets/9167e3bc-b67a-4116-8239-97cc3a92846c" />
