// **********************************************
// 제 목 : C++ ch05-2 실습과제2 - 참조에 의한 호출
// 날 짜 : 2026년 05월 07일
// 작성자 : 2101091 최윤식
// **********************************************
#include<iostream>
using namespace std;

void add2(int& value);  // 참조 매개변수로 선언

int main(void)
{
    int number;
    cout << "정수를 입력하세요 : ";
    cin >> number;
    add2(number);       // 호출 방식은 값에 의한 호출과 동일
    cout << "2만큼 증가한 값 : " << number << endl;
    return 0;
}

// value는 number의 별명 → value에 대한 연산 = number에 대한 연산
void add2(int& value)
{
    value += 2;         // number += 2 와 동일한 효과
}
