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

Sphere::Sphere() : Sphere(1) {} // 위임 생성자
Sphere::Sphere(int r) : radius(r) { // 타겟 생성자
	cout << "반지름 " << radius << "인 구 생성" << endl;
}
Sphere::~Sphere() { // 소멸자 
	cout << "반지름 " << radius << "인 구 소멸" << endl;
}

double Sphere::getVolume() { // 구의 부피 계산 함수
	return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

Sphere globalSph1(10); // 전역객체 선언
Sphere globalSph2(20); // 전역객체 선언 

int main() {
	cout << "구의 부피는 " << globalSph1.getVolume() << endl;
	cout << "구의 부피는 " << globalSph2.getVolume() << endl;
	return 0;
}
