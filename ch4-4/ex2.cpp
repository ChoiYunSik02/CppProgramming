// **********************************************
// 제 목 : ch04-4장 실습과제 2번 - 문자열 이어붙이기
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    string result = "";
    int count = 1;

    while (true) {
        string input;
        cout << "문자열 입력 : ";
        getline(cin, input, '\n');

        if (input == "quit") break;

        result += "<" + to_string(count) + ">" + input;
        count++;
        cout << "이어진 문자열: " << result << endl;
    }

    return 0;
}
