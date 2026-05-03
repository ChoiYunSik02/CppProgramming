// **********************************************
// 제 목 : C++ ch05-1 실습과제3 - 주소에 의한 호출
// 날 짜 : 2026년 05월 03일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;
string GetLatterString(string* s1, string* s2);
int main() {
	string s1("hello");
	string s2("world");
	string res;
	res = GetLatterString(&s1, &s2);
	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다." << endl;
}

string GetLatterString(string* s1, string* s2)
{
	if (*s1 > *s2)
		return *s1; // s1이 사전 순으로 뒤에 오면 s1
	else
		return *s2; // 그렇지 않으면 s2
}
