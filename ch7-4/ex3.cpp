// **********************************************
// 제 목 : C++ ch07-4 연습문제 2번
// 날 짜 : 2026년 06월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

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
//	Coffee& operator+=(Coffee& op);
//	Coffee& operator+=(int n);
//	Coffee& operator++(); // 전위
//	Coffee operator++(int x); // 후위
//};
//
//// 객체1 = 객체1 + 객체2, 객체1 += 객체2
//Coffee& Coffee::operator+=(Coffee& op) {
//	this->water += op.water;
//	this->espresso += op.espresso;
//	this->sugar += op.sugar;
//	this->cream += op.cream;
//	return *this;
//}
//
//// 객체 = 객체 + 정수, 객체 += 정수
//Coffee& Coffee::operator+=(int n) {
//	this->espresso += n;
//	return *this;
//}
//
//// 전위 ++a
//Coffee& Coffee::operator++() {
//	this->espresso++;
//	return *this;
//}
//
//// 후위 a++
//Coffee Coffee::operator++(int x) {
//	Coffee tmp = *this;
//	this->espresso++;
//	return tmp;
//}
//int main() {
//	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2);
//	black += dabang; // 객체 += 객체
//	black += 1; // 객체 += 정수 에스프레소 샷 1추가
//	black++; // 후위 에스프레소 샷 1 추가
//	black.show();
//}

// 프렌드 버전
class Coffee {
	int water, espresso, sugar, cream;
public:
	Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0) {
		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
	}
	void show() {
		cout << "물 " << water << ", 커피 " << espresso << ", 설탕 " << sugar << ", 크림 " << cream << endl;
	}
	friend Coffee& operator+=(Coffee& op1, Coffee& op2); // 프렌드로 선언한 += 연산자 중복 (객체1+= 객체2)
	friend Coffee& operator+=(Coffee& op1, int n); // 프렌드로 선언한 += 연산자 중복 (객체1 += 정수)
	friend Coffee operator++(Coffee& op, int x); // 프렌드로 선언한 후위 연산자 중복 
};

Coffee& operator+=(Coffee& op1, Coffee& op2) {
	op1.water += op2.water;
	op1.espresso += op2.espresso;
	op1.sugar += op2.sugar;
	op1.cream += op2.cream;
	return op1;
}

Coffee& operator+=(Coffee& op1, int n) {
	op1.espresso += n;
	return op1;
}

Coffee operator++(Coffee& op1, int x) {
	Coffee tmp = op1;
	op1.espresso++;
	return tmp;
}

int main() {
	Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2);
	black += dabang; // 객체1 += 객체2
	black += 1; // 객체 += 정수
	black++; // 후위 ++ 연산자 
	black.show();
	return 0;
}
