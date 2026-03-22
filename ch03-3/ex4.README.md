# 3-3장 실습과제 4번 소스코드 설명

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
class Sphere {
public:
    int radius;
    double getVolume();
    Sphere();
    Sphere(int r);
    ~Sphere();
};
```

- `class Sphere` : Sphere 라는 이름의 클래스를 정의한다.
- `public:` : 이하 멤버들을 클래스 외부에서도 자유롭게 접근할 수 있도록 public 접근 지정자를 선언한다.
- `int radius;` : 구의 반지름 값을 저장하는 정수형 멤버 변수를 선언한다.
- `double getVolume();` : 구의 부피를 계산하여 실수형으로 반환하는 멤버 함수를 선언한다.
- `Sphere();` : 매개변수 없이 기본값으로 객체를 생성하는 위임 생성자를 선언한다.
- `Sphere(int r);` : 반지름을 매개변수로 받아 객체를 생성하는 타겟 생성자를 선언한다.
- `~Sphere();` : 객체가 소멸될 때 자동으로 호출되는 소멸자를 선언한다.

---

## 3. 위임 생성자 구현

```cpp
Sphere::Sphere() : Sphere(1) { }
```

- 매개변수 없는 기본 생성자로, **위임 생성자(Delegating Constructor)** 라고 한다.
- 멤버 초기화 리스트에서 `Sphere(1)` 을 호출하여 초기화 작업 전체를 타겟 생성자에게 위임한다.
- 이 생성자를 통해 객체를 생성하면 radius = 1 로 자동 설정된다.
- 중괄호 내부가 비어 있는 이유는 모든 초기화를 타겟 생성자에게 맡기기 때문이다.

---

## 4. 타겟 생성자 구현

```cpp
Sphere::Sphere(int r) : radius(r) {
    cout << "반지름 " << radius << "인 구 생성" << endl;
}
```

- 반지름을 매개변수로 받는 **타겟 생성자(Target Constructor)** 를 구현한다.
- `: radius(r)` 멤버 초기화 리스트를 통해 전달받은 매개변수 값을 멤버 변수 `radius` 에 직접 초기화한다.
- 위임 생성자가 호출될 때도 결국 이 타겟 생성자가 실행되므로, 생성 메시지 출력은 항상 이 생성자에서만 발생한다.
- `cout` 으로 반지름 값을 출력하여 객체가 생성되었음을 알린다.

---

## 5. 소멸자 구현

```cpp
Sphere::~Sphere() {
    cout << "반지름 " << radius << "인 구 소멸" << endl;
}
```

- 객체가 메모리에서 소멸되기 직전에 자동으로 한 번만 호출된다.
- 소멸되는 객체의 반지름 값을 출력하여 소멸 사실을 알린다.
- 지역 객체는 스택 구조(LIFO)에 따라 생성된 역순으로 소멸되므로, 나중에 생성된 객체의 소멸자가 먼저 호출된다.

---

## 6. getVolume() 함수 구현

```cpp
double Sphere::getVolume() {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}
```

- 구의 부피 공식 `V = (4/3) × π × r³` 을 계산하여 반환한다.
- `4 / 3` 으로 작성하면 정수 나눗셈이 되어 결과가 1이 되므로, `4.0 / 3.0` 으로 작성하여 실수 연산이 되도록 한다.
- π 는 `3.14` 를 사용한다.
- `radius * radius * radius` 는 반지름의 세제곱, 즉 r³ 을 의미한다.

---

## 7. main 함수

```cpp
int main() {
    Sphere sph1;
    cout << "구의 부피는 " << sph1.getVolume() << endl;
    Sphere sph2(3);
    cout << "구의 부피는 " << sph2.getVolume() << endl;
    return 0;
}
```

- `Sphere sph1;` : 매개변수 없는 위임 생성자를 호출하여 sph1 객체를 생성한다. 위임 생성자가 내부적으로 `Sphere(1)` 을 호출하므로 radius = 1 로 초기화된다.
- `sph1.getVolume()` : sph1 의 부피 `(4/3) × 3.14 × 1³ ≈ 4.19` 를 계산하여 출력한다.
- `Sphere sph2(3);` : 반지름 3을 인수로 넘겨 타겟 생성자를 직접 호출하여 sph2 객체를 생성한다. radius = 3 으로 초기화된다.
- `sph2.getVolume()` : sph2 의 부피 `(4/3) × 3.14 × 3³ ≈ 113.04` 를 계산하여 출력한다.
- `return 0;` : main 함수가 종료된다. 지역 객체는 스택 구조(LIFO)에 따라 생성된 역순으로 소멸되므로 sph2 의 소멸자가 먼저 호출된 후 sph1 의 소멸자가 호출된다.

---

## 8. 실행 결과
<img width="814" height="230" alt="스크린샷 2026-03-22 164110" src="https://github.com/user-attachments/assets/83bdb974-ee85-40f9-8d54-7644f29fd406" />

