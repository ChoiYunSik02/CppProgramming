// **********************************************
// 제 목 : C++ ch07-4 연습문제 4번
// 날 짜 : 2026년 06월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

//// 멤버 함수 버전
//class Coffee {
//	int water, espresso, sugar, cream;
//public:
//	Coffee(int water = 0, int coffee = 0, int sugar = 0, int cream = 0) {
//		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
//	}
//	void show() {
//		cout << "물 " << water << ", 커피 " << espresso << ", 설탕 " << sugar << ", 크림 " << cream << endl;
//	}
//	Coffee& operator<<(Coffee& op); // a << b
//	Coffee& operator<<(int n); // a << 3
//};
//
//Coffee& Coffee::operator<<(Coffee& op) {
//	this->water += op.water;
//	this->espresso += op.espresso;
//	this->sugar += op.sugar;
//	this->cream += op.cream;
//	return *this;
//}
//
//Coffee& Coffee::operator<<(int n) {
//	this->water += n;
//	return *this;
//}
//
//int main() {
//	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
//	a << b << 3; // 연속 더하기 =  a에 b를 더하고 3을 더한다.
//	a.show();
//	return 0;
//}

// 프렌드 버전
class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 0, int coffee = 0, int sugar = 0, int cream = 0) {
		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	friend Coffee& operator<<(Coffee& op1, Coffee& op2); // a << b // 프렌드 선언
	friend Coffee& operator<<(Coffee& op, int n); // a << 3 // 프렌드 선언
};

Coffee& operator<<(Coffee& op1, Coffee& op2) {
	op1.water += op2.water;
	op1.espresso += op2.espresso;
	op1.sugar += op2.sugar;
	op1.cream += op2.cream;
	return op1;
}

Coffee& operator<<(Coffee& op, int n) {
	op.water += n;
	return op;
}

int main() {
	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
	a << b << 3;
	a.show();
	return 0;
}
