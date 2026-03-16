#include <iostream>
using namespace std;

class Sphere {
public:
	int radius; // 반지름 
	double Volume(); // 구의 부피 계산 함수
	double SurfaceArea(); // 구의 표면적 계산 함수
};

// 부피 계산 함수
double Sphere::Volume() {
	return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

// 표면적 계산 함수
double Sphere::SurfaceArea() {
	return 4 * 3.14 * radius * radius;
}

int main() {
	Sphere gu;
	gu.radius = 5; // 반지름 설정 
	cout << "구의 부피는 " << gu.Volume() << endl; // 부피 값 출력
	cout << "구의 표면적은 " << gu.SurfaceArea() << endl; // 표면적 값 출력
	return 0;
}
