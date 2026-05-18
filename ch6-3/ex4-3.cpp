// **********************************************
// 제 목 : C++ ch06-3 실습과제 4 - 5번 Vector 클래스
// 날 짜 : 2026년 05월 18일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

// Vector 클래스 선언
// 동적 할당 배열에 데이터를 저장하는 클래스
class Vector {
    int* mem;  // 생성자에서 배열 할당. 할당받은 배열의 주소 저장
    int size;  // 생성자에서 할당받은 배열의 크기

public:
    // (1) 생성자 중복 버전
    // 생성자 1: 인수 없음 → 크기 5, 0으로 초기화
    Vector() {
        size = 5;                         // 기본 크기 5
        mem = new int[size];              // 동적 배열 할당
        for (int i = 0; i < size; i++)    // 배열 모든 원소를
            mem[i] = 0;                   // 0으로 초기화
    }

    // 생성자 2: 크기와 초기값을 인수로 받음
    Vector(int size, int initVal) {
        this->size = size;                // 전달받은 크기 저장
        mem = new int[size];              // 동적 배열 할당
        for (int i = 0; i < size; i++)    // 배열 모든 원소를
            mem[i] = initVal;             // 전달받은 값으로 초기화
    }

    // 소멸자: 동적 할당한 배열 메모리 해제
    ~Vector() {
        delete[] mem;
    }
    // (1) show() 멤버 함수 중복 (오버로딩) 버전

    // show(): 벡터의 모든 원소 출력
    void show() {
        for (int i = 0; i < size; i++)    // 배열 전체 순회
            cout << mem[i] << " ";        // 각 원소 출력
        cout << endl;
    }

    // show(n): 벡터의 앞 n개 원소만 출력
    void show(int n) {
        for (int i = 0; i < n; i++)       // 앞 n개만 순회
            cout << mem[i] << " ";        // 각 원소 출력
        cout << endl;
    }


    // (2) 디폴트 매개 변수 버전 — 주석 처리

    // [생성자 디폴트 버전]
    // Vector(int size = 5, int initVal = 0) {
    //     this->size = size;
    //     mem = new int[size];
    //     for (int i = 0; i < size; i++)
    //         mem[i] = initVal;
    // }

    // [show() 디폴트 버전]
    // n = -1 이면 전체 출력, 아니면 앞 n개 출력
    // void show(int n = -1) {
    //     int count = (n == -1) ? size : n;  // 출력할 원소 수 결정
    //     for (int i = 0; i < count; i++)
    //         cout << mem[i] << " ";
    //     cout << endl;
    // }
};

// main 함수

int main() {
    Vector x;           // 생성자 1 호출: 크기 5, 0으로 초기화
    Vector y(10, 8);    // 생성자 2 호출: 크기 10, 8로 초기화

    x.show();           // x의 모든 원소 출력: 0 0 0 0 0
    y.show();           // y의 모든 원소 출력: 8 8 8 8 8 8 8 8 8 8
    y.show(3);          // y의 앞 3개 원소 출력: 8 8 8

    return 0;
}
