// **********************************************
// 제 목 : ch02-1 실습과제4
// 날 짜 : 2026년 03월 12일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>

using namespace std;

int main() {
    // X자 모양의 크기 (7x7)
    int size = 7;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // 주 대각선(i == j) 이거나, 부 대각선(i + j == size - 1)일 때 별 출력
            if (i == j || i + j == size - 1) {
                cout << "*";
            }
            else {
                cout << " "; // 그 외에는 공백 출력
            }
        }
        cout << endl; // 한 행이 끝나면 줄바꿈
    }

    return 0;
}
