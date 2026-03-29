// **********************************************
// 제 목 : 3-5장 실습과제 3번 교재 149 페이지 2번문제
// 날 짜 : 2026년 03월 29일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Coffee {
private:
	int coffee; // 커피
	int sugar; // 설탕
	int milk; // 우유
	int water; // 물 
public:
	Coffee(); 
	Coffee(int c, int s, int m, int w);
	void show();
};
// 기본 생성자
Coffee::Coffee() : coffee(10), sugar(0), milk(0), water(0) { }

Coffee::Coffee(int c, int s, int m, int w) : coffee(c), sugar(s), milk(m), water(w) { }

// show 함수 
void Coffee::show() {
	cout << "coffee ";
	for (int i = 0; i < coffee; i++) {
		cout << "*";
	}
	cout << endl;

	cout << "sugar ";
	for (int i = 0; i < sugar; i++) {
		cout << "*";
	}
	cout << endl;

	cout << "milk ";
	for (int i = 0; i < milk; i++) {
		cout << "*";
	}
	cout << endl;

	cout << "water ";
	for (int i = 0; i < water; i++) {
		cout << "*";
	}
	cout << endl;
}

int main() {
	Coffee espresso;
	Coffee americano(5, 0, 0, 10);
	Coffee cappucchino(5, 1, 5, 2);
	Coffee mySweet(3, 7, 5, 5);

	espresso.show(); // 에소프레소 재료 값 출력
	cout << endl;
	mySweet.show(); // 나만의 커피 값 출력 
}
