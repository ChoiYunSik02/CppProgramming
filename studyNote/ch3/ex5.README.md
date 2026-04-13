# 3장 실습문제 5번 - 커피머신

---

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class CoffeeMachine {
private:
	int coffee, water, sugar; // 커피, 물, 설탕
public:
	CoffeeMachine(); // 생성자
	CoffeeMachine(int c, int w, int s); // 매개변수 생성자
	void drinkEspresso() { coffee -= 1; water -= 1; } // 에소프레소 커피1 물1 소비
	void drinkAmericano() { coffee -= 1; water -= 2; } // 아메리카노 커피1 물 2 소비
	void drinkSugarCoffee() { coffee -= 1; water -= 2; sugar -= 1; } // 설탕커피 커피1, 물2, 설탕1 소비
	void show(); // 커피머신 재료 소비량 표시
	void fill() { coffee = 10; water = 10; sugar = 10; } // 커피머신 재료 충전
};

CoffeeMachine::CoffeeMachine() : CoffeeMachine(10, 10, 10) { } // 기본 생성자
CoffeeMachine::CoffeeMachine(int c, int w, int s) : coffee(c), water(w), sugar(s) { } // 위임 생성자

void CoffeeMachine::show() {
	cout << "[머신상태] 커피:" << coffee << "\t물:" << water << "\t설탕:" << sugar << endl;
}

int main() {
	CoffeeMachine java(5, 10, 6);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}
```

## 실행결과
<img width="906" height="215" alt="image" src="https://github.com/user-attachments/assets/28868662-2491-40b9-9099-3e5e3efc182c" />
