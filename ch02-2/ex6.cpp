// **********************************************
// 제 목 : ch2-2 실습과제6 - 교재 90페이지 10번문제를 푸시오.
// 날 짜 : 2026년 03월 12일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    char buf[256];

    while (true) {
        cout << "영문 텍스트를 입력하세요(빈칸 포함 가능)>>";
        cin.getline(buf, 256); // 한 줄 전체 입력 (공백 포함)

        // exit 입력 시 종료
        if (string(buf) == "exit") break;

        // 단어 개수 세기
        int count = 0;
        string word;
        istringstream iss(buf); // 문자열을 스트림으로 변환
        while (iss >> word) {   // 공백 기준으로 단어 하나씩 추출
            count++;
        }

        cout << "단어의 개수는 " << count << "개이다." << endl;
    }

    return 0;
}
