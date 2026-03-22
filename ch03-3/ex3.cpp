// 3-3장 실습과제 3
// 모든 객체를 전역객체로 생성 
#include <iostream>
using namespace std;

class Triangle {
public:
	int width;
	int height;
	Triangle(); // 생성자1
	Triangle(int a, int b); // 생성자 2
	~Triangle(); // 소멸자
	double getArea(); // 삼각형 면적 계산
};

Triangle::Triangle() : Triangle(1, 1) {} // 위임 생성자 
Triangle::Triangle(int a, int b) : width(a), height(b) { // 타켓 생성자 
	cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 생성" << endl;
}
Triangle::~Triangle() { // 소멸자
	cout << "밑변 " << width << " 높이 " << height << " 인 삼각형 소멸" << endl;
}

double Triangle::getArea() {
	return (1.0 / 2.0) * width * height; // 삼각형 면적 계산 
}

Triangle globalTri1(4, 8); // 전역객체 생성
Triangle globalTri2(2, 2); // 전역객체 생성

int main() {
	cout << "삼각형의 면적은 " << globalTri1.getArea() << endl; // 면적계싼
	cout << "삼각형의 면적은 " << globalTri2.getArea() << endl; // 면적계산 
	return 0;
}

