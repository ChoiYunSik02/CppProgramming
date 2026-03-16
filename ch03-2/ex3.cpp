#include <iostream>
using namespace std;

class Sphere {
public:
	int radius; // 반지름 
	double getVolume(); // 구의 부피 계산 함수
	Sphere(); // 생성자 1
	Sphere(int r); // 생성자 2
};

// 부피 계산 함수
double Sphere::getVolume() {
	return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

// 위임 생성자 반지름 r = 1 초기화
Sphere::Sphere() : Sphere(1) { }

// 타켓 생성자 radius = r 초기화
Sphere::Sphere(int r) : radius(r) { }

int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVolume() << endl;

	Sphere sph2(3); // 반지름 3으로 설정 
	cout << "구의 부피는 " << sph2.getVolume() << endl;
	return 0;
}
