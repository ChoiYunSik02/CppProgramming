// **********************************************
// 제 목 : C++ ch05 실습과제5 - 배열에서 최대 문자열 탐색
// 날 짜 : 2026년 05월 03일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;
string StudentName(string arr[], int size); // 배열과 크기를 매개변수로 받음

int main() {
	string names[5]; //// string 객체 배열 선언
	for (int i = 0; i < 5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}
	string res = StudentName(names, 5); // 배열과 크기를 인수로 전달
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << res << endl;
}

string StudentName(string arr[], int size)
{
	string last = arr[0]; // 가장 뒤에 오는 문자열을 저장할 변수, 첫 번째 원소로 초기화

	for (int i = 1; i < size; i++) { // 두번째 이름부터 마지막까지 순회
		if (arr[i] > last) // 현재 이름이 last 보다 사전 순으로 뒤에 오면
			last = arr[i]; // last를 현재 이름으로 갱신
	}

	return last; // 사전 순으로 가장 뒤에 오는 문자열 반환
}
