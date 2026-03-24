// **********************************************
// 제 목 : 3-4장 실습과제 4번
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

Triangle::Triangle() : Triangle(1, 1) {} // 위임 생성자
Triangle::Triangle(int a, int b) { // 타켓 생성자 
	if (a < 0 || b < 0) {
		width = 1; height = 1; // 음수이면 폭1, 높이1로 초기화
		cout << "길이는 양수여야함, 대신에 폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
	}
	else { // 양수이면 
		width = a; height = b; // 폭 = a, 높이 = b로 초기화
		cout << "폭" << width << ", " << "높이" << height << " 삼각형 생성" << endl;
	}
}

Triangle::~Triangle() { // 소멸자 
	cout << "폭" << width << ", " << "높이" << height << " 삼각형 소멸" << endl;
}

void Triangle::setWidth(int a) {
	if (a < 0) cout << "폭은 양수이어야 함 " << endl;
	else width = a; // 밑변변수의 값 쓰기
} 

void Triangle::setHeight(int b) {
	if (b < 0) cout << "높이는 양수이어야 함 " << endl;
	else height = b; // 높이변수의 값 쓰기
} 

int Triangle::getWidth() { return width; } // 밑변변수의 값 읽기
int Triangle::getHeight() { return height; } // 높이변수의 값 읽기

double Triangle::getArea() { // 삼각형 면적 계산 함수
	return (1.0 / 2.0) * width * height;
}

int main() {
	Triangle tri(-10, -5); // 음수 테스트
	tri.setWidth(-3); // 음수 테스트
	tri.setHeight(-5); // 음수 테스트
	tri.setWidth(3); // 양수 테스트
	tri.setHeight(5); // 양수 테스트 
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	return 0;
}
