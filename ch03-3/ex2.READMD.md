# 3-3장 실습과제 2번 소스코드 설명

---

## 1. 헤더 및 네임스페이스

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>` : 표준 입출력 기능을 사용하기 위해 iostream 헤더 파일을 포함한다.
- `using namespace std;` : std 네임스페이스를 선언하여 `cout`, `endl` 앞에 `std::` 를 생략할 수 있도록 한다.

---

## 2. 클래스 선언부

```cpp
class Triangle {
public:
    int width;
    int height;
    Triangle();
    Triangle(int a, int b);
    ~Triangle();
    double getArea();
};
```

- `class Triangle` : Triangle 이라는 이름의 클래스를 정의한다.
- `public:` : 이하 멤버들을 클래스 외부에서도 자유롭게 접근할 수 있도록 public 접근 지정자를 선언한다.
- `int width;` : 삼각형의 밑변 값을 저장하는 정수형 멤버 변수를 선언한다.
- `int height;` : 삼각형의 높이 값을 저장하는 정수형 멤버 변수를 선언한다.
- `Triangle();` : 매개변수 없이 기본값으로 객체를 생성하는 생성자1(위임 생성자)을 선언한다.
- `Triangle(int a, int b);` : 밑변과 높이를 매개변수로 받아 객체를 생성하는 생성자2(타겟 생성자)를 선언한다.
- `~Triangle();` : 객체가 소멸될 때 자동으로 호출되는 소멸자를 선언한다.
- `double getArea();` : 삼각형의 면적을 계산하여 실수형으로 반환하는 멤버 함수를 선언한다.

---

## 3. 위임 생성자 구현

```cpp
Triangle::Triangle() : Triangle(1, 1) { }
```

- 매개변수 없는 기본 생성자로, **위임 생성자(Delegating Constructor)** 라고 한다.
- 멤버 초기화 리스트에서 `Triangle(1, 1)` 을 호출하여 초기화 작업 전체를 타겟 생성자에게 위임한다.
- 중괄호 내부가 비어 있는 이유는 모든 초기화를 타겟 생성자에게 맡기기 때문이다.
- 이 생성자를 통해 객체를 생성하면 width = 1, height = 1 로 자동 설정된다.

---

## 4. 타겟 생성자 구현

```cpp
Triangle::Triangle(int a, int b) : width(a), height(b) {
    cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 생성" << endl;
}
```

- 밑변과 높이를 매개변수로 받는 생성자로, **타겟 생성자(Target Constructor)** 라고 한다.
- `: width(a), height(b)` 는 멤버 초기화 리스트로, 전달받은 매개변수 값을 멤버 변수에 직접 초기화한다.
- 위임 생성자가 호출될 때도 결국 이 타겟 생성자가 실행되므로, 생성 메시지 출력은 항상 이 생성자에서만 발생한다.
- `cout` 으로 밑변과 높이를 출력하여 객체가 생성되었음을 알린다.

---

## 5. 소멸자 구현

```cpp
Triangle::~Triangle() {
    cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 소멸" << endl;
}
```

- 객체가 메모리에서 소멸되기 직전에 자동으로 한 번만 호출된다.
- `cout` 으로 소멸되는 객체의 밑변과 높이를 출력하여 소멸 사실을 알린다.
- 지역 객체는 스택 구조(LIFO)에 따라 생성된 역순으로 소멸되므로, 나중에 생성된 객체의 소멸자가 먼저 호출된다.

---

## 6. getArea() 함수 구현

```cpp
double Triangle::getArea() {
    return (1.0 / 2.0) * width * height;
}
```

- 삼각형 넓이 공식인 `(밑변 × 높이) ÷ 2` 를 계산하여 반환한다.
- `1 / 2` 로 작성하면 정수 나눗셈이 되어 결과가 0이 되므로, `1.0 / 2.0` 으로 작성하여 실수 연산이 되도록 한다.

---

## 7. main 함수

```cpp
int main() {
    Triangle tri1;
    cout << "삼각형의 면적은 " << tri1.getArea() << endl;
    Triangle tri2(2, 4);
    cout << "삼각형의 면적은 " << tri2.getArea() << endl;
    return 0;
}
```

- `Triangle tri1;` : 매개변수 없는 위임 생성자를 호출하여 tri1 객체를 생성한다. 내부적으로 `Triangle(1, 1)` 이 호출되어 width = 1, height = 1 로 초기화된다.
- `tri1.getArea()` : tri1 의 면적을 계산하여 출력한다. 결과는 `(1 × 1) ÷ 2 = 0.5` 이다.
- `Triangle tri2(2, 4);` : 타겟 생성자를 직접 호출하여 tri2 객체를 생성한다. width = 2, height = 4 로 초기화된다.
- `tri2.getArea()` : tri2 의 면적을 계산하여 출력한다. 결과는 `(2 × 4) ÷ 2 = 4` 이다.
- `return 0;` : main 함수가 종료되며, 지역 객체가 생성 역순(LIFO)으로 소멸된다. tri2 소멸 후 tri1 이 소멸된다.

---

## 8. 실행 결과
<img width="816" height="228" alt="image" src="https://github.com/user-attachments/assets/133b4046-8eed-414e-8442-009164f3bed0" />

