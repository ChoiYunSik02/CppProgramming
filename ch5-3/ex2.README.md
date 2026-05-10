## ch5-3 실습과제2 - Uppercase() 함수

---

### 코드 설명

**함수 선언 (전방 선언)**
```cpp
void Uppercase(string& s);
```
`main()` 위에 함수 원형을 선언하여 컴파일러가 함수의 존재를 미리 알게 한다.
실제 함수 정의는 `main()` 아래에 작성되어 있어도 문제없이 호출 가능하다.
 
**매개변수 `string& s`**
```cpp
void Uppercase(string& s)
```
`string&` 로 참조를 받기 때문에 `s`는 `s1`의 별명이 된다.
함수 안에서 `s`를 수정하면 원본 `s1`도 즉시 바뀐다.
만약 `string s`(값 전달)로 받았다면 복사본만 변경되어 `s1`에는 반영되지 않는다.
 
**문자 순회 및 대문자 변환**
```cpp
for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
}
```
`s.length()`로 문자열 길이만큼 반복하며, `toupper()`로 각 문자를 대문자로 변환한다.
`toupper()`는 이미 대문자이거나 숫자/특수문자면 그대로 반환하므로 안전하게 사용할 수 있다.
 
```
i=0: s[0]='h' → toupper('h') = 'H' → s[0]='H'
i=1: s[1]='e' → toupper('e') = 'E' → s[1]='E'
i=2: s[2]='l' → toupper('l') = 'L' → s[2]='L'
i=3: s[3]='l' → toupper('l') = 'L' → s[3]='L'
i=4: s[4]='o' → toupper('o') = 'O' → s[4]='O'
결과: "hello" → "HELLO"
```
 
### 실행 결과
<img width="828" height="162" alt="image" src="https://github.com/user-attachments/assets/3a0fac16-89ee-4471-8ce5-91c07bda5b70" />

