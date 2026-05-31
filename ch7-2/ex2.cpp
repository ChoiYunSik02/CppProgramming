// **********************************************
// 제 목 : C++ ch07-2 실습과제2 - 복소수 곱셈 연산자
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
    Complex operator*(Complex op2);
};

void Complex::show() {
    cout << " " << real << "+" << img << "j" << endl;
}

Complex Complex::operator*(Complex op2) {
    Complex tmp;
    tmp.real = this->real * op2.real - this->img * op2.img;
    tmp.img  = this->real * op2.img  + this->img * op2.real;
    return tmp;
}

int main() {
    Complex x(2, 3), y(-5, 10), sum;
    sum = x * y;
    cout << "두 복소수의 곱은";
    sum.show();
    return 0;
}
