// **********************************************
// 제 목 : ch2-2 실습과제5 교재 89페이지 8-(1)번문제를 푸시오.
// 날 짜 : 2026년 03월 12일
// 작성자 : 2101091 최윤식
// **********************************************

// 1) char text[100] 을 활용한 버전
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char text[100];

    cout << "빈칸 없이 문자열을 입력하세요>>";
    cin >> text;

    for (int i = 0; i < strlen(text); i++) {
        cout << text[i] << " ";
    }
    cout << endl;

    return 0;
}
