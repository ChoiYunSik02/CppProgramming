// **********************************************
// 제 목 : C++ ch07 실습과제2 - 복소수 덧셈 (전역 프렌드 함수)
// 날 짜 : 2026년 05월 26일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

// Complex 클래스 선언
class Complex {
    int real; // 복소수의 실수부
    int img;  // 복소수의 허수부

public:
    // 생성자: 실수부와 허수부를 인자로 받아 초기화
    // 기본값 0으로 설정하여 Complex sum; 처럼 인자 없이도 생성 가능
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img = img;
        cout << "복소수 " << real << "+ " << img << "j 생성" << endl;
    }

    // show(): 복소수를 "실수부+허수부j" 형식으로 출력하는 멤버 함수
    void show() {
        cout << " " << real << "+" << img << "j" << endl;
    }

    // 전역 함수 ComplexAdd를 프렌드로 선언
    // → 프렌드 선언 덕분에 ComplexAdd()가 private 멤버 real, img에 접근 가능
    friend Complex ComplexAdd(Complex x, Complex y);
};

// 전역 프렌드 함수: ComplexAdd
// 두 복소수를 더한 결과를 새로운 Complex 객체로 반환
// 복소수 덧셈 공식: (a+bj) + (c+dj) = (a+c) + (b+d)j
Complex ComplexAdd(Complex x, Complex y) {
    Complex result;
    result.real = x.real + y.real; // 실수부끼리 합산
    result.img = x.img + y.img;  // 허수부끼리 합산

    // 합산된 실수부와 허수부로 새로운 Complex 객체 생성 후 반환
    return Complex(result);
}

// main 함수
int main() {
    Complex x(2, 3);   // 복소수 2+3j 생성
    Complex y(-5, 10); // 복소수 -5+10j 생성
    Complex sum;       // 기본 생성자 호출 → 복소수 0+0j 생성

    // ComplexAdd 전역 함수 호출 → 내부에서 Complex 객체 생성 후 sum에 대입
    sum = ComplexAdd(x, y);

    cout << "두 복소수의 합은";
    sum.show(); // 결과 출력

    return 0;
}
