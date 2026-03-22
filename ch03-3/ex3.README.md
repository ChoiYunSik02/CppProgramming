# 3-3장 실습과제 3번 소스코드 설명

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
- `Triangle();` : 매개변수 없이 기본값으로 객체를 생성하는 위임 생성자를 선언한다.
- `Triangle(int a, int b);` : 밑변과 높이를 매개변수로 받아 객체를 생성하는 타겟 생성자를 선언한다.
- `~Triangle();` : 객체가 소멸될 때 자동으로 호출되는 소멸자를 선언한다.
- `double getArea();` : 삼각형의 면적을 계산하여 실수형으로 반환하는 멤버 함수를 선언한다.

---

## 3. 위임 생성자 구현

```cpp
Triangle::Triangle() : Triangle(1, 1) {}
```

- 매개변수 없는 기본 생성자로, 멤버 초기화 리스트에서 `Triangle(1, 1)` 을 호출하여 초기화를 타겟 생성자에게 위임한다.
- 이 생성자를 통해 객체를 생성하면 width = 1, height = 1 로 자동 설정된다.
- 실습과제 3에서는 두 전역 객체 모두 타겟 생성자를 직접 호출하므로 이 위임 생성자는 사용되지 않는다.

---

## 4. 타겟 생성자 구현

```cpp
Triangle::Triangle(int a, int b) : width(a), height(b) {
    cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 생성" << endl;
}
```

- `: width(a), height(b)` 멤버 초기화 리스트를 통해 전달받은 매개변수 값을 멤버 변수에 직접 초기화한다.
- 생성자 호출 시 `cout` 으로 밑변과 높이를 출력하여 객체가 생성되었음을 알린다.

---

## 5. 소멸자 구현

```cpp
Triangle::~Triangle() {
    cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 소멸" << endl;
}
```

- 객체가 메모리에서 소멸되기 직전에 자동으로 한 번만 호출된다.
- 소멸되는 객체의 밑변과 높이를 출력하여 소멸 사실을 알린다.

---

## 6. getArea() 함수 구현

```cpp
double Triangle::getArea() {
    return (1.0 / 2.0) * width * height;
}
```

- 삼각형 넓이 공식 `(밑변 × 높이) ÷ 2` 를 계산하여 반환한다.
- `1 / 2` 로 작성하면 정수 나눗셈이 되어 결과가 0이 되므로 `1.0 / 2.0` 으로 작성하여 실수 연산이 되도록 한다.

---

## 7. 전역 객체 선언

```cpp
Triangle globalTri1(4, 8); // 전역 객체 생성
Triangle globalTri2(2, 2); // 전역 객체 생성
```

- `globalTri1` 과 `globalTri2` 는 모든 함수 바깥에 선언된 **전역 객체**이다.
- 전역 객체는 `main` 함수가 실행되기 전에 선언된 순서대로 생성자가 호출된다.
- 따라서 프로그램이 시작되자마자 `globalTri1` 의 생성자가 먼저 호출되고, 이어서 `globalTri2` 의 생성자가 호출된다.

---

## 8. main 함수

```cpp
int main() {
    cout << "삼각형의 면적은 " << globalTri1.getArea() << endl;
    cout << "삼각형의 면적은 " << globalTri2.getArea() << endl;
    return 0;
}
```

- 전역 객체이기 때문에 main 함수 내부에서는 별도의 객체 생성 없이 바로 사용할 수 있다.
- `globalTri1.getArea()` : globalTri1 의 면적 `(4 × 8) ÷ 2 = 16` 을 계산하여 출력한다.
- `globalTri2.getArea()` : globalTri2 의 면적 `(2 × 2) ÷ 2 = 2` 를 계산하여 출력한다.
- `return 0;` : main 함수가 종료된다. 전역 객체의 소멸자는 프로그램이 완전히 종료되기 직전에 생성된 역순(LIFO)으로 호출되므로 `globalTri2` 가 먼저 소멸된 후 `globalTri1` 이 소멸된다.

---

## 9. 실행 결과
<img width="822" height="226" alt="image" src="https://github.com/user-attachments/assets/be841e74-63a0-4742-90ce-09faf7860035" />

---

## 10. 실습과제 2와 실행 결과가 다른 이유

실습과제 2와 3의 차이는 객체를 **지역 객체**로 선언하느냐, **전역 객체**로 선언하느냐에 있다.

| 구분 | 실습과제 2 (지역 객체) | 실습과제 3 (전역 객체) |
|:----:|:---------------------:|:---------------------:|
| **선언 위치** | main 함수 내부 | 모든 함수 외부 |
| **생성 시점** | main 함수 실행 중 선언 시점 | main 함수 실행 **전** |
| **소멸 시점** | main 함수 종료 시 | 프로그램 종료 **직전** |
| **생성 순서** | tri1 → tri2 (선언 순서) | globalTri1 → globalTri2 (선언 순서) |
| **소멸 순서** | tri2 → tri1 (역순) | globalTri2 → globalTri1 (역순) |

**실습과제 2** 에서는 tri1, tri2 가 main 함수 내부의 **지역 객체**이므로 main 이 실행된 후 선언문이 실행되는 시점에 생성자가 호출된다. 따라서 생성 메시지 → 면적 출력이 번갈아 등장하며, main 이 끝날 때 지역 객체들이 소멸된다.

**실습과제 3** 에서는 globalTri1, globalTri2 가 **전역 객체**이므로 프로그램이 시작되자마자 main 함수 실행 전에 생성자가 먼저 호출된다. 그 결과 생성 메시지 두 줄이 모두 출력된 뒤에야 main 이 시작되고 면적이 출력된다. 소멸자 역시 main 이 끝난 후 프로그램 종료 직전에 생성 역순으로 호출되므로 소멸 메시지도 맨 마지막에 출력된다.

즉, 실행 결과가 달라지는 핵심 이유는 **생성자와 소멸자가 호출되는 시점** 이 지역 객체와 전역 객체에서 서로 다르기 때문이다.
