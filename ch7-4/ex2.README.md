# ch07-4 연습문제 1번 - Coffee 클래스 +연산자 중복
 
---
 
## 공통 Coffee 클래스
 
```cpp
class Coffee {
```
> 물, 에스프레소, 설탕, 크림으로 구성된 커피를 표현하는 클래스.
 
```cpp
    int water, espresso, sugar, cream;
```
> 커피의 구성 요소를 저장하는 `private` 멤버 변수 4개.
 
```cpp
    Coffee(int water=1, int coffee=1, int sugar=0, int cream=0) {
```
> 기본값이 있는 생성자. 인자 없이 생성하면 `water=1, espresso=1, sugar=0, cream=0`으로 초기화.
 
```cpp
        this->water = water; this->espresso = coffee;
        this->sugar = sugar; this->cream = cream;
```
> 매개변수를 멤버 변수에 대입한다. `espresso`는 매개변수명이 `coffee`이므로 주의.
 
```cpp
    void show() { ... }
```
> 커피 구성 요소를 `물 N, 커피 N, 설탕 N, 크림 N` 형식으로 출력한다.
 
---
 
## 1번 - + 연산자 중복
 
### (1) 멤버 함수 버전
 
```cpp
Coffee operator+(Coffee& op);
```
> `Coffee + Coffee` 연산을 처리하는 멤버 함수 선언.
 
```cpp
Coffee operator+(int n);
```
> `Coffee + 정수` 연산을 처리하는 멤버 함수 선언. 에스프레소만 n만큼 증가.
 
```cpp
Coffee Coffee::operator+(Coffee& op) {
```
> `+` 연산자 정의. `this`가 왼쪽 피연산자, `op`가 오른쪽 피연산자.
 
```cpp
    Coffee tmp;
```
> 연산 결과를 담을 임시 Coffee 객체 생성.
 
```cpp
    tmp.water = this->water + op.water;
    tmp.espresso = this->espresso + op.espresso;
    tmp.sugar = this->sugar + op.sugar;
    tmp.cream = this->cream + op.cream;
```
> 두 Coffee 객체의 각 멤버를 더해 임시 객체에 저장한다.
 
```cpp
    return tmp;
```
> 합산된 새 Coffee 객체를 반환한다.
 
```cpp
Coffee Coffee::operator+(int n) {
```
> `Coffee + 정수` 연산자 정의. 에스프레소에만 n을 더한다.
 
```cpp
    tmp.espresso = this->espresso + n;
```
> 에스프레소만 n 증가. 나머지 멤버는 그대로 복사.
 
---
 
### (2) 프렌드 함수 버전
 
```cpp
friend Coffee operator+(Coffee& op1, Coffee& op2);
```
> `+` 연산자를 프렌드 함수로 선언. 두 피연산자를 모두 매개변수로 받는다.
 
```cpp
friend Coffee operator+(Coffee& op1, int n);
```
> `Coffee + 정수` 연산자 프렌드 선언.
 
```cpp
Coffee operator+(Coffee& op1, Coffee& op2) {
```
> 프렌드 함수 정의. 클래스 외부 함수지만 `private` 멤버에 직접 접근 가능하다.
 
```cpp
    tmp.water = op1.water + op2.water;
```
> 멤버 함수와 달리 `this` 대신 `op1`으로 왼쪽 피연산자에 접근한다.
 
#### 실행 결과
<img width="830" height="159" alt="image" src="https://github.com/user-attachments/assets/fbc7b1a4-e3f0-46ed-9b59-01d8aaeaaa19" />

 
---
