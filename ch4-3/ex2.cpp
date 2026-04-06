// **********************************************
// 제 목 : ch04-3 실습과제 2번 - 코드 문제 해결
// 날 짜 : 2026년 04월 7일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	int radius;
	while (true) {
		cout << "정수 반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break;

		Circle* p = new Circle(radius);
		cout << "원의 면적은 " << p->getArea() << endl;

		delete p; // 메모리 해제를 해야한다.
	}
}
