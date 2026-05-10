## ch5-3 실습과제3 - SwapString() 함수

---

### 코드 설명
 
**매개변수 `string& a, string& b`**
```cpp
void SwapString(string& a, string& b)
```
두 매개변수 모두 참조로 선언했기 때문에 `a`는 `s1`의 별명, `b`는 `s2`의 별명이 된다.
함수 안에서 `a`, `b`를 교환하면 원본 `s1`, `s2`도 함께 바뀐다.
 
**임시 변수를 이용한 swap**
```cpp
string temp;
temp = a;
a = b;
b = temp;
```
`temp`를 빈 문자열로 먼저 선언한 뒤 `a`의 값을 저장한다.
이후 `a = b`, `b = temp` 순서로 교환한다.
 
```
초기:  a = "hello",  b = "world"
① temp = a   →  temp = "hello"
② a = b      →  a = "world"
③ b = temp   →  b = "hello"
결과:  a = "world",  b = "hello"  (원본 s1, s2에도 반영)
```
 
**포인터 방식과의 차이**
 
| 항목 | 포인터 (`string*`) | 참조 (`string&`) |
|------|------------------|----------------|
| 호출 방법 | `SwapString(&s1, &s2)` | `SwapString(s1, s2)` |
| 함수 내부 접근 | `*a`, `*b` (역참조 필요) | `a`, `b` (일반 변수처럼) |
| nullptr 전달 | 가능 → 런타임 오류 위험 | 불가 → 더 안전 |
| 코드 가독성 | 복잡 | 간결 |
 
### 실행 결과
<img width="811" height="160" alt="image" src="https://github.com/user-attachments/assets/688f8196-cb86-4a34-86c4-00ec4f714205" />

