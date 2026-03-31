// **********************************************
// 제 목 : 4-1장 실습과제 2번
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
	Triangle() { width = 1, height = 1; }
	Triangle(int a, int b) { width = a, height = b; }

	void setWidth(int a) { width = a; }
	void setHeight(int b) { height = b; }

	double getArea() {
		return (1.0 / 2.0) * width * height;
	}
};

int main() {
	Triangle tri;
	Triangle* p; // 객체 포인터 선언
	p = &tri; // tri의 주소를 p에 저장 

	p->setWidth(3); // tri.setWidth(3)을 포인터 표현으로 변경
	p->setHeight(5); // tri.setHeight(5)을 포인터 표현으로 변경

	cout << "삼각형의 면적은 " << p->getArea() << endl; // 면적을 포인터 표현으로 변경 
	return 0;
}
