#include <iostream>
using namespace std;

class Circle {
private:
	int radius; // 수정된 코드
public:
	// int radius; // 기존 코드 
	Circle();
	Circle(int r);
	int getRadius(); // 멤버 변수의 값을 읽는 함수
};

Circle::Circle() { radius = 1; } // 위임
Circle::Circle(int r) { radius = r; } // 타켓
int Circle::getRadius() { return radius; } // 멤버 변수 값 읽기

int main() {
	Circle waffle1;
	Circle waffle2(5); // 생성자를 이용한 멤버변수 설정
	// waffle.radius = 5; // 기존코드
	cout << "원의 반지름은 " << waffle1.getRadius() << endl;
	cout << "원의 반지름은 " << waffle2.getRadius() << endl;
	return 0;
}

