# C++ 4-1장 실습과제3번 - 소스코드 설명

---

## 과제 목표

`Triangle` 클래스를 정의하고, **모든 멤버함수를 `this` 포인터를 이용하여 구현**한다.  
생성자 오버로딩을 통해 인자 개수에 따라 다르게 초기화되도록 한다.

---

## 클래스 설명 : `Triangle`

### 멤버 변수

| 변수명 | 자료형 | 접근 지정자 | 설명 |
|--------|--------|-------------|------|
| `width` | `int` | `private` | 삼각형의 밑변 |
| `height` | `int` | `private` | 삼각형의 높이 |

멤버 변수를 `private`으로 선언하여 외부에서 직접 접근하지 못하도록 **캡슐화**한다.

---

### this 포인터란?

`this`는 **객체 자신의 주소를 가리키는 포인터**로, 컴파일러가 모든 멤버함수에 자동으로 삽입하는 매개변수이다.

```cpp
this->width = 1;
// 위 코드는 아래와 동일한 의미
(*this).width = 1;
```

`this->멤버변수` 형태로 사용하면 현재 객체의 멤버 변수임을 명시적으로 표현할 수 있다.

---

### 멤버 함수

#### 기본 생성자 `Triangle()`

```cpp
Triangle() { this->width = 1; this->height = 1; }
```

- 매개변수 없이 호출되는 생성자
- `this` 포인터로 멤버 변수에 접근하여 `width = 1`, `height = 1` 로 초기화
- `Triangle tri1;` 선언 시 호출됨

#### 단일 인자 생성자 `Triangle(int a)`

```cpp
Triangle(int a) { this->width = a; this->height = 1; }
```

- 밑변(`width`)만 인자로 받는 생성자
- `this` 포인터로 `width = a`, `height = 1` 로 초기화
- `Triangle tri2(10);` 선언 시 호출됨

#### 두 인자 생성자 `Triangle(int a, int b)`

```cpp
Triangle(int a, int b) { this->width = a; this->height = b; }
```

- 밑변과 높이 모두 인자로 받는 생성자
- `this` 포인터로 `width = a`, `height = b` 로 초기화
- `Triangle tri3(10, 2);` 선언 시 호출됨

#### `getArea()`

```cpp
double getArea() {
    return (1.0 / 2.0) * this->width * this->height;
}
```

- 삼각형 넓이 공식 `(밑변 × 높이) / 2` 를 계산하여 반환
- `this->width`, `this->height` 로 현재 객체의 멤버 변수에 접근
- `1.0 / 2.0` 을 사용해 정수 나눗셈으로 소수점이 잘리는 것을 방지

---

## main 함수 설명

### 객체 생성 및 출력

```cpp
Triangle tri1;           // 기본 생성자 호출 → width=1, height=1
Triangle tri2(10);       // 단일 인자 생성자 호출 → width=10, height=1
Triangle tri3(10, 2);    // 두 인자 생성자 호출 → width=10, height=2
```

| 객체 | 호출된 생성자 | width | height | getArea() 반환값 |
|------|--------------|-------|--------|-----------------|
| `tri1` | `Triangle()` | 1 | 1 | 0.5 |
| `tri2` | `Triangle(int a)` | 10 | 1 | 5.0 |
| `tri3` | `Triangle(int a, int b)` | 10 | 2 | 10.0 |

---

## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| `this` 포인터 | 객체 자신의 주소를 가리키는 포인터, 컴파일러가 자동 삽입 |
| `this->멤버` | 현재 객체의 멤버 변수 또는 멤버 함수에 접근 |
| 생성자 오버로딩 | 인자 개수에 따라 다른 생성자가 호출됨 |
| 캡슐화 | `private` 멤버를 `public` 생성자/함수로만 접근 |

---

## 실행 결과

```
삼각형의 면적은 0.5
삼각형의 면적은 5
삼각형의 면적은 10
```
