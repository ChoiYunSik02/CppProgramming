# 실습과제 2 - string 클래스를 이용한 예제 5-11 재작성

---

## 전체 소스코드 설명

```cpp
#include <iostream>
```
> 표준 입출력 라이브러리를 포함한다. `cout`, `endl` 사용을 위해 필요하다.

```cpp
#include <string>
```
> `string` 클래스를 사용하기 위해 포함한다.  
> 예제 5-11의 `#include <cstring>` (c스타일 문자열 함수용)을 이것으로 대체한다.

```cpp
using namespace std;
```
> `std::` 접두사 없이 `cout`, `string` 등을 사용하기 위한 선언이다.

---

```cpp
class Person {
```
> `Person` 클래스 선언을 시작한다.

```cpp
    string name;
```
> **핵심 변경 지점.**  
> 예제 5-11의 `char* name;`을 `string name;`으로 교체한다.  
> `string`은 내부적으로 힙 메모리를 자동 관리하므로 개발자가 `new/delete`를 직접 쓸 필요가 없다.

```cpp
    int id;
```
> 사람의 고유 번호를 저장하는 멤버 변수다. 변경 없음.

```cpp
public:
    Person(int id, const string& name);
```
> 생성자를 선언한다.  
> 매개변수가 `const char* name` → `const string& name`으로 바뀌었다.  
> `const&`로 받으면 문자열 리터럴 `"Kitae"`도 자동으로 `string`으로 변환되어 전달된다.

```cpp
    // 복사 생성자 → 불필요 (string이 자동으로 깊은 복사 수행)
    // 소멸자      → 불필요 (string이 자동으로 메모리 해제)
```
> 예제 5-11에서는 `char*` 때문에 직접 작성해야 했던 두 함수를 제거한다.  
> `string` 멤버 변수는 컴파일러 디폴트 복사 생성자만으로도 깊은 복사가 이루어진다.

```cpp
    void changeName(const string& name);
```
> 이름 변경 함수를 선언한다. 매개변수 타입이 `const char*` → `const string&`으로 변경되었다.

```cpp
    void show() { cout << id << ',' << name << endl; }
```
> `id`와 `name`을 콤마로 구분하여 출력하는 인라인 함수다. 변경 없음.

```cpp
};
```
> 클래스 선언을 종료한다.

---

```cpp
Person::Person(int id, const string& name) {
```
> 생성자 구현부를 시작한다. `::`는 `Person` 클래스에 속한 함수임을 나타낸다.

```cpp
    this->id = id;
```
> 매개변수 `id`를 멤버 변수 `this->id`에 대입한다.

```cpp
    this->name = name;
```
> **핵심.**  
> 예제 5-11에서는 `new char[]` 할당 후 `strcpy()`로 복사했지만,  
> `string`은 대입 연산자(`=`) 하나로 내부 메모리 할당과 복사를 모두 처리한다.

```cpp
}
```
> 생성자 구현을 종료한다.

---

```cpp
void Person::changeName(const string& name) {
```
> `changeName()` 함수 구현부를 시작한다.

```cpp
    if (name.length() > this->name.length()) return;
```
> 예제 5-11의 동작을 유지하기 위한 길이 체크다.  
> `strlen()` 대신 `string::length()` 멤버 함수를 사용한다.  
> 새 이름이 현재 이름보다 길면 변경하지 않고 함수를 빠져나간다.

```cpp
    this->name = name;
```
> `string` 대입 연산자로 이름을 변경한다.  
> 예제 5-11의 `strcpy(this->name, name);`을 단 한 줄로 대체한다.

```cpp
}
```
> 함수 구현을 종료한다.

---

```cpp
int main() {
```
> 프로그램 진입점이다.

```cpp
    Person father(1, "Kitae");
```
> `id=1`, `name="Kitae"`로 father 객체를 생성한다.  
> 문자열 리터럴 `"Kitae"`는 자동으로 `string` 타입으로 변환되어 생성자에 전달된다.

```cpp
    Person daughter(father);
```
> father 객체를 복사하여 daughter 객체를 생성한다.  
> 직접 작성한 복사 생성자가 없으므로 컴파일러가 자동 삽입한 디폴트 복사 생성자가 호출된다.  
> `string` 멤버의 복사 생성자가 내부적으로 실행되므로 **깊은 복사**가 자동으로 이루어진다.

```cpp
    cout << "daughter 객체 생성 직후 ----" << endl;
```
> 구분용 문자열을 출력한다.

```cpp
    father.show();
```
> father의 id와 name을 출력한다. → `1,Kitae`

```cpp
    daughter.show();
```
> daughter의 id와 name을 출력한다. → `1,Kitae` (복사 직후라 father와 동일)

```cpp
    daughter.changeName("Grace");
```
> daughter의 이름을 "Grace"로 변경한다.  
> "Grace"(5글자) ≤ "Kitae"(5글자)이므로 길이 조건을 통과한다.  
> 깊은 복사 덕분에 father의 name에는 영향을 주지 않는다.

```cpp
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
```
> 구분용 문자열을 출력한다.

```cpp
    father.show();
```
> father는 변화 없이 `1,Kitae`를 출력한다.

```cpp
    daughter.show();
```
> daughter는 이름이 변경되어 `1,Grace`를 출력한다.

```cpp
    return 0;
}
```
> main 함수를 정상 종료한다.  
> 스코프를 벗어나며 두 객체의 소멸자가 자동 호출되고, `string` 멤버가 각자의 힙 메모리를 해제하므로 이중 해제 오류가 발생하지 않는다.

---

## 실행 결과
<img width="813" height="233" alt="image" src="https://github.com/user-attachments/assets/55a8c20e-cdfb-488a-831a-ed239fbb13ae" />


---

## char* vs string 핵심 비교

| 항목 | char* 방식 (예제 5-11) | string 방식 (실습과제 2) |
|------|----------------------|------------------------|
| 생성자 | `new char[]` + `strcpy` | `this->name = name` 한 줄 |
| 소멸자 | `delete[] name` 직접 필요 | 불필요 (자동 해제) |
| 복사 생성자 | 깊은 복사 직접 작성 필요 | 불필요 (자동 깊은 복사) |
| 이름 변경 | `strlen` + `strcpy` | `string` 대입 한 줄 |
