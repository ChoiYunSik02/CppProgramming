//// **********************************************
//// 제 목 : ch04-3 실습과제 4번
//// 날 짜 : 2026년 04월 7일
//// 작성자 : 2101091 최윤식
//// **********************************************

#include <iostream>
using namespace std;

class Triangle {
    int base, height;
public:
    Triangle() {
        base = 1; height = 1;
    }
    Triangle(int b, int h) {
        base = b;
        height = h;
        cout << "밑변 " << base << " 높이 " << height << "인 삼각형 생성\n";
    }

    ~Triangle() {
        cout << "밑변 " << base << " 높이 " << height << "인 삼각형 소멸\n";
    }

    double getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Triangle* tri = new Triangle[3]{
        Triangle(1,1),
        Triangle(2,2),
        Triangle(4,4)
    };

    for (int i = 0; i < 3; i++) {
        cout << "삼각형의 면적은 " << tri[i].getArea() << "\n";
    }

    delete[] tri;
    return 0;
}
