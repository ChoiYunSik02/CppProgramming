// **********************************************
// 제 목 : 3-5장 실습과제 3번 교재 148 페이지 1번문제
// 날 짜 : 2026년 03월 29일
// 작성자 : 2101091 최윤식
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring> // strcpy
using namespace std;

class Picture {
private:
	int width; // 가로 크긱
	int height; // 세로 크기
	char place[20]; // 장소 
public:
	Picture(); // 생성자1
	Picture(int a, int b, const char* p); // 생성자2
	int getWidth(); // 가로 크기 반환
	int getHeight(); // 세로 크기 반환
	const char* getPlace(); // 장소 반환
};

// 기본 생성자 width = 5, height = 7, 장소 : 모름 
Picture::Picture() : width(5), height(7) {
	strcpy(place, "모름");
}

Picture::Picture(int a, int b, const char* p) : width(a), height(b) { strcpy(place, p); }

int Picture::getWidth() { return width; } // 가로 크기 반환
int Picture::getHeight() { return height; } // 세로 크기 반환

const char* Picture::getPlace() {
	return place; // 장소 반환 
}

int main() {
	Picture pic;
	Picture mt(10, 14, "한라산");
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
	return 0;
}
