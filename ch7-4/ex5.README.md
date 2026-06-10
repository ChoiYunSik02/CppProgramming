## ch7-4 연습문제 4번 - << 연산자 중복 (Coffee용)
 
### (1) 멤버 함수 버전
 
```cpp
Coffee& operator<<(Coffee& op);
```
> `a << b` 형태로 커피 b를 a에 합치는 `<<` 연산자 선언.
 
```cpp
Coffee& operator<<(int n);
```
> `a << n` 형태로 물을 n만큼 추가하는 `<<` 연산자 선언.
 
```cpp
Coffee& Coffee::operator<<(Coffee& op) {
```
> `<<` 연산자 정의. `+=`와 유사하게 자기 자신에 더하고 참조를 반환.
 
```cpp
    this->water += op.water;
    this->espresso += op.espresso;
    this->sugar += op.sugar;
    this->cream += op.cream;
    return *this;
```
> Coffee를 합치고 자기 자신의 참조를 반환해 `a << b << 3` 연속 사용 가능.
 
```cpp
Coffee& Coffee::operator<<(int n) {
    this->water += n;
    return *this;
}
```
> 물에 n을 더하고 자기 자신의 참조를 반환한다.
 
---
 
### (2) 프렌드 함수 버전
 
```cpp
friend Coffee& operator<<(Coffee& op1, Coffee& op2);
```
> `<<` 연산자 프렌드 선언. `op1`에 `op2`를 합친다.
 
```cpp
friend Coffee& operator<<(Coffee& op1, int n);
```
> `<<` 연산자 프렌드 선언. `op1`의 물에 n을 더한다.
 
```cpp
Coffee& operator<<(Coffee& op1, Coffee& op2) {
    op1.water += op2.water;
    ...
    return op1;
}
```
> `op1`에 `op2`를 합치고 `op1`의 참조를 반환한다.
 
```cpp
Coffee& operator<<(Coffee& op1, int n) {
    op1.water += n;
    return op1;
}
```
> `op1`의 물을 n 증가시키고 `op1`의 참조를 반환한다.
 
#### 실행 결과
<img width="816" height="133" alt="image" src="https://github.com/user-attachments/assets/002a4aef-6254-4ece-97c5-19e3f6b99dae" />

