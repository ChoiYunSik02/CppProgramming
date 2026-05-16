// **********************************************
// 제 목 : C++ ch06-1 실습과제3 - Rectangle 클래스
// 날 짜 : 2026년 05월 16일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle() { width = 1; height = 1; }
	Rectangle(int a) { width = a; height = 1; }
	Rectangle(int a, int b) { width = a; height = b; }
	void show();
};

void Rectangle::show() {
	cout << "사각형 폭은 " << width << " 높이는 " << height << endl;
}
int main() {
	Rectangle rect0;
	rect0.show();
	Rectangle rect1(10);
	rect1.show();
	Rectangle rect2(10, 20);
	rect2.show();
	return 0;
}
