// **********************************************
// 제 목 : C++ ch07-4 실습과제1
// 날 짜 : 2026년 06월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class complex {
	int real;
	int img;
public:
	complex() {
		this->real = 0;
		this->img = 0;
	}
	void show();
	friend istream& operator>>(istream& op1, complex& op2);
	friend ostream& operator<<(ostream& op1, complex& op2);
};

istream& operator>>(istream& op1, complex& op2) {
	cout << "실수부:";
	op1 >> op2.real;
	cout << "허수부:";
	op1 >> op2.img;
	return op1;
}

ostream& operator<<(ostream& op1, complex& op2) {
	op1 << op2.real; // 실수부 출력
	if (op2.img < 0) // 허수부가 -이면
		op1 << op2.img << "j" << endl; // - 그대로 출력
	else
		op1 << "+" << op2.img << "j" << endl; // 부호를 +로 변경 후 출력 
	return op1;
}

void complex::show() {
	cout << real;
	if (img < 0)
		cout << img << "j" << endl;
	else
		cout << "+" << img << "j" << endl;
}

int main() {
	complex x, y;
	cin >> x >> y;
	cout << x << y;
	return 0;
}
