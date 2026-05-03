# Chapter 05-1 실습과제5 소스코드 설명

> **string 배열에서 사전 순으로 가장 뒤에 오는 문자열 탐색**  
> 학번: 2101091 최윤식

---

## 📋 문제 요약

사전에서 제일 뒤에 나오는 문자열을 구하는 함수를 작성하시오.  
- `string` 객체 배열을 인수로 받고 `string` 객체를 리턴하는 함수
- 5개의 이름을 입력받아 사전 순으로 가장 뒤에 오는 문자열을 출력

---

## 💻 소스코드 및 설명
```cpp
#include <iostream>
#include <string>
using namespace std;
```
> - `<iostream>` : `cout`, `cin`, `endl` 등 입출력 스트림 사용을 위해 포함  
> - `<string>` : `string` 클래스 및 `getline()` 사용을 위해 포함  
> - `using namespace std` : `std::` 접두사 없이 표준 라이브러리 사용

---

```cpp
string StudentName(string arr[], int size);
```
> **함수 선언 (프로토타입)**  
> - `string arr[]` : `string` 객체 배열의 시작 주소를 받는 매개변수  
>   → 배열 이름 자체가 첫 번째 원소의 주소이므로 **포인터로 전달**됨  
>   → `string* arr` 와 동일한 의미  
> - `int size` : 배열의 원소 개수를 전달받는 매개변수  
>   → 배열은 크기 정보를 함께 전달하지 않으면 함수 내부에서 크기를 알 수 없음  
> - 리턴값 `string` : 사전 순으로 가장 뒤에 오는 문자열을 객체로 반환

---

```cpp
int main() {
```
> 프로그램의 시작점. `main()` 함수 정의 시작.

---

```cpp
    string names[5];
```
> **`string` 객체 배열 선언**  
> - `string` 객체 5개가 연속된 메모리에 생성됨  
> - 각 원소는 기본 생성자 호출로 빈 문자열 `""` 로 초기화됨  
> - `names[0]` ~ `names[4]` 로 각 원소에 접근

---

```cpp
    for (int i = 0; i < 5; i++) {
```
> 반복 변수 `i` 를 0부터 4까지 증가시키며 5회 반복  
> → 배열 인덱스 `names[0]` ~ `names[4]` 순서로 입력받기 위함

---

```cpp
        cout << "이름 >> ";
```
> 사용자에게 이름 입력을 안내하는 프롬프트 출력  
> `endl` 없이 출력해 입력 커서가 같은 줄에 위치하도록 함

---

```cpp
        getline(cin, names[i], '\n');
```
> **공백을 포함한 한 줄 전체를 `names[i]` 에 입력받음**  
> - `cin >>` 는 공백 전까지만 읽으므로 `"Kim Nam Yun"` 같은 이름을 읽을 수 없음  
> - `getline(cin, names[i], '\n')` : 엔터(`'\n'`)가 입력될 때까지 한 줄 전체를 읽어 `names[i]` 에 저장  
> - 공백이 포함된 이름도 하나의 문자열로 올바르게 저장됨

---

```cpp
    }
```
> `for` 반복문 종료 — 5개의 이름이 모두 `names` 배열에 저장된 상태

---

```cpp
    string res = StudentName(names, 5);
```
> **배열을 인수로 함수 호출**  
> - `names` : 배열의 첫 번째 원소 주소가 전달됨 (배열 이름 = 주소)  
> - `5` : 배열 원소 개수를 함께 전달  
> - 함수가 반환한 `string` 임시 객체로 `res` 를 초기화  
> - `res` 에 사전 순 가장 뒤 문자열이 저장됨

---

```cpp
    cout << "사전에서 가장 뒤에 나오는 문자열은 " << res << endl;
```
> 결과 출력  
> - `res` 에 저장된 사전 순 최댓값 문자열을 화면에 출력  
> - `endl` 로 줄바꿈 및 버퍼 플러시

---

```cpp
}
```
> `main()` 함수 종료

---

```cpp
string StudentName(string arr[], int size)
{
```
> **함수 정의**  
> - `string arr[]` : `main()` 의 `names` 배열 시작 주소를 받음  
>   → 배열 원소를 직접 읽기만 하므로 복사 없이 주소로 접근  
> - `int size` : 배열 크기 5를 받음  
> - 리턴 타입 `string` : 탐색 결과를 `string` 객체로 반환

---

```cpp
    string last = arr[0];
```
> **탐색 기준값을 첫 번째 원소로 초기화**  
> - `arr[0]` : 배열의 첫 번째 `string` 객체  
> - 아직 비교를 시작하지 않았으므로 일단 첫 번째 이름을 현재 최댓값으로 설정  
> - 이후 반복문에서 더 뒤에 오는 문자열을 발견하면 `last` 를 갱신함

---

```cpp
    for (int i = 1; i < size; i++) {
```
> **두 번째 원소(`arr[1]`)부터 마지막 원소(`arr[4]`)까지 순회**  
> - `i = 1` 부터 시작 : `arr[0]` 은 이미 `last` 로 설정했으므로 중복 비교 불필요  
> - `i < size` : `size = 5` 이므로 `i` 가 0~4 범위에서 반복

