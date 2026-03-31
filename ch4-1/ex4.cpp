// **********************************************
// 제 목 : 4-1장 실습과제 4번
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
	Triangle(int a, int b) { 
		width = a, height = b;
		cout << "밑변" << width << "," << "높이" << height << "인 삼각형 생성" << endl;
	}
	~Triangle() {
		cout << "밑변" << width << "," << "높이" << height << "인 삼각형 소멸" << endl;
	}

	double getArea() {
		return (1.0 / 2.0) * width * height;
	}
};

int main() {

	Triangle tri[3] = { Triangle(2, 2), Triangle(4, 4), Triangle(6, 6) };
	

	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << tri[i].getArea() << endl;
	}
	return 0;
}
