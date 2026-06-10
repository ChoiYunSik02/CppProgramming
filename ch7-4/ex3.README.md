## ch7-4 연습문제 2번 - += / ++ 연산자 중복
 
### (1) 멤버 함수 버전 - 소스코드 설명
 
```cpp
Coffee& operator+=(Coffee& op);
```
> `+= Coffee` 연산자 선언. 참조를 반환해 `a += b += c` 연속 사용 가능.
 
```cpp
Coffee& operator+=(int n);
```
> `+= 정수` 연산자 선언. 에스프레소에 n을 더한다.
 
```cpp
Coffee& operator++();
```
> 전위 `++` 연산자 선언. 에스프레소를 1 증가시키고 자기 자신의 참조를 반환.
 
```cpp
Coffee operator++(int);
```
> 후위 `++` 연산자 선언. 매개변수 `int`는 전위와 구분하기 위한 더미(dummy) 인자.
 
```cpp
Coffee& Coffee::operator+=(Coffee& op) {
```
> `+=` 연산자 정의. 자기 자신(`*this`)에 직접 더하고 참조를 반환.
 
```cpp
    this->water += op.water;
    this->espresso += op.espresso;
    this->sugar += op.sugar;
    this->cream += op.cream;
    return *this;
```
> 각 멤버를 op의 값만큼 누적하고 자기 자신의 참조를 반환한다.
 
```cpp
Coffee& Coffee::operator++() {
```
> 전위 `++` 정의. 에스프레소를 먼저 증가시키고 자신을 반환.
 
```cpp
    this->espresso++;
    return *this;
```
> 에스프레소 1 증가 후 변경된 객체의 참조를 반환한다.
 
```cpp
Coffee Coffee::operator++(int) {
```
> 후위 `++` 정의. 증가 전 상태를 복사해 반환해야 한다.
 
```cpp
    Coffee tmp = *this;
    this->espresso++;
    return tmp;
```
> 증가 전 상태를 `tmp`에 저장하고, 에스프레소를 증가시킨 뒤 원래 값을 반환한다.
 
---
 
### (2) 프렌드 함수 버전 - 소스코드 설명
 
```cpp
friend Coffee& operator++(Coffee& op);
```
> 전위 `++` 프렌드 선언. 객체를 참조로 받아 직접 수정하고 반환.
 
```cpp
friend Coffee  operator++(Coffee& op, int);
```
> 후위 `++` 프렌드 선언. `int` 더미 인자로 전위와 구분.
 
```cpp
Coffee& operator++(Coffee& op) {
    op.espresso++;
    return op;
}
```
> 프렌드 전위 `++`. `op`의 에스프레소를 증가시키고 `op` 참조를 반환한다.
 
```cpp
Coffee operator++(Coffee& op, int) {
    Coffee tmp = op;
    op.espresso++;
    return tmp;
}
```
> 프렌드 후위 `++`. 증가 전 복사본을 반환하고 원본은 증가시킨다.
 
#### 실행 결과
<img width="833" height="137" alt="image" src="https://github.com/user-attachments/assets/ba866415-e7a7-42b6-b69e-c21e7fcb2e21" />

 
---
