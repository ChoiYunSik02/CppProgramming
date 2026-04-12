// **********************************************
// 제 목 : C++ ch04-4 실습과제3번 - 문자 'a' 개수 세기
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "문자열 입력 : ";
    getline(cin, s, '\n');

    int count = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'a') count++;
    }

    cout << "문자 a는 " << count << "개 있습니다." << endl;

    return 0;
}
