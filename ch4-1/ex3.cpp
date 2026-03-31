// **********************************************
// 제 목 : 4-1장 실습과제 3번
// 날 짜 : 2026년 03월 31일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
	int width;
	int height;
public:
	// this 포인터로 멤버 변수에 접근
	Triangle() { this->width = 1; this->height = 1; } // 밑변 = 1, 높이 = 1로 초기화
	Triangle(int a) { this->width = a; this->height = 1; } // 밑변 = a, 높이 = 1로 초기화
	Triangle(int a, int b) { this->width = a; this->height = b; } // 밑변 = a, 높이 = b로 초기화

	double getArea() {
		return (1.0 / 2.0) * this->width * this->height; // this 포인터를 각각 사용
	}
};

int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;

	Triangle tri2(10);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;

	Triangle tri3(10, 2);
	cout << "삼각형의 면적은 " << tri3.getArea() << endl;

	return 0;
}
