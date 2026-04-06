# ch04-3 실습과제 5번 소스코드 설명

## 1. 프로그램 개요
이 프로그램은 **C++ 클래스와 동적 메모리 할당(new / delete[])**의 개념을 연습하기 위한 예제이다.  
`Sphere` 클래스를 정의하고, 여러 개의 객체를 동적으로 생성하여 각 구의 반지름을 입력받은 후 부피를 계산하고 메모리를 해제한다.

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

## 3. Sphere 클래스 정의

```cpp
class Sphere {
    int radius;
```

- radius : 구의 반지름  
- 접근 지정자를 생략했으므로 기본값인 private 멤버 변수

---

## 4. 멤버 함수

### 4.1 setRadius 함수

```cpp
void setRadius(int r) {
    radius = r;
}
```

- 전달받은 반지름 값을 멤버 변수 radius에 저장한다.

---

### 4.2 getVolume 함수

```cpp
double getVolume() {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}
```

- 구의 부피를 계산하여 반환한다.  
- 구의 부피 공식 사용  
- 부피 = 4/3 × π × r³

---

## 5. main 함수

### 5.1 구의 개수 입력

```cpp
int n;
cout << "생성하고자 하는 구의 개수: ";
cin >> n;
```

- 사용자로부터 생성할 구의 개수를 입력받는다.

---

### 5.2 Sphere 객체 배열의 동적 생성

```cpp
Sphere* arr = new Sphere[n];
```

- 입력받은 개수만큼 Sphere 객체를 동적 배열로 생성한다.

---

### 5.3 반지름 입력 및 설정

```cpp
for (int i = 0; i < n; i++) {
    int r;
    cout << "구" << i + 1 << "의 반지름: ";
    cin >> r;
    arr[i].setRadius(r);
}
```

- 반복문을 이용하여 각 구의 반지름을 입력받는다.  
- setRadius() 함수를 통해 각 객체의 반지름 값을 설정한다.

---

### 5.4 구의 부피 출력

```cpp
for (int i = 0; i < n; i++) {
    cout << "구" << i + 1 << "의 부피 " << arr[i].getVolume() << "\n";
}
```

- 반복문을 사용하여 각 구의 부피를 계산한다.  
- getVolume() 함수를 호출하여 결과를 출력한다.

---

### 5.5 동적 메모리 해제

```cpp
delete[] arr;
```

- new[]로 할당한 메모리는 반드시 delete[]로 해제해야 한다.  
- 메모리 누수를 방지할 수 있다.

---


## 6. 실행 결과
<img width="841" height="255" alt="스크린샷 2026-04-07 012533" src="https://github.com/user-attachments/assets/864c8d8c-0f24-4bd8-8502-db09dbfdb362" />

