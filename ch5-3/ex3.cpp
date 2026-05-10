// **********************************************
// 제 목 : C++ ch05-3 실습과제3 - SwapString() 함수 (참조에 의한 호출)
// 날 짜 : 2026년 05월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;
void SwapString(string& a, string& b);

int main() {
	string s1("hello");
	string s2("world");
	cout << "교환전 문자열 " << s1 << ' ' << s2 << endl;
	SwapString(s1, s2);
	cout << "교환후 문자열 " << s1 << ' ' << s2 << endl;
	return 0;
}

void SwapString(string& a, string& b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
}


