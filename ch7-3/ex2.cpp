// **********************************************
// 제 목 : C++ ch07-3 실습과제2 - 프렌드 함수로 구현한 ++ 연산자 중복
// 날 짜 : 2026년 06월 08일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Complex {
	int real; // 실수부 
	int img; // 허수부
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;
		this->img = img;
		cout << "복소수 " << real << " - " << -img << "j" << " 생성" << endl;
	}
	void show();
	friend Complex& operator++(Complex& op);
	friend Complex operator--(Complex& op, int x);
};

void Complex::show() {
	cout << real << " - " << -img << "j" << endl;
}

Complex& operator++(Complex& op) {
	op.real++;
	op.img++;
	return op;
}

Complex operator--(Complex& op, int x) {
	Complex tmp = op;
	op.real--;
	op.img--;
	return tmp;
}
int main() {
	Complex x(2, -3);

	++x;
	cout << "증가결과";
	x.show();

	x--;
	cout << "감소결과";
	x.show();

	return 0;
}
