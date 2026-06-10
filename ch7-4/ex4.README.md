## ch7-4 연습문제 3번 - ! / > 연산자 중복
 
### (1) 멤버 함수 버전
 
```cpp
bool operator!();
```
> 단항 `!` 연산자 선언. 설탕이 0이면 `true`를 반환한다.
 
```cpp
bool operator>(Coffee& op);
```
> 이항 `>` 연산자 선언. 물 양을 비교해 왼쪽이 더 많으면 `true` 반환.
 
```cpp
bool Coffee::operator!() {
```
> `!` 연산자 정의. 피연산자가 하나이므로 매개변수 없이 `this`만 사용.
 
```cpp
    if (sugar == 0) return true;
    return false;
```
> 설탕이 0이면 `true`, 아니면 `false` 반환. `!a`가 true면 설탕 없음.
 
```cpp
bool Coffee::operator>(Coffee& op) {
```
> `>` 연산자 정의. `this->water`와 `op.water`를 비교한다.
 
```cpp
    if (this->water > op.water) return true;
    return false;
```
> 왼쪽 Coffee의 물이 더 많으면 `true`, 아니면 `false` 반환.
 
---
 
### (2) 프렌드 함수 버전
 
```cpp
friend bool operator!(Coffee& op);
```
> `!` 연산자 프렌드 선언. 단항이므로 매개변수가 1개.
 
```cpp
friend bool operator>(Coffee& op1, Coffee& op2);
```
> `>` 연산자 프렌드 선언. 이항이므로 매개변수가 2개.
 
```cpp
bool operator!(Coffee& op) {
    if (op.sugar == 0) return true;
    return false;
}
```
> `op`의 설탕이 0이면 `true` 반환. `private` 멤버에 직접 접근 가능.
 
```cpp
bool operator>(Coffee& op1, Coffee& op2) {
    if (op1.water > op2.water) return true;
    return false;
}
```
> `op1`의 물이 `op2`보다 많으면 `true` 반환.
 
#### 실행 결과
<img width="822" height="150" alt="image" src="https://github.com/user-attachments/assets/4002e26a-d0b5-4867-b6dd-379f08f5172e" />

 
---
