// **********************************************
// 제 목 : ch04-3 실습과제 3번 - 코드 문제 해결
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

// 수정된 main 문 
int main() {
	Circle* pArray = new Circle[3];

	for (int i = 0; i < 3; i++) {
		cout << pArray[i].getArea() << '\n'; // 배열 인덱스 사용 
	}

	delete[] pArray; // 정상 해제
}
