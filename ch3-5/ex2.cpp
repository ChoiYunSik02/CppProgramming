// **********************************************
// 제 목 : 3-5 장 실습과제 2번
// 날 짜 : 2026년 03월 29일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
	int width;
	int height;
public:
	// 생성자
	Triangle() { 
		width = 1, height = 1;
		cout << "폭" << width << ", " << "높이" << height << " 인 삼각형 생성" << endl;
	} 

	// 소멸자 
	~Triangle() { cout << "폭" << width << ", " << "높이" << height << " 인 삼각형 소멸" << endl; } 
	
	// 삼각형 면적 함수
	double getArea() { return (1.0 / 2.0) * width * height; }

	// 세터 함수 
	void setWidth(int a) { width = a; }
	void setHeight(int b) { height = b; }
};


int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
	return 0;
}
