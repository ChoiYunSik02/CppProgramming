// **********************************************
// 제 목 : 3-1장 실습과제 4번
// 날 짜 : 2026년 03월 16일
// 작성자 : 2101091 최윤식
// **********************************************

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
};

int Rectangle::getArea() {
	return width * height; // 사각형의 면적 계산
}

int Rectangle::Perimeter() {
	return (width + height) * 2; // 사각형 둘레 계산
}

int Rectangle::CoordinateX() { 
	return x + width; // x좌표 계산
}
int Rectangle::CoordinateY() {
	return y - height; // y좌표 계산
}

int main() {
	Rectangle rect;
	rect.x = 1; // 좌측상단 x좌표 설정
	rect.y = 2; // 좌측상단 y좌표 설정
	rect.width = 3; // 밑변의 길이 설정
	rect.height = 4; // 높이 설정 
	cout << "사각형의 면적은 " << rect.getArea() << endl;
	cout << "사각형의 둘레길이는 " << rect.Perimeter() << endl;
	cout << "사각형의 우측하단의 좌표는 " << "(" << rect.CoordinateX() << ", " << rect.CoordinateY() << ")" << endl;
}
