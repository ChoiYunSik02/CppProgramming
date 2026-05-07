# ch5-2 실습과제 2 — add2 함수 오류 원인 분석 및 수정

---

## 문제

아래 코드에서 `add2` 함수는 `main` 함수의 변수 `number`를 2만큼 증가시키는 함수이다.  
그러나 실행 결과에서 보듯이 원하는 대로 작동하지 않는다.  
**이유를 설명하고 원하는 결과가 나오도록 코드를 수정하시오.**

---

## 오류 원인 분석

`add2(int value)`는 **값에 의한 호출(call by value)** 방식이다.  
함수 호출 시 `number`의 **값(15)이 복사**되어 `value`라는 별도의 메모리 공간에 저장된다.  
따라서 `value += 2`를 수행해도 `value`(복사본)만 17이 될 뿐, 원본 `number`는 그대로 15이다.

```
[ main 스택 ]    [ add2 스택 ]
  number = 15  →  value = 15 (복사본)
                  value += 2 → value = 17
  number = 15  ← 원본은 변경되지 않음
```

---

## 수정 방법 — 참조에 의한 호출(Call by Reference) 적용

매개변수를 `int& value`로 변경하면, `value`는 `number`의 **별명(alias)** 이 된다.  
`value += 2`는 곧 `number += 2`와 같으므로 원본이 직접 변경된다.

---

## 실행 결과
<img width="851" height="163" alt="image" src="https://github.com/user-attachments/assets/95861cdb-3104-410a-a76c-e42dd29ce50b" />


---

## 코드 설명

| 부분 | 설명 |
|------|------|
| `void add2(int& value)` | `&`를 붙여 참조 매개변수로 선언. `value`는 호출 시 전달된 변수의 별명이 됨 |
| `add2(number)` | 호출 문법은 기존과 동일. 내부적으로 `int& value = number`가 수행됨 |
| `value += 2` | `value`가 `number`의 별명이므로 `number`가 직접 2 증가함 |
| 별도 메모리 할당 없음 | 참조 매개변수는 이름만 생기고 별도 메모리 공간은 할당되지 않음 |
