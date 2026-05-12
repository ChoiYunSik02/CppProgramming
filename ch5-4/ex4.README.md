# ch5-4 실습과제 4 - Collector 클래스 (교재 282p 13번)


---

## 전체 소스코드 설명

```cpp
#include <iostream>
```
> 표준 입출력 라이브러리를 포함한다. `cout`, `endl` 사용을 위해 필요하다.

```cpp
using namespace std;
```
> `std::` 접두사 없이 표준 라이브러리를 사용하기 위한 선언이다.

---

```cpp
class Collector {
```
> 센서 값을 동적 배열에 저장하는 `Collector` 클래스 선언을 시작한다.

```cpp
    int *p;
```
> 데이터를 저장하는 동적 배열을 가리키는 포인터다.  
> 힙 메모리를 직접 관리하므로 소멸자와 깊은 복사 생성자가 반드시 필요하다.

```cpp
    int size = 0;
```
> 저장된 데이터의 개수를 나타내는 멤버 변수다. 선언과 동시에 0으로 초기화된다.

```cpp
public:
    Collector(int size, int values[]);
```
> 생성자를 선언한다.  
> `size`개만큼 동적 배열을 할당하고, `values[]` 배열에서 데이터를 복사해 저장한다.

```cpp
    Collector(const Collector& src);
```
> 복사 생성자를 선언한다. (문항 3)  
> `calcAvg(Collector c)`처럼 값으로 전달할 때 이 생성자가 호출된다.  
> `const&`로 받아 원본을 수정하지 않도록 보장한다.

```cpp
    ~Collector() { delete[] p; }
```
> 소멸자다. (문항 2)  
> 객체가 소멸될 때 동적 할당된 배열 `p`를 힙에서 해제한다.  
> 배열로 할당했으므로 반드시 `delete[]`를 사용해야 한다.

```cpp
    void show();
```
> 저장된 데이터 개수와 모든 값을 화면에 출력하는 함수를 선언한다.

```cpp
    int getSize() { return size; }
```
> 저장된 데이터 개수를 반환하는 인라인 함수다.

```cpp
    int get(int index) { return p[index]; }
```
> 인덱스에 해당하는 데이터를 반환하는 인라인 함수다.

```cpp
};
```
> 클래스 선언을 종료한다.

---

```cpp
Collector::Collector(int size, int values[]) {
```
> 생성자 구현부를 시작한다.

```cpp
    this->size = size;
```
> 매개변수 `size`를 멤버 변수 `this->size`에 저장한다.

```cpp
    this->p    = new int[size];
```
> `size` 개수만큼 `int` 배열을 힙에 동적 할당하고, 시작 주소를 `p`에 저장한다.

```cpp
    for (int i = 0; i < size; i++) {
```
> 0부터 `size-1`까지 반복한다. `values[]` 배열에서 `size`개만큼만 복사하기 위함이다.  
> `main()`에서 `temp`에 5개가 있더라도 `size=4`이면 4개만 저장된다.

```cpp
        p[i] = values[i];
```
> `values[]`의 i번째 값을 동적 배열 `p`의 i번째 위치에 저장한다.

```cpp
    }
}
```
> 반복문과 생성자 구현을 종료한다.

---

```cpp
Collector::Collector(const Collector& src) {
```
> 복사 생성자 구현부를 시작한다. `src`는 복사할 원본 객체를 참조한다. (문항 3)

```cpp
    this->size = src.size;
```
> 원본의 데이터 개수를 그대로 복사한다.

```cpp
    this->p    = new int[src.size];
```
> **깊은 복사의 핵심.**  
> 원본의 `p`를 그대로 복사하지 않고, 새로운 독립된 메모리를 별도로 할당한다.  
> 이로써 `this->p`와 `src.p`는 서로 다른 힙 메모리를 가리키게 된다.

```cpp
    for (int i = 0; i < src.size; i++) {
```
> 원본에 저장된 데이터 개수만큼 반복한다.

```cpp
        this->p[i] = src.p[i];
```
> 원본 배열의 각 원소를 새로 할당한 배열에 하나씩 복사한다.

```cpp
    }
}
```
> 반복문과 복사 생성자 구현을 종료한다.

---

```cpp
void Collector::show() {
```
> `show()` 함수 구현부를 시작한다.

```cpp
    cout << "데이터 수 " << size << ": ";
```
> 저장된 데이터 개수를 출력한다. 줄바꿈 없이 이어서 값들을 출력하기 위해 `endl`을 사용하지 않는다.

