// **********************************************
// 제 목 : C++ ch07 실습과제1 - 복소수 덧셈 연산자
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
    Complex operator+(Complex op2);
};

void Complex::show() {
    cout << " " << real << "+" << img << "j" << endl;
}

Complex Complex::operator+(Complex op2) {
    Complex tmp;
    tmp.real = this->real + op2.real;
    tmp.img  = this->img  + op2.img;
    return tmp;
}

int main() {
    Complex x(2, 3), y(-5, 10), sum;
    sum = x + y;
    cout << "두 복소수의 합은";
    sum.show();
    return 0;
}
