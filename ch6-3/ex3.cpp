// **********************************************
// 제 목 : C++ ch06-3 실습과제 3 - Triangle 클래스
// 날 짜 : 2026년 05월 18일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
    static int numOfTriangle; // 생존 중인 삼각형 객체 수 (static: 모든 객체 공유)

public:
    // 생성자: 객체가 생성될 때마다 카운트 증가
    Triangle() {
        numOfTriangle++;
    }

    // 소멸자: 객체가 소멸될 때마다 카운트 감소
    ~Triangle() {
        numOfTriangle--;
    }

    // static 멤버 함수: 현재 생존 중인 삼각형 개수 반환
    static int getNumofTriangle() {
        return numOfTriangle;
    }
};


// static 멤버 변수 전역 공간 정의 (초기값 0)
// 반드시 클래스 외부에 선언해야 실제 메모리 할당됨
int Triangle::numOfTriangle = 0;

// main 함수
int main() {
    // 동적으로 Triangle 객체 5개 생성 → 생성자 5번 호출 → numOfTriangle = 5
    Triangle* tri1 = new Triangle[5];
    cout << "생성된 삼각형의 개수 :" << Triangle::getNumofTriangle() << endl;
    // 출력: 5

    // tri1 배열 삭제 → 소멸자 5번 호출 → numOfTriangle = 0
    delete[] tri1;

    // 스택에 Triangle 객체 15개 생성 → 생성자 15번 호출 → numOfTriangle = 15
    Triangle tri2[15];
    cout << "생성된 삼각형의 개수 :" << Triangle::getNumofTriangle() << endl;
    // 출력: 15

    return 0;
    // main 종료 시 tri2[15] 자동 소멸 → 소멸자 15번 호출 → numOfTriangle = 0
}
