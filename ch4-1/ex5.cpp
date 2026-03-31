// **********************************************
// 제 목 : 4-1장 실습과제 5번
// 날 짜 : 2026년 03월 31일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
	int width;
	int height;
public:
	Triangle() { width = 1, height = 1; }
	Triangle(int a, int b) { width = a, height = b; }
	~Triangle() {}

	double getArea() {
		return (1.0 / 2.0) * width * height;
	}
};

int main() {

	Triangle tri[3] = { Triangle(2, 2), Triangle(4, 4), Triangle(6, 6) };
	Triangle* p = tri;
	
	// 방법 1
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << (tri + i)->getArea() << endl;
	}
	cout << endl;

	// 방법 2
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << (p+i)->getArea() << endl;
	}
	cout << endl;

	// 방법 3
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << p[i].getArea() << endl;
	}
	cout << endl;

	// 방법 4
	p = tri; // 포인터 초기화 
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}

	return 0;
}
