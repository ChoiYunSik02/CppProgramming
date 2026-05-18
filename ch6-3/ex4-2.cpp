// **********************************************
// 제 목 : C++ ch06 실습과제 4 - 3번 equals
// 날 짜 : 2026년 05월 18일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

// (1) 함수 중복버전
// equals(x, y) — x와 y가 완전히 같은지 비교
bool equals(string x, string y) {
    return (x == y);              // 두 문자열 전체 비교
}

// equals(x, y, n) — x와 y의 앞 n글자가 같은지 비교
bool equals(string x, string y, int n) {
    return (x.substr(0, n) == y.substr(0, n));
    // substr(시작위치, 길이): 문자열의 일부를 새 string으로 반환
}

// equals(x, y, n, z) — x, y, z 세 문자열의 앞 n글자가 모두 같은지 비교
bool equals(string x, string y, int n, string z) {
    return (x.substr(0, n) == y.substr(0, n)) &&
        (y.substr(0, n) == z.substr(0, n));
    // x앞n == y앞n 이고 y앞n == z앞n 이면 세 문자열 모두 같음
}


// (2) 디폴트 매개 변수 버전 (하나의 함수로 해결)

// n=0이면 전체 비교, n>0이면 앞 n글자 비교
// z=""이면 두 문자열 비교, z!=""이면 세 문자열 비교
// bool equals(string x, string y, int n = 0, string z = "") {
//     if (n == 0)
//         return (x == y);                         // 전체 비교
//     if (z == "")
//         return (x.substr(0, n) == y.substr(0, n)); // 두 문자열 앞n 비교
//     return (x.substr(0, n) == y.substr(0, n)) &&   // 세 문자열 앞n 비교
//            (y.substr(0, n) == z.substr(0, n));
// }


// main 함수
int main() {
    string x = "Prof. Hwang";
    string y = "Prof. Kim";
    string z = "Prof. Lee";

    // equals(x, y): "Prof. Hwang" == "Prof. Kim" → false → 출력 없음
    if (equals(x, y))
        cout << "같음" << endl;

    // equals(x, y, 3): "Pro" == "Pro" → true → 출력
    if (equals(x, y, 3))
        cout << "앞 3글자 같음" << endl;

    // equals(x, y, 5, z): "Prof." == "Prof." == "Prof." → true → 출력
    if (equals(x, y, 5, z))
        cout << "앞 5글자 같음" << endl;

    return 0;
}
