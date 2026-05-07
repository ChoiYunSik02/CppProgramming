// **********************************************
// 제 목 : C++ ch05 실습과제3 - swap 참조에 의한 호출
// 날 짜 : 2026년 05월 07일
// 작성자 : 2101091 최윤식
// **********************************************

#include<iostream>
using namespace std;

// 함수 선언 (프로토타입)
void swap(int& a, int& b);

int main(void)
{
    int x, y;

    // 두 정수 입력
    cout << "정수x를 입력 하시오: ";
    cin >> x;
    cout << "정수y를 입력 하시오: ";
    cin >> y;

    // swap 호출 전 출력
    cout << "swap함수 호출 전 x=" << x << ", y=" << y << endl;

    // 함수 호출 — 참조에 의한 호출
    swap(x, y);

    // swap 호출 후 출력
    cout << "swap함수 호출 후 x=" << x << ", y=" << y << endl;

    return 0;
}

// 함수 정의 — a, b는 main의 x, y의 별명
void swap(int& a, int& b)
{
    int tmp; // 임시 저장 변수
    tmp = a; // tmp = x
    a = b;   // x = y
    b = tmp; // y = tmp (원래 x값)
}
