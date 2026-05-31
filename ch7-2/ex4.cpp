// **********************************************
// 제 목 : C++ ch07-2 실습과제4 - 복소수와 정수 뺄셈 연산자
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
    Complex operator-(int op2);
};

void Complex::show() {
    cout << real << "+" << img << "j" << endl;
}

Complex Complex::operator-(int op2) {
    Complex tmp;
    tmp.real = this->real - op2;
    tmp.img  = this->img  - op2;
    return tmp;
}

int main() {
    Complex a(3, 5), b;
    a.show();
    b.show();
    b = a - 2;
    a.show();
    b.show();
    return 0;
}
