// **********************************************
// 제 목 : C++ ch04 실습문제 4번 - 4번 (알파벳과 빈칸만 필터링)
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "텍스트 입력(한글 안 됨)>>";
    getline(cin, s, '\n');

    string dest = "";
    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];
        if (isalpha(ch) || ch == ' ') {
            dest += ch;
        }
    }

    cout << dest << endl;
    return 0;
}