---

```cpp
        if (arr[i] > last)
```
> **현재 원소 `arr[i]` 가 `last` 보다 사전 순으로 뒤에 오는지 비교**  
> - `string` 의 `>` 연산자는 두 문자열을 **사전 순(lexicographic)** 으로 비교  
> - 첫 글자부터 순서대로 ASCII 값을 비교하여 더 큰 쪽이 사전 순으로 뒤에 옴  
> - 예) `'L'(76) > 'K'(75)` 이므로 `"Lee"` > `"Kim"` → `"Lee"` 가 더 뒤

---

```cpp
            last = arr[i];
```
> **`arr[i]` 가 `last` 보다 사전 순으로 뒤에 오면 `last` 를 갱신**  
> - `string` 의 `=` 대입 연산자로 `last` 에 `arr[i]` 의 내용을 복사  
> - 반복문이 끝날 때까지 이 과정을 반복하면 결국 가장 뒤의 문자열이 `last` 에 남음

---

```cpp
    }
```
> `for` 반복문 종료 — 배열 전체 탐색 완료, `last` 에 최댓값 저장됨

---

```cpp
    return last;
```
> 사전 순으로 가장 뒤에 오는 문자열 `last` 를 반환  
> - 컴파일러가 임시 객체를 자동 생성하여 반환값을 저장  
> - 지역 변수 `last` 는 함수 종료 후 소멸하지만, 임시 객체를 통해 `main()` 의 `res` 에 안전하게 전달됨

---

```cpp
}
```
> `StudentName()` 함수 종료  
> - 지역 변수 `last`, `i` 는 스택에서 소멸  
> - 포인터로 전달된 `arr` 도 소멸 (원본 배열 `names` 는 그대로 유지)

---

## 📊 탐색 과정 단계별 상태표

> 입력값 : `Kim Nam Yun`, `Chang Jae Young`, `Lee Jae Moon`, `Han Won Sun`, `Hwang Su hee`

| 단계 | i | arr[i] | last (현재 최댓값) | 갱신 여부 |
|------|---|--------|--------------------|---------|
| 초기화 | — | — | `"Kim Nam Yun"` | 첫 번째 원소로 설정 |
| 1회 | 1 | `"Chang Jae Young"` | `"Kim Nam Yun"` | ❌ `'C' < 'K'` |
| 2회 | 2 | `"Lee Jae Moon"` | **`"Lee Jae Moon"`** | ✅ `'L' > 'K'` |
| 3회 | 3 | `"Han Won Sun"` | `"Lee Jae Moon"` | ❌ `'H' < 'L'` |
| 4회 | 4 | `"Hwang Su hee"` | `"Lee Jae Moon"` | ❌ `'H' < 'L'` |
| 반환 | — | — | `"Lee Jae Moon"` | 최종 결과 |

---

## 📊 함수 호출 흐름 정리

```
main()                              StudentName()
────────────────────────────────────────────────────
names[0] = "Kim Nam Yun"
names[1] = "Chang Jae Young"
names[2] = "Lee Jae Moon"           arr → names 배열 주소
names[3] = "Han Won Sun"            size = 5
names[4] = "Hwang Su hee"
                  names(주소) ──▶
                  5          ──▶    last = arr[0] = "Kim Nam Yun"
                                    arr[1]="Chang..." < last → 유지
                                    arr[2]="Lee..."  > last → 갱신 ✅
                                    arr[3]="Han..."  < last → 유지
                                    arr[4]="Hwang.." < last → 유지
                                    return "Lee Jae Moon"
                  ◀── 임시객체 ─── "Lee Jae Moon"
res = "Lee Jae Moon"
```

---

## ✅ 실행 결과
<img width="844" height="259" alt="스크린샷 2026-05-03 171219" src="https://github.com/user-attachments/assets/a20b3676-488e-4c6f-ab19-6747407fe6db" />


> **왜 `"Lee Jae Moon"` 이 가장 뒤인가?**  
> 사전 순 비교는 첫 글자의 알파벳 순서로 결정됨  
> `C(67) < H(72) < K(75) < L(76)` → `'L'` 이 가장 크므로 `"Lee Jae Moon"` 이 최댓값

---

## 📌 핵심 정리

| 항목 | 내용 |
|------|------|
| 매개변수 | `string arr[]` — 배열의 시작 주소 전달 (`string*` 와 동일) |
| 배열 크기 전달 | `int size` 를 별도로 전달 — 함수 내부에서 배열 크기를 알 수 없기 때문 |
| 입력 방식 | `getline()` — 공백 포함 한 줄 전체 입력 |
| 탐색 방식 | 첫 번째 원소를 기준으로 설정 후 순회하며 더 큰 값으로 갱신 |
| 비교 연산 | `string` 의 `>` 연산자 — 사전 순(lexicographic) 비교 |
| 반환 방식 | 지역 변수 `last` 를 임시 객체로 반환 후 `res` 에 대입 |

---

