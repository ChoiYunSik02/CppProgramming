// **********************************************
// 제 목 : 3-4장 실습과제 3번
// 날 짜 : 2026년 03월 24일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
	int width; // 밑변
	int height; // 높이
public:
	Triangle(); // 생성자 1
	Triangle(int a, int b); // 생성자 2
	~Triangle(); // 소멸자
	void setWidth(int a); // 멤버 접근 함수 setter
	void setHeight(int b); 
	int getWidth(); // 멤버 접근 함수 getter
	int getHeight();
	double getArea(); // 삼각형 면적 계산 함수
};

Triangle::Triangle() : Triangle(1, 1) { } // 위임 생성자
Triangle::Triangle(int a, int b) : width(a), height(b) { // 타켓 생성자
	cout << "폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
}
Triangle::~Triangle() { // 소멸자 
	cout << "폭" << width << ", " << "높이" << height << " 삼각형 소멸" << endl;
}

void Triangle::setWidth(int a) { width = a; } // 밑변변수의 값 쓰기
void Triangle::setHeight(int b) { height = b; } // 높이변수의 값 쓰기
int Triangle::getWidth() { return width; } // 밑변변수의 값 읽기
int Triangle::getHeight() { return height; } // 높이변수의 값 읽기

double Triangle::getArea() { // 삼각형 면적 계산 함수
	return (1.0 / 2.0) * width * height;
}

int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
	return 0;
}
