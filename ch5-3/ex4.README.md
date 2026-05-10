## ch5-3 실습과제4 - Circle 클래스 plus/minus 체이닝
 
---
 
### 코드 설명
 
**`plus()` 함수**
```cpp
Circle& plus(int n) {
    radius += n;
    return *this;
}
```
반지름에 `n`을 더하고 `*this`(자기 자신)의 참조를 리턴한다.
`Circle&`(참조)를 리턴하므로 리턴값이 복사본이 아닌 **원본 a** 자체가 된다.
 
**`minus()` 함수 (추가 구현)**
```cpp
Circle& minus(int m) {
    radius -= m;
    return *this;
}
```
`plus()`와 동일한 구조로, 반지름에서 `m`을 빼고 `*this` 참조를 리턴한다.
 
**`return *this`의 의미**
- `this` : 현재 객체를 가리키는 포인터
- `*this` : 포인터를 역참조한 현재 객체 자체
- `Circle&` 리턴이므로 다음 메서드 호출이 계속 원본 `a`에 적용됨
**체이닝 계산 흐름**
```
a(5)
.plus(1)   → radius = 5 + 1 = 6,  원본 a 참조 리턴
.plus(2)   → radius = 6 + 2 = 8,  원본 a 참조 리턴
.plus(3)   → radius = 8 + 3 = 11, 원본 a 참조 리턴
.minus(3)  → radius = 11 - 3 = 8, 원본 a 참조 리턴
.minus(2)  → radius = 8 - 2 = 6,  원본 a 참조 리턴
.minus(1)  → radius = 6 - 1 = 5,  원본 a 참조 리턴
.minus(5)  → radius = 5 - 5 = 0,  원본 a 참조 리턴
 
최종 a.radius = 0
```
 
**만약 `Circle&` 대신 `Circle`(값)로 리턴했다면?**
```
a(5)
.plus(1) → a(6), 복사본 리턴
.plus(2) → 복사본(8), a에는 미반영
...
a.getRadius() = 6  (첫 번째 plus만 a에 반영)
```
참조 리턴이기 때문에 모든 연산이 원본 `a`에 누적 반영되어 최종적으로 `0`이 출력된다.
 
### 실행 결과
<img width="833" height="122" alt="image" src="https://github.com/user-attachments/assets/fd566796-1825-4418-ae1e-b8a87fe4e4b6" />

