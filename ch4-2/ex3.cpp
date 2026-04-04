// **********************************************
// 제 목 : ch04-2 실습과제 3번 - 정수 평균값 계산
// 날 짜 : 2026년 04월 4일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

int main() {
    cout << "입력할 정수의 개수를 입력하세요: ";
    int n;
    cin >> n;                   // 정수의 개수 입력
    if (n <= 0) return -1;

    int* p = new int[n];        // n개의 정수 배열 동적 할당
    if (!p) {
        cout << "메모리를 할당할 수 없습니다.";
        return -1;
    }

    cout << n << "개의 정수를 입력하시오. " << endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i];            // n개 만큼 배열에 값 저장
    }

    // 합 계산
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i];
    }

    // 출력
    cout << "평균값은 " << sum / n << "입니다." << endl;

    delete[] p;                 // 동적 할당 메모리 반환
}
