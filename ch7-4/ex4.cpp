// **********************************************
// 제 목 : C++ ch07-4 연습문제 3번
// 날 짜 : 2026년 06월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

// 멤버 함수 버전
//class Coffee {
//	int water, espresso, sugar, cream;
//public:
//	Coffee(int water = 0, int coffee = 0, int sugar = 0, int cream = 0) {
//		this->water = water; this->espresso = coffee; this->sugar = sugar; this->cream = cream;
//	}
//	void show() {
//		cout << "물 " << water << ", 커피 " << espresso << ", 설탕 " << sugar << ", 크림 " << cream << endl;
//	}
//	bool operator!(); // 설탕 없으면 true
//	bool operator>(Coffee& op); // 물 양 비교
//};
//
//bool Coffee::operator!() {
//	if (sugar == 0) return true;
//	return false;
//}
//
//bool Coffee::operator>(Coffee& op) {
//	if (this->water > op.water) return true;
//	return false;
//}
//
//int main() {
//	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
//	if (!a)
//		cout << "No sugar!" << endl;
//	if (a > b) cout << "커피 a가 양이 더 많아요" << endl;
//	else cout << "커피 b가 양이 더 많아요" << endl;
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
	friend bool operator!(Coffee& op); // 프렌드로 선언한 operator!
	friend bool operator>(Coffee& op1, Coffee& op2); // 프렌드로 선언한 operator> 
};

bool operator!(Coffee& op) {
	if (op.sugar == 0) return true;
	return false;
}

bool operator>(Coffee& op1, Coffee& op2) {
	if (op1.water > op2.water) return true;
	return false;
}

int main() {
	Coffee a(2, 5, 0, 0), b(2, 2, 2, 2);
	if (!a)
		cout << "No sugar!" << endl;
	if (a > b) cout << "커피 a가 양이 더 많아요" << endl;
	else cout << "커피 b가 양이 더 많아요" << endl;
	return 0;
}

