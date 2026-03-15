// **********************************************
// 제 목 : ch2-2 실습과제3
// 날 짜 : 2026년 03월 12일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
    int id;
    string name, address;

    cout << "학번을 입력하시오: ";
    cin >> id;
    cin.ignore(); // 키보드 버퍼에 남아있는 엔터키('\n') 제거

    cout << "이름을 입력하시오: ";
    getline(cin, name);

    cout << "주소를 입력하시오: ";
    getline(cin, address);

    cout << endl;
    cout << "1.학번:" << id << endl;
    cout << "2.이름:" << name << endl;
    cout << "3.주소:" << address << endl;

    return 0;
}

// 다른 방법
#include <iostream>
using namespace std;

int main() {
	int number;
	char name[100];
	char address[100];

	cout << "학번을 입력하시오: ";
	cin >> number;
	cin.ignore();

	cout << "이름을 입력하세요: ";
	cin.getline(name, sizeof(name), '\n');

	cout << "주소를 입력하세요: ";
	cin.getline(address, sizeof(address), '\n');
	
	cout << endl; // 단순 줄바꿈
	cout << "1.학번: " << number << endl;
	cout << "2.이름: " << name << endl;
	cout << "3.주소: " << address << endl;
	return 0;
}
