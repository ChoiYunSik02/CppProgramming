// 실습과제 4번 

#include <iostream>
using namespace std;

class Rectangle {
public:
	int x; // 좌측 상단 좌표 x 변수 설정
	int y; // 좌측 상단 좌표 y 변수 설정
	int width;
	int height;
	int getArea(); // 면적 계산 후 리턴하는 함수
	int Perimeter(); // 사각형의 둘레길이를 구하는 함수
	int CoordinateX(); // 사각형의 우측하단 x좌표를 구하는 함수
	int CoordinateY(); // 사각형의 우측하단 y좌표를 구하는 함수
	Rectangle();
	Rectangle(int a, int b);
	Rectangle(int a, int b, int c, int d);
};

int Rectangle::getArea() {
	return width * height; // 사각형의 면적 계산
}

int Rectangle::Perimeter() {
	return (width + height) * 2; // 사각형 둘레 계산
}

int Rectangle::CoordinateX() { 
	return x + width; // 우측하단 x좌표 계산
}
int Rectangle::CoordinateY() {
	return y - height; // 우측하단 y좌표 계산
}

// 모든 멤버변수를 1로 초기화
Rectangle::Rectangle() : Rectangle(1, 1, 1, 1) { }
// width = height = 1로 초기화
Rectangle::Rectangle(int a, int b) : Rectangle(a, b, 1, 1) { }
// x=a, y=b, width=c, height=d 로 초기화
Rectangle::Rectangle(int a, int b, int c, int d) : x(a), y(b), width(c), height(d) { }


int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3, 5, 2, 4);
	
	cout << "사각형의 면적은 " << rect1.getArea() << endl;
	cout << "사각형의 둘레길이는 " << rect2.Perimeter() << endl;
	cout << "사각형의 우측하단의 좌표는 " << "(" << rect3.CoordinateX() << ", " << rect3.CoordinateY() << ")" << endl;
}
