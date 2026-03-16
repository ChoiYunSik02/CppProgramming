// **********************************************
// 제 목 : 3-1장 실습과제 5번
// 날 짜 : 2026년 03월 16일
// 작성자 : 2101091 최윤식
// **********************************************
#include <iostream>
using namespace std;

class Rectangle {
public:
    int x;
    int y;
    int width;
    int height;
    void input();        // 키보드로부터 데이터를 받아 멤버변수에 대입하는 함수 추가
    int getArea();
    int Perimeter();
    int CoordinateX();
    int CoordinateY();
};

void Rectangle::input() {
    cout << "사각형의 좌측 상단 좌표(x, y): ";
    cin >> x >> y;           // 멤버변수에 직접 대입
    cout << "사각형의 폭과 높이(width, height): ";
    cin >> width >> height;  // 멤버변수에 직접 대입
}

// 사각형의 면적 계산 함수
int Rectangle::getArea() {
    return width * height;
}

// 사각형의 둘레 길이 계산 함수
int Rectangle::Perimeter() {
    return (width + height) * 2;
}

// 사각형의 우측 하단 x좌표 계산 함수
int Rectangle::CoordinateX() {
    return x + width;
}

// 사각형의 우측 하단 y좌표 계산 함수

int Rectangle::CoordinateY() {
    return y - height;
}

int main() {
    Rectangle rect;
    rect.input();  // 입력을 멤버함수가 담당
    cout << "사각형의 면적은 " << rect.getArea() << endl;
    cout << "사각형의 둘레길이는 " << rect.Perimeter() << endl;
    cout << "사각형의 우측하단의 좌표는 (" << rect.CoordinateX() << ", " << rect.CoordinateY() << ")" << endl;
}
