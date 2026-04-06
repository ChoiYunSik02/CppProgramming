# 4-3장 실습과제 3번 - 코드 문제점 분석

## 문제점 1
```cpp
pArray++;
```
포인터를 증가시키면서 원래 배열의 시작 주소를 잃어버림
→ `delete[]`를 할 수 없게 됨 → 메모리 누수 발생

## 문제점 2
```cpp
pArray -> getArea()
```
배열 전체가 아니라 첫 번째 요소만 계속 접근하게 됨

## 해결 방법
- 포인터 직접 증가 사용 금지
- 배열 인덱스 방식 사용

```cpp
pArray[i].getArea()
```

## 결론
배열 포인터를 직접 증가시키는 것은 매우 위험하며, 배열 요소 접근은 인덱스(`[i]`)를 사용하는 것이 안전하다.


## 수정 후 실행결과
<img width="832" height="277" alt="image" src="https://github.com/user-attachments/assets/7a627cd4-78f3-4926-abe9-df241896b245" />

<br>