```cpp
    for (int i = 0; i < size; i++) {
```
> 저장된 데이터 수만큼 반복한다.

```cpp
        cout << p[i] << " ";
```
> 배열의 각 값을 공백으로 구분하여 출력한다.

```cpp
    }
    cout << endl;
}
```
> 모든 값 출력 후 줄바꿈을 하고 함수를 종료한다.

---

```cpp
double calcAvg(Collector c) {
```
> 외부 함수 `calcAvg` 구현부를 시작한다.  
> **값으로 전달(pass by value)** 이므로 함수 호출 시 복사 생성자가 자동으로 호출된다.  
> 문항 2에서 복사 생성자 없이 소멸자만 있으면 바로 이 시점에 얕은 복사가 발생해 문제가 생긴다.

```cpp
    int sum = 0;
```
> 합계를 저장할 변수를 0으로 초기화한다.

```cpp
    for (int i = 0; i < c.getSize(); i++) {
```
> 저장된 데이터 개수만큼 반복한다.

```cpp
        sum += c.get(i);
```
> 각 인덱스의 데이터를 `get()`으로 꺼내 `sum`에 누적한다.

```cpp
    }
    return (double)sum / c.getSize();
```
> 합계를 데이터 개수로 나눈 평균을 `double`로 반환한다.  
> `(double)` 형변환을 하지 않으면 정수 나눗셈이 되어 소수점이 버려진다.

```cpp
}
```
> 함수 종료. 매개변수 `c`가 스코프를 벗어나므로 `c`의 소멸자가 호출된다.  
> 깊은 복사로 생성된 `c`이므로 `c.p`만 해제되고, 원본 `weight.p`는 영향을 받지 않는다.

---

```cpp
int main() {
```
> 프로그램 진입점이다.

```cpp
    int temp[] = { 69, 70, 71, 72, 74 };
```
> 5개의 센서 값을 가진 배열을 선언한다.

```cpp
    Collector weight(4, temp);
```
> `size=4`로 Collector 객체를 생성한다.  
> `temp` 배열의 앞 4개 값(69, 70, 71, 72)만 저장되고, 74는 저장되지 않는다.

```cpp
    double avg = calcAvg(weight);
```
> `calcAvg` 함수를 호출한다.  
> 값 전달 방식이므로 `weight`를 복사해 매개변수 `c`를 만든다 → 복사 생성자 호출.  
> 반환된 평균값(70.5)을 `avg`에 저장한다.

```cpp
    weight.show();
```
> `데이터 수 4: 69 70 71 72`를 출력한다.  
> `calcAvg` 호출 후에도 `weight`의 데이터가 그대로임을 확인할 수 있다.

```cpp
    cout << "평균은 " << avg << endl;
```
> `평균은 70.5`를 출력한다.

```cpp
    return 0;
}
```
> main 함수를 정상 종료한다.  
> `weight` 객체가 소멸되며 소멸자가 `weight.p`의 동적 배열을 해제한다.

---

## 실행 결과
<img width="836" height="158" alt="image" src="https://github.com/user-attachments/assets/5017107a-debe-44ef-9d82-682d3ba13b7a" />



---

## 문항 2 — 소멸자만 추가했을 때 오류 발생 과정

```
① Collector weight(4, temp) 생성
   weight.p ──▶ [69, 70, 71, 72]  (힙 메모리)

② calcAvg(weight) 호출
   → 디폴트 복사 생성자(얕은 복사) 실행
   → c.p와 weight.p가 같은 메모리를 공유

   weight.p ──┐
              └──▶ [69, 70, 71, 72]  ← 메모리 공유!
   c.p ───────┘

③ calcAvg() 종료 → c 객체 소멸
   → c의 소멸자: delete[] p → 메모리 해제됨

④ main() 종료 → weight 객체 소멸
   → weight의 소멸자: delete[] p
   → 이미 해제된 메모리를 또 해제 → 이중 해제(double free)
   → Debug Assertion Failed! (_CrtIsValidHeapPointer) 오류 발생
```

## 문항 3 — 복사 생성자 추가 후 정상 동작

```
② calcAvg(weight) 호출
   → 깊은 복사 생성자 실행 → c.p는 새로운 별도 메모리

   weight.p ──▶ [69, 70, 71, 72]  (weight 전용)
   c.p      ──▶ [69, 70, 71, 72]  (c 전용, 별도 할당)

③ calcAvg() 종료 → c.p만 해제 → weight 영향 없음
④ main() 종료  → weight.p 해제 → 정상 종료
```
