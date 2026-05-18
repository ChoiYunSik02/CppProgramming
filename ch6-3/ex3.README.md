# ch6-3 실습과제 3 소스코드 설명 — Triangle 클래스

## 문제 요약

`Triangle` 객체가 생성/소멸될 때마다 **현재 생존 중인 객체 수**를 추적한다.  
`static` 멤버 변수로 모든 객체가 카운터를 공유하고, `static` 함수로 조회한다.

---

## 전체 구조

```
Triangle 클래스
├── [private] static int numOfTriangle   ← 생존 객체 수 (공유 카운터)
├── [public]  Triangle()                 ← 생성자: 카운터 +1
├── [public]  ~Triangle()                ← 소멸자: 카운터 -1
└── [public]  static getNumofTriangle()  ← 카운터 값 반환
```

---

## 클래스 선언 상세 설명

### static 멤버 변수

```cpp
private:
    static int numOfTriangle;
```

| 항목 | 설명 |
|------|------|
| `static` | 모든 Triangle 객체가 **하나의 변수를 공유** |
| `private` | 외부 직접 접근 불가, `getNumofTriangle()`을 통해서만 조회 |
| 초기값 | 클래스 외부에서 `int Triangle::numOfTriangle = 0;` 으로 0 초기화 |

### 생성자

```cpp
Triangle() {
    numOfTriangle++;  // 객체 생성마다 카운터 1 증가
}
```

### 소멸자

```cpp
~Triangle() {
    numOfTriangle--;  // 객체 소멸마다 카운터 1 감소
}
```

> ⚠️ 소멸자가 없으면 `delete[]` 후에도 카운터가 줄지 않아 잘못된 값이 출력된다.

### static 멤버 함수

```cpp
static int getNumofTriangle() {
    return numOfTriangle;  // 현재 생존 중인 객체 수 반환
}
```

---

## 전역 선언 (static 멤버 변수 정의)

```cpp
int Triangle::numOfTriangle = 0;
```

- 클래스 내부의 `static int numOfTriangle;`은 **선언**만 하고 메모리를 할당하지 않음
- 반드시 **클래스 외부 전역 공간**에서 이렇게 **정의**해야 실제 메모리가 생성됨
- 초기값 `0`으로 설정 (프로그램 시작 시 삼각형 0개)

---

## main 함수 실행 흐름

```cpp
Triangle* tri1 = new Triangle[5];
```
→ 생성자 5번 호출 → `numOfTriangle = 0 + 5 = 5`

```cpp
cout << Triangle::getNumofTriangle() << endl;  // 출력: 5
```

```cpp
delete[] tri1;
```
→ 소멸자 5번 호출 → `numOfTriangle = 5 - 5 = 0`

```cpp
Triangle tri2[15];
```
→ 생성자 15번 호출 → `numOfTriangle = 0 + 15 = 15`

```cpp
cout << Triangle::getNumofTriangle() << endl;  // 출력: 15
```

---

## 객체 생명주기 시각화

```
프로그램 시작
  numOfTriangle = 0
      ↓
new Triangle[5]  →  생성자 ×5  →  numOfTriangle = 5
      ↓
cout → "생성된 삼각형의 개수 :5"
      ↓
delete[] tri1    →  소멸자 ×5  →  numOfTriangle = 0
      ↓
Triangle tri2[15] →  생성자 ×15  →  numOfTriangle = 15
      ↓
cout → "생성된 삼각형의 개수 :15"
      ↓
main 종료 → tri2 소멸자 ×15 → numOfTriangle = 0
```

---

## 실행 결과
<img width="837" height="156" alt="image" src="https://github.com/user-attachments/assets/4d695434-d1b9-4163-b2ab-30eea0348929" />


---

## 핵심 포인트 정리

> ✅ `static` 멤버 변수는 **모든 객체가 하나의 값을 공유** → 카운터 역할에 적합  
> ✅ **생성자**에서 +1, **소멸자**에서 -1 → 현재 생존 객체 수를 항상 정확히 추적  
> ✅ `delete[]`는 배열 원소 수만큼 소멸자를 자동 호출  
> ✅ static 멤버 변수는 반드시 **클래스 외부에서 정의** (`int Triangle::numOfTriangle = 0;`)
