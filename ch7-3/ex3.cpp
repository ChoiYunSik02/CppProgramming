// **********************************************
// 제 목 : C++ ch07-3 실습과제3 - 프렌드로 구현한 곱셈(*)연산자 중복
// 날 짜 : 2026년 06월 08일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator*(int op1, Power op2);
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator*(int op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1 * op2.kick;
	tmp.punch = op1 * op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();

	b = 2 * a;
	a.show();
	b.show();

	return 0;
}
