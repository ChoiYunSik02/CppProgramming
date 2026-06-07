// **********************************************
// 제 목 : C++ ch07-3 실습과제4 - 프렌드로 구현한 곱셈(*)과 덧셈(+)연산자 중복
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
	friend Power operator*(int n, Power op);
	friend Power operator*(Power op, int n);
	friend Power operator+(Power op1, Power op2);
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator*(int n, Power op) {
	Power tmp; // 임시 객체 생성
	tmp.kick = n * op.kick;
	tmp.punch = n* op.punch;
	return tmp;
}

Power operator*(Power op, int n) {
	Power tmp;
	tmp.kick = op.kick * n;
	tmp.punch = op.punch * n;
	return tmp;
}

Power operator+(Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

int main() {
	Power a(1, 1), b(2, 2), c;
	c.show();
	c = a * 2 + 2 * b;
	c.show();
	return 0;
}
