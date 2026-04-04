// **********************************************
// 제 목 : ch04-2 실습과제 4번 - 실수 최대값 구하기
// 날 짜 : 2026년 04월 4일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

int main() {
	cout << "입력할 실수의 개수를 입력하세요: ";
	double n;
	cin >> n; // 정수의 개수 입력 

	if (n <= 0) return -1;
	double* p = new double[n]; // n개의 정수 배열 동적할당 
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;
	}

	cout << n << "개의 실수를 입력하시오. " << endl; // 한번만 실행

	for (int i = 0; i < n; i++) {
		cin >> p[i]; // n개 만큼 배열에 값 저장 
	}

	// 최대값 계산 
	double max = p[0]; // 첫번째 원소를 최대값으로 초기화 
	for (int i = 0; i < n; i++) {
		if (p[i] > max) max = p[i];
	}

	// 출력 
	cout << "최대값은 " << max << "입니다." << endl;
	delete[] p;
}
