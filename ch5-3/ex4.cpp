// **********************************************
// 제 목 : C++ ch05-3 실습과제4 - Circle 클래스 plus/minus 참조 리턴
// 날 짜 : 2026년 05월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius) { this->radius = radius; }
	Circle& plus(int n) {
		radius += n;
		return *this;
	}
	// 마이너스 추가
	Circle& minus(int m) {
		radius -= m;
		return *this;
	}
	int getRadius() { return radius; }
};

int main() {
	Circle a(5);
	// 5에서 +1, +2, +3, -3, -2, -1, -5를 함으로써 출력은 0
	a.plus(1).plus(2).plus(3).minus(3).minus(2).minus(1).minus(5); 
	cout << "객체 a의 반지름은 " << a.getRadius();
	return 0;
}
