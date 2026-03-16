# 3-2장 실습과제 4번 - 소스코드 설명

---

## 🔷 클래스 선언

```cpp
class Rectangle {
public:
    int x;          // 좌측 상단 x 좌표
    int y;          // 좌측 상단 y 좌표
    int width;      // 가로 길이
    int height;     // 세로 길이

    int getArea();       // 면적 반환
    int Perimeter();     // 둘레 반환
    int CoordinateX();   // 우측 하단 x좌표 반환
    int CoordinateY();   // 우측 하단 y좌표 반환

    Rectangle();
    Rectangle(int a, int b);
    Rectangle(int a, int b, int c, int d);
};
```

### 멤버 변수 설명

| 변수 | 의미 |
|------|------|
| `x` | 사각형 좌측 상단의 x 좌표 |
| `y` | 사각형 좌측 상단의 y 좌표 |
| `width` | 사각형의 가로 길이 |
| `height` | 사각형의 세로 길이 |

---

## 🔷 멤버 함수 설명

### `getArea()` - 면적 계산

```cpp
int Rectangle::getArea() {
    return width * height;
}
```

- 사각형의 넓이 = 가로 × 세로
- `rect1` 기준: `1 × 1 = 1`

---

### `Perimeter()` - 둘레 계산

```cpp
int Rectangle::Perimeter() {
    return (width + height) * 2;
}
```

- 사각형의 둘레 = (가로 + 세로) × 2
- `rect2` 기준: `(1 + 1) × 2 = 4`

---

### `CoordinateX()` - 우측 하단 x좌표

```cpp
int Rectangle::CoordinateX() {
    return x + width;
}
```

- 좌측 상단 x 좌표에서 가로 길이만큼 더함
- `rect3` 기준: `3 + 2 = 5`

---

### `CoordinateY()` - 우측 하단 y좌표

```cpp
int Rectangle::CoordinateY() {
    return y - height;
}
```

- 좌측 상단 y 좌표에서 세로 길이만큼 뺌 (y축 아래 방향이 음수)
- `rect3` 기준: `5 - 4 = 1`

> ⚠️ **y 좌표 방향 주의**: 화면 좌표계에서 y축은 아래로 갈수록 증가하지만,  
> 이 과제에서는 수학적 좌표계를 기준으로 **아래로 내려갈수록 y 감소**로 처리합니다.

---

## 🔷 생성자 설명 (위임 생성자 활용)

```cpp
// 1. 기본 생성자 - 모든 멤버를 1로 초기화
Rectangle::Rectangle() : Rectangle(1, 1, 1, 1) { }

// 2. 인자 2개 생성자 - width, height를 1로 기본 설정
Rectangle::Rectangle(int a, int b) : Rectangle(a, b, 1, 1) { }

// 3. 인자 4개 생성자 - 멤버 초기화 리스트로 직접 초기화 (타깃 생성자)
Rectangle::Rectangle(int a, int b, int c, int d) : x(a), y(b), width(c), height(d) { }
```

### 위임 생성자 흐름도

```
Rectangle()          →  Rectangle(1, 1, 1, 1)
                                   ↓
Rectangle(int a, int b)  →  Rectangle(a, b, 1, 1)
                                   ↓
Rectangle(int a, int b, int c, int d)  →  x=a, y=b, width=c, height=d
```

- 생성자 1, 2번은 **위임 생성자(Delegating Constructor)**: 다른 생성자에게 초기화를 위임
- 생성자 3번은 **타깃 생성자**: 실제 멤버 초기화를 담당하며 **멤버 초기화 리스트** 사용

---

## 🔷 main() 함수 분석

```cpp
Rectangle rect1;               // x=1, y=1, width=1, height=1
Rectangle rect2(3, 5);         // x=3, y=5, width=1, height=1
Rectangle rect3(3, 5, 2, 4);   // x=3, y=5, width=2, height=4
```

### 객체별 초기화 값

| 객체 | x | y | width | height |
|------|---|---|-------|--------|
| `rect1` | 1 | 1 | 1 | 1 |
| `rect2` | 3 | 5 | 1 | 1 |
| `rect3` | 3 | 5 | 2 | 4 |

---

## 🔷 실행 결과

```
사각형의 면적은 1
사각형의 둘레길이는 4
사각형의 우측하단의 좌표는 (5, 1)
```

### 계산 과정 정리

| 출력 | 객체 | 계산식 | 결과 |
|------|------|--------|------|
| 면적 | `rect1` | `1 × 1` | `1` |
| 둘레 | `rect2` | `(1 + 1) × 2` | `4` |
| 우측 하단 x | `rect3` | `3 + 2` | `5` |
| 우측 하단 y | `rect3` | `5 - 4` | `1` |

---

## 💡 핵심 개념 요약

| 개념 | 설명 |
|------|------|
| **위임 생성자** | 한 생성자가 다른 생성자를 호출해 초기화를 위임하는 방식 |
| **멤버 초기화 리스트** | 생성자 본문 실행 전에 멤버 변수를 초기화하는 문법 (`: x(a), y(b), ...`) |
| **타깃 생성자** | 위임을 받아 실제 초기화를 수행하는 생성자 |
