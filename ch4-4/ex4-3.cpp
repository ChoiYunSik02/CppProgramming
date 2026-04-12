// **********************************************
// 제 목 : C++ ch04 실습과제4 - 실습문제 5번 (Container 클래스)
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class Container {
    int* p;       // 정수 배열에 대한 포인터
    int size;     // 정수 배열의 크기
public:
    Container(int size);   // 생성자
    ~Container();          // 소멸자
    void read();           // 배열의 크기만큼 정수를 키보드로부터 읽어들이기
    void write();          // 배열에 저장된 전체 정수 출력
    void rotate();         // 배열의 원소들을 오른쪽으로 회전
    double avg();          // 평균 출력
};

Container::Container(int size) {
    this->size = size;
    p = new int[size];
}

Container::~Container() {
    delete[] p;
}

void Container::read() {
    cout << "정수 " << size << "개 입력>>";
    for (int i = 0; i < size; i++) {
        cin >> p[i];
    }
}

void Container::write() {
    for (int i = 0; i < size; i++) {
        cout << p[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

// 오른쪽 회전: 마지막 원소가 맨 앞으로 이동
void Container::rotate() {
    int last = p[size - 1];
    for (int i = size - 1; i > 0; i--) {
        p[i] = p[i - 1];
    }
    p[0] = last;
}

double Container::avg() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += p[i];
    }
    return sum / size;
}

int main() {
    Container c(10);
    c.read();
    c.write();
    c.rotate();
    c.write();
    cout << "평균은 " << c.avg() << endl;
    return 0;
}
