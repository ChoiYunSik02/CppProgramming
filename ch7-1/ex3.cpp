// **********************************************
// 제 목 : C++ ch07 실습과제3 - 복소수 덧셈 (다른 클래스의 멤버 프렌드 함수)
// 날 짜 : 2026년 05월 26일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Complex;

class ComplexManager {
public:
    Complex ComplexAdd(Complex x, Complex y);
};

class Complex {
    int real;
    int img;

public:
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img = img;
        cout << "복소수 " << real << "+ " << img << "j 생성" << endl;
    }

    void show() {
        cout << " " << real << "+" << img << "j" << endl;
    }

    friend Complex ComplexManager::ComplexAdd(Complex x, Complex y);
};

Complex ComplexManager::ComplexAdd(Complex x, Complex y) {
    Complex result;
    result.real = x.real + y.real;
    result.img = x.img + y.img;
    return result;
}

int main() {
    Complex x(2, 3), y(-5, 10), sum;
    ComplexManager man;
    sum = man.ComplexAdd(x, y);
    cout << "두 복소수의 합은";
    sum.show();
    return 0;
}
