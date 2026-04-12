// **********************************************
// 제 목 : C++ ch04 실습문제4 - 8번 (URL 파싱)
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string url;
        cout << "웹 주소 입력>>";
        getline(cin, url, '\n');

        if (url == "그만") break;

        // 1. 프로토콜 추출: "://" 앞부분
        int protoEnd = url.find("://");
        string protocol = url.substr(0, protoEnd);

        // 2. 호스트 시작 인덱스 ("://" 다음)
        int hostStart = protoEnd + 3;

        // 3. ":" (포트 구분자)와 "/" (경로 시작) 위치 탐색
        int colonPos = url.find(':', hostStart);
        int slashPos = url.find('/', hostStart);

        string host, port, rest;

        if (colonPos != (int)string::npos && colonPos < slashPos) {
            // 포트 번호가 명시된 경우: protocol://host:port/path
            host = url.substr(hostStart, colonPos - hostStart);

            int portEnd = (slashPos != (int)string::npos) ? slashPos : (int)url.length();
            port = url.substr(colonPos + 1, portEnd - colonPos - 1);

            rest = (slashPos != (int)string::npos) ? url.substr(slashPos) : "/";
        }
        else {
            // 포트 번호가 없는 경우: 기본값 80
            if (slashPos != (int)string::npos) {
                host = url.substr(hostStart, slashPos - hostStart);
                rest = url.substr(slashPos);
            }
            else {
                host = url.substr(hostStart);
                rest = "/";
            }
            port = "80";
        }

        cout << "프로토콜: " << protocol << endl;
        cout << "호스트: " << host << endl;
        cout << "포트: " << port << endl;
        cout << "나머지 부분: " << rest << endl;
    }

    return 0;
}
