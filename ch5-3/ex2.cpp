// **********************************************
// 제 목 : C++ ch05-3 실습과제2 - Uppercase() 함수 (참조에 의한 호출)
// 날 짜 : 2026년 05월 10일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;
void Uppercase(string& s);

int main() {
	string s1("hello");
	cout << "변환전 문자열 " << s1 << endl;
	Uppercase(s1);
	cout << "변환후 문자열 " << s1 << endl;
	return 0;
}

// 문자를 순회하면서 모든 문자를 대문자로 변환
void Uppercase(string& s)
{
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}
