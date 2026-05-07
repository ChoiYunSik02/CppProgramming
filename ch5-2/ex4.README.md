# ch5-2 실습과제 4 — get_parts 함수 (정수부/소수부 분리)

---

## 문제

키보드로부터 실수를 입력받아 **정수부**와 **소수부**를 구하여 출력하는 프로그램을 작성하시오.

**조건**
- 정수부와 소수부를 구하여 리턴하는 부분을 `get_parts` 함수 1개로 작성할 것
- 화면 입출력은 `main` 함수에서 작성할 것 (`get_parts` 함수 내부에서 입출력 금지)
- 함수의 **선언, 호출, 정의**를 모두 작성할 것

---

## 코드 설명

### 함수 선언 (프로토타입)

```cpp
void get_parts(double num, int& intpart, double& fracpart);
```

- `double num` : 값에 의한 호출 — 입력 전용, 읽기만 하므로 복사로 전달
- `int& intpart` : 참조 매개변수 — `main`의 `ip`의 별명, 정수부를 돌려줄 통로
- `double& fracpart` : 참조 매개변수 — `main`의 `fp`의 별명, 소수부를 돌려줄 통로

---

### 함수 호출

```cpp
get_parts(num, ip, fp);
```

호출 직후 내부적으로 아래와 같이 초기화된다.

```
int&    intpart  = ip;   // ip의 별명
double& fracpart = fp;   // fp의 별명
```

`intpart`, `fracpart`는 이름만 생성되고 별도의 메모리 공간은 할당되지 않는다.

---

### 함수 정의 — 정수부/소수부 추출

```cpp
intpart  = (int)num;       // 3.14159 → 3  (소수점 이하 버림)
fracpart = num - intpart;  // 3.14159 - 3 = 0.14159
```

`intpart`와 `fracpart`가 각각 `ip`, `fp`의 별명이므로,  
함수 내에서 값을 대입하면 `main`의 변수가 즉시 갱신된다.

---

## 실행 결과
<img width="823" height="170" alt="image" src="https://github.com/user-attachments/assets/98335648-90cd-4b27-8a37-3c22d124336d" />


### 참조 매개변수를 사용한 이유

`return`문은 값을 하나만 반환할 수 있다.  
정수부(`ip`)와 소수부(`fp`) **두 값을 동시에 반환**하려면  
참조 매개변수를 출력 통로로 활용하는 것이 가장 간결한 방법이다.

```
[ main 스택 ]         [ get_parts 스택 ]
  ip  = ?       ←→    intpart  (ip의 별명)
  fp  = ?       ←→    fracpart (fp의 별명)
  num = 3.14159 →     num (복사본)
```
