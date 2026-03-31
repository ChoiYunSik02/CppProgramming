# C++ 4-1장 실습과제2번 - 소스코드 설명

---

## 과제 목표

`Triangle` 클래스를 정의하고, 멤버함수 호출 부분을 **객체 포인터(`->`)** 를 이용하는 방식으로 작성한다.

---

## 클래스 설명 : `Triangle`

### 멤버 변수

| 변수명 | 자료형 | 접근 지정자 | 설명 |
|--------|--------|-------------|------|
| `width` | `int` | `private` | 삼각형의 밑변 |
| `height` | `int` | `private` | 삼각형의 높이 |

멤버 변수를 `private`으로 선언하여 외부에서 직접 접근하지 못하도록 **캡슐화**한다.

---

### 멤버 함수

#### 기본 생성자 `Triangle()`
```cpp
Triangle() { width = 1; height = 1; }
```
- 매개변수 없이 호출되는 생성자
- `width`와 `height`를 각각 `1`로 초기화

#### 매개변수 생성자 `Triangle(int a, int b)`
```cpp
Triangle(int a, int b) { width = a; height = b; }
```
- 밑변과 높이를 인자로 받아 초기화하는 생성자

#### `setWidth(int a)`
```cpp
void setWidth(int a) { width = a; }
```
- 밑변(`width`)을 외부에서 설정하는 setter 함수

#### `setHeight(int b)`
```cpp
void setHeight(int b) { height = b; }
```
- 높이(`height`)를 외부에서 설정하는 setter 함수

#### `getArea()`
```cpp
double getArea() {
    return (1.0 / 2.0) * width * height;
}
```
- 삼각형 넓이 공식 `(밑변 × 높이) / 2` 을 계산하여 반환
- 정수끼리 나눗셈 시 소수점이 잘리는 것을 방지하기 위해 `1.0 / 2.0` 으로 작성

---

## main 함수 설명

### 객체 및 포인터 선언

```cpp
Triangle tri;   // 기본 생성자 호출 → width=1, height=1
Triangle* p;    // Triangle 객체를 가리키는 포인터 선언
p = &tri;       // tri 객체의 주소를 p에 저장
```

`tri` 객체가 생성된 후, 포인터 `p`에 `tri`의 주소(`&tri`)를 대입한다.  
이로써 `p`는 `tri` 객체를 가리키게 된다.

---

### 객체 포인터로 멤버함수 호출

```cpp
p->setWidth(3);   // tri.setWidth(3) 과 동일
p->setHeight(5);  // tri.setHeight(5) 과 동일
```

`->` 연산자는 포인터가 가리키는 객체의 멤버에 접근하는 연산자이다.  
`p->멤버()` 는 `(*p).멤버()` 와 완전히 동일한 표현이다.

| 포인터 표현 | 객체 직접 표현 | 의미 |
|---|---|---|
| `p->setWidth(3)` | `tri.setWidth(3)` | width를 3으로 설정 |
| `p->setHeight(5)` | `tri.setHeight(5)` | height를 5로 설정 |
| `p->getArea()` | `tri.getArea()` | 넓이 계산 및 반환 |

---

### 결과 출력

```cpp
cout << "삼각형의 면적은 " << p->getArea() << endl;
```

`p->getArea()` 를 호출하면 `(1.0/2.0) * 3 * 5 = 7.5` 가 반환된다.

---

## 실행 결과

```
삼각형의 면적은 7.5
```

---

## 핵심 개념 정리

| 개념 | 설명 |
|------|------|
| 객체 포인터 선언 | `클래스명* 포인터명;` |
| 주소 대입 | `p = &객체명;` |
| 멤버 접근 (`->`) | `p->멤버` = `(*p).멤버` |
| 캡슐화 | `private` 멤버 변수를 `public` 멤버 함수로만 접근 |
