// **********************************************
// 제 목 : C++ ch05-4 실습과제4 - Collector 클래스 (교재 282p 13번)
// 날 짜 : 2026년 05월 12일
// 작성자 : 2101091 최윤식
// **********************************************
// 문항 (1): 생성자, show(), 외부 함수 calcAvg() 구현
// 문항 (2): 소멸자 추가 → 얕은 복사 문제 발생 원인 설명
// 문항 (3): 복사 생성자 추가 → 정상 동작하도록 수정

#include <iostream>
using namespace std;

class Collector {
    int* p;       // 데이터를 저장하는 동적 배열
    int size = 0; // 데이터 개수
public:
    // 문항 (1): 생성자
    Collector(int size, int values[]);

    // 문항 (3): 복사 생성자 (깊은 복사)
    // calcAvg(Collector c)에서 값 전달 시 복사 생성자 호출됨
    Collector(const Collector& src);

    // 문항 (2): 소멸자
    ~Collector() { delete[] p; }

    // 문항 (1): show() 구현
    void show();

    int getSize() { return size; }
    int get(int index) { return p[index]; }
};

// 생성자: size 크기의 동적 배열 할당 후 values 데이터 복사
Collector::Collector(int size, int values[]) {
    this->size = size;
    this->p = new int[size]; // size 크기만큼 동적 할당
    for (int i = 0; i < size; i++) {
        p[i] = values[i];       // values 배열에서 size개만큼 복사
    }
}

// 복사 생성자: 깊은 복사
// calcAvg(Collector c) 호출 시 매개변수 c로 복사 생성자가 호출됨
Collector::Collector(const Collector& src) {
    this->size = src.size;
    this->p = new int[src.size]; // 새 메모리 별도 할당
    for (int i = 0; i < src.size; i++) {
        this->p[i] = src.p[i];      // 데이터 복사
    }
}

// show(): 데이터 개수와 저장된 값들을 출력
void Collector::show() {
    cout << "데이터 수 " << size << ": ";
    for (int i = 0; i < size; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

// 외부 함수: Collector 객체를 값으로 전달받아 평균 계산
// 값 전달(pass by value) → 복사 생성자 호출 → 깊은 복사 필요
double calcAvg(Collector c) {
    int sum = 0;
    for (int i = 0; i < c.getSize(); i++) {
        sum += c.get(i);
    }
    return (double)sum / c.getSize();
}

int main() {
    int temp[] = { 69, 70, 71, 72, 74 };
    Collector weight(4, temp);          // size=4 → 69, 70, 71, 72만 저장 (74는 제외)

    double avg = calcAvg(weight);       // 복사 생성자 호출 후 평균 계산
    weight.show();                      // 데이터 수 4: 69 70 71 72
    cout << "평균은 " << avg << endl;  // 평균은 70.5

    return 0;
}

