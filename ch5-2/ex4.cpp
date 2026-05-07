// **********************************************
// 제 목 : C++ ch05-2 실습과제4 - 정수부/소수부 분리
// 날 짜 : 2026년 05월 07일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

// 함수 선언 (프로토타입)
void get_parts(double num, int& intpart, double& fracpart);

int main() {
    double num; // 입력받을 실수
    int ip;     // 정수부 저장 변수
    double fp;  // 소수부 저장 변수

    cout << "실수를 입력하시오 : ";
    cin >> num;

    // 함수 호출
    get_parts(num, ip, fp);

    // 결과 출력
    cout << "정수부 : " << ip << endl;
    cout << "소수부 : " << fp << endl;

    return 0;
}

// intpart는 메인함수의 ip의 별명, fracpart는 메인함수의 fp의 별명
void get_parts(double num, int& intpart, double& fracpart)
{
    intpart  = (int)num;          // 실수를 int형으로 변환 (정수표현)
    fracpart = num - intpart;     // 원본 실수에서 정수부를 빼면 소수부
}
