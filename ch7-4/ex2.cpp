// **********************************************
// 제 목 : C++ ch07-4 연습문제 1번 (프렌드)
// 날 짜 : 2026년 06월 10일
// 작성자 : 2101091 최윤식
// **********************************************

//#include <iostream>
//using namespace std;
//
//// 멤버 함수 버전 
//class Coffee {
//	int water, espresso, sugar, cream;
//public:
//	Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0) {
//		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
//	}
//	void show() {
//		cout << "물 " << water << ", 커피 " << espresso;
//		cout << ", 설탕 " << sugar << ", 크림 " << cream << endl;
//	}
//	Coffee operator+(Coffee& op); // 멤버 함수로 선언(객체 + 객체)
//	Coffee operator+(int n); // 멤버 함수로 선언 (객체 + 정수) 
//};
//
//Coffee Coffee::operator+(Coffee& op) {
//	Coffee tmp;
//	tmp.water = this->water + op.water;
//	tmp.espresso = this->espresso + op.espresso;
//	tmp.sugar = this->sugar + op.sugar;
//	tmp.cream = this->cream + op.cream;
//	return tmp;
//}
//
//Coffee Coffee::operator+(int n) {
//	Coffee tmp;
//	tmp.water = this->water;
//	tmp.espresso = this->espresso + n;
//	tmp.sugar = this->sugar;
//	tmp.cream = this->cream;
//	return tmp;
//}
//
//int main() {
//	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
//	c = black + dabang; // 커피 + 커피 
//	d = c + 1; // 커피 + 정수 
//	c.show(); d.show();
//}

// 프렌드 버전
#include <iostream>
using namespace std;

class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0) {
		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	friend Coffee operator+(Coffee& op1, Coffee& op2); // 프렌드 함수로 선언 (객체 + 객체)
	friend Coffee operator+(Coffee& op1, int n); // 프렌드 함수로 선언 (객체 + 정수)
};

Coffee operator+(Coffee& op1, Coffee& op2) {
	Coffee tmp;
	tmp.water = op1.water + op2.water;
	tmp.espresso = op1.espresso + op2.espresso;
	tmp.sugar = op1.sugar + op2.sugar;
	tmp.cream = op1.cream + op2.cream;
	return tmp;
}

Coffee operator+(Coffee& op1, int n) {
	Coffee tmp;
	tmp.water = op1.water;
	tmp.espresso = op1.espresso + n;
	tmp.sugar = op1.sugar;
	tmp.cream = op1.cream;
	return tmp;
}
int main() {
	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
	c = black + dabang;
	d = c + 1;
	c.show(); d.show();
	return 0;
}
