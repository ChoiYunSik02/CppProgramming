# 3-4장 실습과제4

---

## 소스 코드 설명

```cpp
// **********************************************
// 제 목 : 3-4장 실습과제 4번
// 날 짜 : 2026년 03월 24일
// 작성자 : 2101091 최윤식
// **********************************************
```
소스 파일의 제목, 작성 날짜, 작성자 정보를 나타내는 주석 헤더이다.

---

```cpp
#include <iostream>
using namespace std;
```
`iostream` 헤더 파일을 포함하여 표준 입출력 기능을 사용할 수 있도록 한다.  
`std` 네임스페이스를 전역으로 선언하여 `cout`, `endl` 등을 접두사 없이 사용한다.

---

```cpp
class Triangle {
```
`Triangle`이라는 이름의 클래스를 선언한다.

---

```cpp
private:
    int width;  // 밑변
    int height; // 높이
```
삼각형의 밑변과 높이를 저장하는 멤버 변수 `width`, `height`를 `private`으로 선언한다.  
`private` 선언으로 외부에서 직접 접근이 불가능하며, setter/getter 함수를 통해서만 접근할 수 있다.

---

```cpp
public:
    Triangle();
    Triangle(int a, int b);
    ~Triangle();
    void setWidth(int a);
    void setHeight(int b);
    int getWidth();
    int getHeight();
    double getArea();
```
외부에서 접근 가능한 `public` 멤버들을 선언한다.  
생성자 2개, 소멸자 1개, setter 함수 2개, getter 함수 2개, 면적 계산 함수 1개로 구성된다.

---

```cpp
Triangle::Triangle() : Triangle(1, 1) {} // 위임 생성자
```
매개변수가 없는 기본 생성자이다.  
`: Triangle(1, 1)` 문법을 사용하여 매개변수가 있는 타겟 생성자에게 초기화를 **위임**한다.  
이 경우 `a = 1`, `b = 1`이 전달되므로 양수 조건을 만족하여 정상 생성 메시지가 출력된다.

---

```cpp
Triangle::Triangle(int a, int b) { // 타켓 생성자
    if (a < 0 || b < 0) {
        width = 1; height = 1;
        cout << "길이는 양수여야함, 대신에 폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
    }
    else {
        width = a; height = b;
        cout << "폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
    }
}
```
매개변수 `a`, `b`를 받아 멤버 변수를 초기화하는 **타겟 생성자**이다.  
입력값 `a` 또는 `b` 중 하나라도 음수이면 `width = 1`, `height = 1`로 **대체 초기화**하고 경고 메시지를 출력한다.  
두 값 모두 양수이면 입력값 그대로 `width = a`, `height = b`로 초기화하고 생성 메시지를 출력한다.  
실습과제3과의 차이점은 **생성자 단계에서 유효성 검사를 추가**한 것이다.

---

```cpp
Triangle::~Triangle() { // 소멸자
    cout << "폭" << width << ", " << "높이" << height << " 삼각형 소멸" << endl;
}
```
객체가 메모리에서 해제될 때 자동으로 호출되는 **소멸자(Destructor)** 이다.  
소멸 시점의 `width`, `height` 값을 출력한다.  
`main` 함수의 `return 0` 이후 지역 객체 `tri`의 수명이 종료되면서 자동 호출된다.

---

```cpp
void Triangle::setWidth(int a) {
    if (a < 0) cout << "폭은 양수이어야 함 " << endl;
    else width = a;
}
```
`width`에 새로운 값을 저장하는 **setter 함수**이다.  
**입력값 `a`** 를 검사하여 음수이면 경고 메시지를 출력하고 값을 저장하지 않는다.  
양수인 경우에만 `width = a`로 저장한다.

---

```cpp
void Triangle::setHeight(int b) {
    if (b < 0) cout << "높이는 양수이어야 함 " << endl;
    else height = b;
}
```
`height`에 새로운 값을 저장하는 **setter 함수**이다.  
**입력값 `b`** 를 검사하여 음수이면 경고 메시지를 출력하고 값을 저장하지 않는다.  
양수인 경우에만 `height = b`로 저장한다.

---

```cpp
int Triangle::getWidth() { return width; }   // 밑변변수의 값 읽기
int Triangle::getHeight() { return height; } // 높이변수의 값 읽기
```
`private` 멤버 변수 `width`와 `height`의 현재 값을 반환하는 **getter 함수**이다.

---

```cpp
double Triangle::getArea() {
    return (1.0 / 2.0) * width * height;
}
```
삼각형의 넓이를 계산하여 반환하는 함수이다.  
삼각형 넓이 공식 `(밑변 × 높이) / 2`를 적용한다.  
`1.0 / 2.0`으로 실수 나눗셈을 수행하여 결과가 `double` 타입으로 반환된다.

---

```cpp
Triangle tri(-10, -5); // 음수 테스트
```
`-10`, `-5`를 인자로 전달하여 `tri` 객체를 생성한다.  
두 값 모두 음수이므로 타겟 생성자의 조건 분기에서 `width = 1`, `height = 1`로 대체 초기화되고 경고 메시지가 출력된다.

---

```cpp
tri.setWidth(-3);  // 음수 테스트
tri.setHeight(-5); // 음수 테스트
```
음수 값을 setter에 전달하여 유효성 검사를 테스트한다.  
입력값이 음수이므로 각각 경고 메시지만 출력되고 `width`, `height` 값은 변경되지 않는다.

---

```cpp
tri.setWidth(3);  // 양수 테스트
tri.setHeight(5); // 양수 테스트
```
양수 값을 setter에 전달한다.  
입력값이 양수이므로 `width = 3`, `height = 5`로 정상 저장된다.

---

```cpp
cout << "삼각형의 폭은 " << tri.getWidth() << endl;
cout << "삼각형의 높이는 " << tri.getHeight() << endl;
```
getter 함수를 통해 최종 저장된 `width`, `height` 값을 출력한다.

---

```cpp
return 0;
```
`main` 함수가 정상 종료되었음을 운영체제에 알린다.  
이 시점에 지역 객체 `tri`의 소멸자가 자동으로 호출된다.

---

## 실행 결과
<img width="813" height="234" alt="스크린샷 2026-03-24 231140" src="https://github.com/user-attachments/assets/05753b17-8cda-4562-a84f-7bbcc5131bb9" />



---

## 실습과제3과의 차이점

| 항목 | 실습과제3 | 실습과제4 |
|---|---|---|
| 생성자 유효성 검사 | 없음 | 음수 입력 시 `1, 1`로 대체 초기화 |
| setter 유효성 검사 | 없음 | 음수 입력 시 경고 메시지 출력 후 저장 거부 |
| 잘못된 입력 처리 | 음수 그대로 저장됨 | 음수 입력 방어 로직 포함 |

> setter 함수에서 **입력값 매개변수(`a`, `b`)** 를 검사해야 하며,  
> 멤버 변수(`width`, `height`) 자체를 검사하면 기존 값이 음수일 때만 걸리는 잘못된 로직이 된다.
