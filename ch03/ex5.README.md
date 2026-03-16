# 3-1장 실습과제 5장
---

## 전체 구조 요약

```
Rectangle 클래스
├── 멤버변수: x, y, width, height
└── 멤버함수
    ├── input()       → 키보드 입력 받아 멤버변수에 저장
    ├── getArea()     → 면적 계산
    ├── Perimeter()   → 둘레 계산
    ├── CoordinateX() → 우측 하단 x좌표 계산
    └── CoordinateY() → 우측 하단 y좌표 계산
```

---

## 헤더 및 네임스페이스

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>` : `cin`, `cout` 사용을 위한 헤더 파일
- `using namespace std` : `std::` 접두사 없이 사용 가능하게 설정

---

## 클래스 선언

```cpp
class Rectangle {
public:
    int x;
    int y;
    int width;
    int height;
    void input();
    int getArea();
    int Perimeter();
    int CoordinateX();
    int CoordinateY();
};
```

| 멤버 | 종류 | 설명 |
|---|---|---|
| `x` | 멤버변수 | 사각형 좌측 상단의 x좌표 |
| `y` | 멤버변수 | 사각형 좌측 상단의 y좌표 |
| `width` | 멤버변수 | 사각형의 가로 길이 |
| `height` | 멤버변수 | 사각형의 세로 길이 |
| `input()` | 멤버함수 | 키보드로부터 값을 입력받아 멤버변수에 저장 |
| `getArea()` | 멤버함수 | 면적을 계산하여 반환 |
| `Perimeter()` | 멤버함수 | 둘레를 계산하여 반환 |
| `CoordinateX()` | 멤버함수 | 우측 하단 x좌표를 계산하여 반환 |
| `CoordinateY()` | 멤버함수 | 우측 하단 y좌표를 계산하여 반환 |

- `public` : 클래스 외부(main 등)에서 멤버에 자유롭게 접근 가능

---

## 멤버함수 구현

### input() — 키보드 입력
```cpp
void Rectangle::input() {
    cout << "사각형의 좌측 상단 좌표(x, y): ";
    cin >> x >> y;
    cout << "사각형의 폭과 높이(width, height): ";
    cin >> width >> height;
}
```
- `void` : 반환할 값이 없으므로 void 사용
- 멤버함수 내부이므로 `x`, `y`, `width`, `height`에 **직접 접근** 가능
- `cin >> x >> y` : x, y 두 값을 공백으로 구분하여 한 번에 입력받음

---

### getArea() — 면적 계산
```cpp
int Rectangle::getArea() {
    return width * height;
}
```
- 면적 = 가로 × 세로
- 계산 결과를 `int`로 반환

---

### Perimeter() — 둘레 계산
```cpp
int Rectangle::Perimeter() {
    return (width + height) * 2;
}
```
- 둘레 = (가로 + 세로) × 2
- 계산 결과를 `int`로 반환

---

### CoordinateX() — 우측 하단 x좌표
```cpp
int Rectangle::CoordinateX() {
    return x + width;
}
```
- 좌측 상단 x좌표에서 오른쪽으로 width만큼 이동
- 우측 하단 x = x + width

---

### CoordinateY() — 우측 하단 y좌표
```cpp
int Rectangle::CoordinateY() {
    return y - height;
}
```
- 좌측 상단 y좌표에서 아래로 height만큼 이동
- 화면 좌표계에서 아래쪽이 y값이 감소하므로 빼기 연산
- 우측 하단 y = y - height

---

## main() 함수

```cpp
int main() {
    Rectangle rect;
    rect.input();
    cout << "사각형의 면적은 " << rect.getArea() << endl;
    cout << "사각형의 둘레길이는 " << rect.Perimeter() << endl;
    cout << "사각형의 우측하단의 좌표는 (" << rect.CoordinateX() << ", " << rect.CoordinateY() << ")" << endl;
}
```

| 코드 | 설명 |
|---|---|
| `Rectangle rect;` | Rectangle 클래스의 객체 `rect` 생성 |
| `rect.input();` | 멤버함수 호출로 키보드 입력 처리 |
| `rect.getArea()` | 면적 계산 결과 출력 |
| `rect.Perimeter()` | 둘레 계산 결과 출력 |
| `rect.CoordinateX/Y()` | 우측 하단 좌표 출력 |

---

## 실행 결과
<img width="799" height="165" alt="Image" src="https://github.com/user-attachments/assets/cb0d8761-2653-4140-a6f3-cd165f972ef0" />

---

## 좌표 계산 시각화

```
(2, 10) ──────────── (7, 10)
   │                     │
   │   width=5            │
   │   height=3           │
   │                     │
(2, 7)  ──────────── (7, 7)  ← 우측 하단
```
- 우측 하단 x = 2 + 5 = **7**
- 우측 하단 y = 10 - 3 = **7**
