// **********************************************
// 제 목 : C++ ch07-2 실습과제3 - 복소수 += 연산자
// 날 짜 : 2026년 05월 31일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;
public:
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img = img;
    }
    void show();
    Complex& operator+=(Complex op2);
};

void Complex::show() {
    cout << real << "+" << img << "j" << endl;
}

Complex& Complex::operator+=(Complex op2) {
    this->real = this->real + op2.real;
    this->img  = this->img  + op2.img;
    return *this;
}

int main() {
    Complex a(3, 5), b(1, 1);
    a.show();
    b.show();
    b += a;
    a.show();
    b.show();
    return 0;
}
