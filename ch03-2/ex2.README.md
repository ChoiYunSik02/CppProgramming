# 3-2장 실습과제 2번 - 소스코드 설명

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
class Triangle {
public:
    int width, height;
    double getArea();
    Triangle();
    Triangle(int a, int b);
};
```

| 멤버 | 종류 | 설명 |
|---|---|---|
| `width` | 멤버변수 | 삼각형의 밑변 |
| `height` | 멤버변수 | 삼각형의 높이 |
| `getArea()` | 멤버함수 | 삼각형 면적을 계산하여 반환 |
| `Triangle()` | 위임 생성자 | 인자 없이 객체 생성 시 호출, 타겟 생성자에 위임 |
| `Triangle(int a, int b)` | 타겟 생성자 | 실제 초기화 작업을 담당 |

- `public` : 클래스 외부에서 모든 멤버에 자유롭게 접근 가능
- 반환형이 `double`인 이유 : 삼각형 면적 공식에서 `1/2`를 곱하므로 소수점이 발생할 수 있기 때문

---

## 멤버함수 구현

### getArea() — 면적 계산

```cpp
double Triangle::getArea() {
    return (1.0/2.0) * width * height;
}
```

- 삼각형 면적 공식 : **밑변 × 높이 ÷ 2**
- `1.0/2.0` 으로 작성한 이유 : `1/2`로 쓰면 정수 나눗셈이 되어 결과가 `0`이 되기 때문에, 실수 나눗셈이 되도록 `1.0/2.0`으로 작성
- 계산 결과를 `double`로 반환

---

### Triangle() — 위임 생성자

```cpp
Triangle::Triangle() : Triangle(1, 1) { }
```

- 인자 없이 객체를 생성할 때 호출되는 생성자
- 직접 초기화하지 않고 `Triangle(1, 1)` 즉, **타겟 생성자에게 초기화를 위임**
- `width = 1`, `height = 1` 로 초기화됨
- 몸체 `{ }` 가 비어있는 이유 : 실제 초기화는 타겟 생성자가 담당하기 때문

---

### Triangle(int a, int b) — 타겟 생성자

```cpp
Triangle::Triangle(int a, int b) : width(a), height(b) { }
```

- 두 정수를 인자로 받아 직접 멤버변수를 초기화하는 생성자
- **멤버 초기화 리스트** `width(a), height(b)` 를 사용하여 객체 생성과 동시에 초기화
- 위임 생성자와 일반 호출 모두 이 생성자를 통해 최종 초기화가 이루어짐
- 몸체 `{ }` 가 비어있는 이유 : 초기화 리스트에서 모든 초기화가 완료되기 때문

---

## main() 함수

```cpp
int main() {
    Triangle tri1;
    cout << "삼각형의 면적은 " << tri1.getArea() << endl;

    Triangle tri2(2, 4);
    cout << "삼각형의 면적은 " << tri2.getArea() << endl;

    return 0;
}
```

| 코드 | 설명 |
|---|---|
| `Triangle tri1` | 인자 없이 객체 생성 → 위임 생성자 호출 → width=1, height=1 |
| `tri1.getArea()` | 1 × 1 × 0.5 = **0.5** 출력 |
| `Triangle tri2(2, 4)` | 인자를 주어 객체 생성 → 타겟 생성자 호출 → width=2, height=4 |
| `tri2.getArea()` | 2 × 4 × 0.5 = **4** 출력 |

---

## 생성자 호출 흐름

```
tri1 생성
  └→ Triangle()          (위임 생성자 호출)
       └→ Triangle(1, 1) (타겟 생성자로 위임 → width=1, height=1)

tri2 생성
  └→ Triangle(2, 4)      (타겟 생성자 직접 호출 → width=2, height=4)
```

---

## 실행 결과
<img width="795" height="153" alt="Image" src="https://github.com/user-attachments/assets/729b414d-1de4-4dfd-ad3a-324e89b5ab64" />

---

## 핵심 포인트 정리

| 개념 | 설명 |
|---|---|
| 위임 생성자 | 초기화를 직접 하지 않고 타겟 생성자에게 넘김 |
| 타겟 생성자 | 실제 멤버변수 초기화를 담당하는 생성자 |
| 멤버 초기화 리스트 | 생성자 몸체 대신 `: width(a), height(b)` 형식으로 초기화 |
| `1.0/2.0` | 정수 나눗셈 오류를 방지하기 위한 실수형 표현 |
