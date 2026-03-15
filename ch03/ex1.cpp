// **********************************************
// 제 목 : sizeof(클래스명) 활용 코드
// 날 짜 : 2026년 03월 15일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class A {
    // 멤버 없음
};

class B {
    int x;        // 4 bytes
    double y;     // 8 bytes
};

class C {
    int x;        // 4 bytes
    char c;       // 1 byte (+ 패딩 3 bytes)
    double y;     // 8 bytes
};

int main() {
    cout << "sizeof(A) = " << sizeof(A) << " bytes" << endl;
    cout << "sizeof(B) = " << sizeof(B) << " bytes" << endl;
    cout << "sizeof(C) = " << sizeof(C) << " bytes" << endl;

    return 0;
}
