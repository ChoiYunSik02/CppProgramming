// **********************************************
// 제 목 : C++ ch06-3 실습과제 4 - 2번 printMatrix
// 날 짜 : 2026년 05월 18일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;


// (1) 함수 중복
// printMatrix() — 인수 없음: 2x2 행렬에 '*' 출력
void printMatrix() {
    for (int i = 0; i < 2; i++) {        // 행 반복 (2행)
        for (int j = 0; j < 2; j++)      // 열 반복 (2열)
            cout << '*';                 // '*' 출력
        cout << endl;                    // 행 끝에 줄바꿈
    }
}

// printMatrix(r, c) — 행/열 지정: r x c 행렬에 '*' 출력
void printMatrix(int r, int c) {
    for (int i = 0; i < r; i++) {        // 행 반복
        for (int j = 0; j < c; j++)      // 열 반복
            cout << '*';                 // '*' 출력
        cout << endl;
    }
}

// printMatrix(r, c, ch) — 행/열/문자 모두 지정: r x c 행렬에 ch 출력
void printMatrix(int r, int c, char ch) {
    for (int i = 0; i < r; i++) {        // 행 반복
        for (int j = 0; j < c; j++)      // 열 반복
            cout << ch;                  // 지정된 문자 출력
        cout << endl;
    }
}


// (2) 디폴트 매개 변수 버전 (하나의 함수로 해결)

// r=2, c=2, ch='*' 가 디폴트값
// printMatrix()         → 2x2 '*'
// printMatrix(2,5,'a')  → 2x5 'a'
// printMatrix(1,10)     → 1x10 '*'
// void printMatrix(int r = 2, int c = 2, char ch = '*') {
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++)
//             cout << ch;
//         cout << endl;
//     }
// }


// main 함수
int main() {
    printMatrix();           // 2x2 행렬에 '*' 출력
    printMatrix(2, 5, 'a');  // 2x5 행렬에 'a' 출력
    printMatrix(1, 10);      // 1x10 행렬에 '*' 출력

    return 0;
}
