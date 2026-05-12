// **********************************************
// 제 목 : C++ ch05-4 실습과제3 - MyStack 클래스 (복사 생성자 포함)
// 날 짜 : 2026년 05월 12일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class MyStack {
    int* p;      // 정수를 저장할 동적 배열에 대한 포인터
    int size;    // 할당받은 동적 배열의 크기
    int tos;     // 다음에 저장될 배열 원소의 인덱스 (top of stack)
public:
    MyStack();                          // 기본 생성자
    MyStack(int size);                  // size 크기의 스택 생성
    MyStack(const MyStack& src);        // 복사 생성자 (깊은 복사)
    ~MyStack();                         // 소멸자

    bool push(int n);   // 정수 n을 스택에 푸시. 꽉 차면 false, 아니면 true 리턴
    bool pop(int& n);   // 스택 탑의 값을 n에 팝. 비어 있으면 false, 아니면 true 리턴
};

// 기본 생성자
MyStack::MyStack() : size(0), tos(0), p(nullptr) {}

// size 크기의 동적 배열 할당 생성자
MyStack::MyStack(int size) {
    this->size = size;
    this->tos = 0;
    this->p = new int[size]; // size 크기만큼 힙에 동적 할당
}

// 복사 생성자 - 깊은 복사
// MyStack b = a; 또는 MyStack b(a); 호출 시 실행
MyStack::MyStack(const MyStack& src) {
    this->size = src.size;  // 배열 크기 복사
    this->tos = src.tos;   // 현재 스택 상태(인덱스) 복사

    // 원본과 별개인 새 메모리를 할당 (깊은 복사의 핵심)
    this->p = new int[src.size];

    // 원본 스택의 데이터를 새 배열에 복사
    for (int i = 0; i < src.tos; i++) {
        this->p[i] = src.p[i];
    }
}

// 소멸자: 동적 할당된 배열 해제
MyStack::~MyStack() {
    if (p) delete[] p;
}

// 스택 푸시
bool MyStack::push(int n) {
    if (tos == size) return false; // 스택이 꽉 찬 경우
    p[tos++] = n;                  // 값 저장 후 tos 증가
    return true;
}

// 스택 팝
bool MyStack::pop(int& n) {
    if (tos == 0) return false; // 스택이 비어 있는 경우
    n = p[--tos];               // tos 감소 후 값 반환
    return true;
}

int main() {
    MyStack a(10);              // 10개 저장 공간의 스택 a 생성
    a.push(10); a.push(20);     // a: [10, 20]

    MyStack b = a;              // 복사 생성자 호출 → b: [10, 20] (a와 별개의 메모리)
    b.push(30);                 // b: [10, 20, 30]

    int n;
    a.pop(n);                   // a의 탑(20) 팝
    cout << "스택 a에서 팝한 값 " << n << endl;  // 20 출력

    b.pop(n);                   // b의 탑(30) 팝
    cout << "스택 b에서 팝한 값 " << n << endl;  // 30 출력

    return 0;
    // b, a 순서로 소멸 → 각자의 메모리를 해제하므로 오류 없음
}
