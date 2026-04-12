# ch4-4장 실습과제 2번 - 소스코드 설명

---

## 줄별 설명

### 헤더 및 선언

| 코드 | 설명 |
|------|------|
| `#include <iostream>` | `cout`, `cin` 사용을 위한 헤더 |
| `#include <string>` | `string` 클래스 사용을 위한 헤더 |
| `using namespace std;` | `std::` 접두사 없이 사용하기 위한 선언 |

---

### 변수 선언

| 코드 | 설명 |
|------|------|
| `string result = ""` | 지금까지 입력된 문자열을 누적해서 저장하는 변수. 처음엔 빈 문자열로 초기화 |
| `int count = 1` | 몇 번째 입력인지 번호를 추적하는 카운터. 1부터 시작 |

---

### 반복문 내부

| 코드 | 설명 |
|------|------|
| `while (true)` | "quit" 입력 전까지 무한 반복 |
| `string input` | 이번 루프에서 입력받을 문자열을 저장하는 임시 변수 |
| `getline(cin, input, '\n')` | 엔터키까지 한 줄 전체를 `input`에 저장. `cin >>`은 공백 앞에서 끊기지만 `getline`은 공백도 포함해서 읽음 |
| `if (input == "quit") break` | `string`의 `==` 연산자로 문자열 직접 비교. `"quit"` 이면 루프 탈출 |
| `to_string(count)` | 정수 `count`를 문자열로 변환. 예) `2` → `"2"` |
| `"<" + to_string(count) + ">" + input` | `+` 연산자로 문자열 조각들을 이어붙여 `"<2>world"` 같은 형태를 만듦 |
| `result += ...` | 기존 `result` 뒤에 새로 만든 조각을 덧붙임 |
| `count++` | 다음 입력을 위해 번호 1 증가 |

---

## 실행 결과
<img width="824" height="255" alt="image" src="https://github.com/user-attachments/assets/5f9d2b75-51ec-47c9-9ae6-8262da3dd893" />

### 동작 예시 (count=2, input="world" 일 때)

```
result 현재값  →  "<1>hello"
조립 결과      →  "<" + "2" + ">" + "world"  =  "<2>world"
result +=      →  "<1>hello" + "<2>world"    =  "<1>hello<2>world"
```
