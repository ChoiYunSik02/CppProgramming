// **********************************************
// 제 목 : 3-3장 실습과제 4번
// 날 짜 : 2026년 03월 22일
// 작성자 : 2101091 최윤식
// **********************************************
#include <iostream>
using namespace std;

class Sphere {
public:
	int radius;
	double getVolume();
	Sphere(); // 생성자 1
	Sphere(int r); // 생성자 2
	~Sphere(); // 소멸자
};

Sphere::Sphere() : Sphere(1) { } // 위임 생성자
Sphere::Sphere(int r) : radius(r) { // 타겟 생성자
	cout << "반지름 " << radius << "인 구 생성" << endl;
}
Sphere::~Sphere() { // 소멸자 
	cout << "반지름 " << radius << "인 구 소멸" << endl;
}

double Sphere::getVolume() { // 구의 부피 계산 함수
	return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVolume() << endl;

	Sphere sph2(3);
	cout << "구의 부피는 " << sph2.getVolume() << endl;
	return 0;
}
