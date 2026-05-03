// **********************************************
// 제 목 : C++ ch05 실습과제4 - 객체 교환 함수
// 날 짜 : 2026년 05월 03일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;
string SwapString(string* s1, string* s2);
int main() {
	string s1("hello");
	string s2("world");
	cout << "호출전 s1:" << s1 << " s2:" << s2 << endl;
	SwapString(&s1, &s2);
	cout << "호출후 s1:" << s1 << " s2:" << s2 << endl;
}

string SwapString(string* s1, string* s2)
{
	string tmp; // 임시 객체 선언
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	return tmp;
}
