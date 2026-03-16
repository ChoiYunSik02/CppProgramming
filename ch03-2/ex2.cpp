// **********************************************
// 제 목 : 3-2장 실습과제 2번
// 날 짜 : 2026년 03월 16일
// 작성자 : 2101091 최윤식
// **********************************************
#include <iostream>
using namespace std;

class Triangle {
public:
	int width, height; // 밑변, 높이 멤버 변수 
	double getArea(); // 면적 계산 멤버 함수
	Triangle(); // 생성자 1
	Triangle(int a, int b); // 생성자 2
};

double Triangle::getArea() {
	return (1.0/2.0)* width * height; // 삼각형 면적 계산 
}

// 위임 생성자 x = 1, y = 1 초기화
Triangle::Triangle(): Triangle(1, 1) { } 

// 타켓 생성자 width = a, height = b 초기화
Triangle::Triangle(int a, int b): width(a), height(b) { } 

int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;

	Triangle tri2(2, 4);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	return 0;
}
