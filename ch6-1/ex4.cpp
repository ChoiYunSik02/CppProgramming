// **********************************************
// 제 목 : C++ ch06-1 실습과제4 - Point3D 클래스
// 날 짜 : 2026년 05월 16일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Point3D {
private:
	int x, y, z;
public:
	Point3D() { x = 0; y = 0; z = 0; }
	Point3D(int a) { x = a; y = 0; z = 0; }
	Point3D(int a, int b) { x = a; y = b; z = 0; }
	Point3D(int a, int b, int c) { x = a; y = b; z = c; }
	void show() {
		cout << "3차원 점의 좌표는 " << "(" << x << "," << y << "," << z << ")" << endl;
	}
};

int main() {
	Point3D p0;
	p0.show();
	Point3D p1(1);
	p1.show();
	Point3D p2(1, 2);
	p2.show();
	Point3D p3(1, 2, 3);
	p3.show();
	return 0;
}
