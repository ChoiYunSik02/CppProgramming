# 4-1장 실습과제1

---

## 1. 배열명의 의미

배열명은 **배열의 첫 번째 원소의 주소(포인터 상수)** 를 의미한다.

```cpp
Circle circleArray[3];
```

위와 같이 선언하면 `circleArray`는 `circleArray[0]`의 주소를 나타내는 **포인터 상수**이다.  
일반 포인터 변수와 달리 값을 변경할 수 없다 (`circleArray++` 불가).

| 표현 | 의미 |
|------|------|
| `circleArray` | 첫 번째 원소(`circleArray[0]`)의 주소 |
| `circleArray + 1` | 두 번째 원소(`circleArray[1]`)의 주소 |
| `circleArray + 2` | 세 번째 원소(`circleArray[2]`)의 주소 |

---

## 2. 객체 포인터의 의미

객체 포인터란 **객체의 주소를 저장하는 변수**이다.  
구조체 포인터와 동일한 방식으로 동작하며, 선언 방법은 다음과 같다.

```
클래스명* 객체포인터명;
```

```cpp
Circle donut;
Circle* p;   // 객체 포인터 선언
p = &donut;  // donut 객체의 주소를 p에 저장
```

- **객체(값)** : 멤버 변수와 멤버 함수가 저장된 변수
- **객체 포인터** : 객체의 **주소**가 저장된 변수 → 객체 그 자체가 아님
- `*p`와 `donut`은 동일한 객체를 가리킨다

멤버 접근 방법은 두 가지이다.

```cpp
(*p).getArea();  // 역참조 후 점(.) 연산자 사용
p->getArea();    // 화살표(->) 연산자 사용 (동일한 의미)
```

---

## 3. 포인터를 이용하여 배열 각 원소의 주소를 구하는 방법

포인터에 배열명을 대입한 뒤, **포인터 산술 연산(+n)** 으로 각 원소의 주소를 구할 수 있다.

```cpp
Circle circleArray[3];
Circle* p = circleArray;  // p는 circleArray[0]의 주소
```

| 표현 | 의미 |
|------|------|
| `p` 또는 `circleArray` | `circleArray[0]`의 주소 |
| `p + 1` 또는 `circleArray + 1` | `circleArray[1]`의 주소 |
| `p + 2` 또는 `circleArray + 2` | `circleArray[2]`의 주소 |

> 포인터 `+n`은 **단순히 n을 더하는 것이 아니라**, 해당 자료형의 크기(sizeof) × n 만큼 주소가 이동한다.

---

## 4. 포인터를 이용하여 배열 각 원소의 값을 구하는 방법

포인터를 통해 배열 원소의 값(객체)에 접근하는 방법은 다음과 같이 다양하다.

```cpp
Circle circleArray[3];
Circle* p = circleArray;
```

**방법 1 : `(포인터 + i)->멤버함수()` 방식**

```cpp
for (int i = 0; i < 3; i++)
    cout << (p + i)->getArea() << endl;
```

**방법 2 : `포인터[i].멤버함수()` 방식 (배열 인덱스처럼 사용)**

```cpp
for (int i = 0; i < 3; i++)
    cout << p[i].getArea() << endl;
```

**방법 3 : `p++`로 포인터를 직접 증가시키는 방식**

```cpp
for (int i = 0; i < 3; i++) {
    cout << p->getArea() << endl;
    p++;  // 포인터를 다음 원소로 이동
}
```

**방법 4 : `역참조(*p)` 방식**

```cpp
for (int i = 0; i < 3; i++)
    cout << (*(p + i)).getArea() << endl;
```

> 위 4가지 방법은 모두 동일한 결과를 출력하며, 상황에 따라 적절한 방법을 선택하여 사용한다.
