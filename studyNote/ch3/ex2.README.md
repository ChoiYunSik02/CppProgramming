---
 
# 3장 실습문제 2번 - 커피 클래스
 
---

```cpp
#include <iostream>
using namespace std;

class Coffee {
    int coffee, sugar, milk, water; // 커피 재료들의 양을 저장할 변수들입니다.
public:
    Coffee(int c, int s, int m, int w); // 4가지 재료를 모두 받는 생성자입니다.
    void show(); // 커피 상태를 별표(*)로 출력해줄 함수입니다.
};

// [멤버 초기화 리스트]
// 괄호 안에 들어온 c, s, m, w 값을 각각의 멤버 변수에 곧바로 초기화합니다.
Coffee::Coffee(int c, int s, int m, int w) : coffee(c), sugar(s), milk(m), water(w) { }

// show() 함수 구현부
void Coffee::show() {
    // 각 재료의 숫자만큼 반복문(for)을 돌면서 별표(*)를 찍습니다.
    cout << "coffee "; for(int i=0; i<coffee; i++) cout << "*"; cout << endl;
    cout << "sugar  "; for(int i=0; i<sugar; i++) cout << "*"; cout << endl;
    cout << "milk   "; for(int i=0; i<milk; i++) cout << "*"; cout << endl;
    cout << "water  "; for(int i=0; i<water; i++) cout << "*"; cout << endl;
}

int main() {
    // 다양한 비율의 커피 객체들을 생성합니다.
    Coffee espresso(10, 0, 0, 0); 
    Coffee americano(5, 0, 0, 10); 
    Coffee cappuccino(5, 1, 5, 2); 
    Coffee mySweet(3, 7, 5, 5); 

    espresso.show(); cout << endl; // 에스프레소 상태 출력
    mySweet.show();                // 마이스윗 커피 상태 출력
}
```


## 실행결과
<img width="899" height="164" alt="image" src="https://github.com/user-attachments/assets/e74b642d-3408-4713-8665-92983a5f11b6" />

