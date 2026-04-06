# ch04-3 실습과제 4번 소스코드 설명

## 1. 프로그램 개요
이 프로그램은 **C++ 클래스와 생성자, 소멸자, 동적 메모리 할당(new / delete[])**의 개념을 연습하기 위한 예제이다.  
`Triangle` 클래스를 정의하고, 여러 개의 객체를 동적으로 생성하여 삼각형의 면적을 계산한 뒤 메모리를 해제한다.

---

## 2. 헤더 파일 및 네임스페이스

```cpp
#include <iostream>
using namespace std;
```

- iostream  
  - 입력(cin)과 출력(cout)을 사용하기 위한 표준 헤더 파일

- using namespace std;  
  - std:: 접두어를 생략하고 표준 라이브러리를 편리하게 사용하기 위함

---

## 3. Triangle 클래스 정의

```cpp
class Triangle {
    int base, height;
```

- base : 삼각형의 밑변  
- height : 삼각형의 높이  
- 접근 지정자를 생략했으므로 기본값인 private 멤버 변수

---

## 4. 생성자(Constructor)

### 4.1 기본 생성자

```cpp
Triangle() {
    base = 1; height = 1;
}
```

- 매개변수가 없는 생성자  
- 객체가 생성될 때 밑변과 높이를 1로 초기화  
- 초기값이 필요한 경우를 대비한 기본 생성자

---

### 4.2 매개변수 생성자

```cpp
Triangle(int b, int h) {
    base = b;
    height = h;
    cout << "밑변 " << base << " 높이 " << height << "인 삼각형 생성\n";
}
```

- 밑변(b)과 높이(h)를 받아 멤버 변수에 저장  
- 객체가 생성될 때 생성 정보 출력  
- 생성자 실행 순서를 확인하는 데 도움을 줌

---

## 5. 소멸자(Destructor)

```cpp
~Triangle() {
    cout << "밑변 " << base << " 높이 " << height << "인 삼각형 소멸\n";
}
```

- 객체가 소멸될 때 자동으로 호출됨  
- 동적 할당된 객체가 해제되는 시점을 확인하기 위해 메시지 출력  
- delete[]가 호출될 때 배열의 각 객체마다 소멸자가 실행됨

---

## 6. 멤버 함수 getArea()

```cpp
double getArea() {
    return 0.5 * base * height;
}
```

- 삼각형의 면적을 계산하여 반환  
- 삼각형 면적 공식 사용  
- 면적 = 1/2 × 밑변 × 높이

---

## 7. main 함수

### 7.1 삼각형 객체 배열의 동적 생성

```cpp
Triangle* tri = new Triangle[3]{
    Triangle(1,1),
    Triangle(2,2),
    Triangle(4,4)
};
```

- Triangle 객체 3개를 동적 배열로 생성  
- 각 원소는 매개변수 생성자를 통해 초기화됨  
- 이 과정에서 생성자 메시지가 3번 출력됨

---

### 7.2 삼각형 면적 출력

```cpp
for (int i = 0; i < 3; i++) {
    cout << "삼각형의 면적은 " << tri[i].getArea() << "\n";
}
```

- 반복문을 이용해 각 삼각형 객체의 면적 계산  
- getArea() 멤버 함수 호출  
- 객체 배열 접근은 tri[i] 형태로 수행

---

### 7.3 동적 메모리 해제

```cpp
delete[] tri;
```

- new[]로 할당한 메모리는 반드시 delete[]로 해제해야 함  
- 배열에 포함된 모든 객체의 소멸자 자동 호출  
- 메모리 누수 방지

---


## 8. 실행 결과
<img width="1111" height="291" alt="스크린샷 2026-04-07 012320" src="https://github.com/user-attachments/assets/3b78fd51-5a06-43f9-8e58-f939976435ee" />



