// **********************************************
// 제 목 : 3-5장 실습과제 3번 교재 149 페이지 3번문제
// 날 짜 : 2026년 03월 29일
// 작성자 : 2101091 최윤식
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Account {
private:
	char user[20]; // 이름 저장
	int balance; // 잔액
public:
	Account(const char* name); // 이름 받는 생성자
	void deposit(int money); // 잔액을 더하는 함수
	int withdraw(int money); // 출금 후 실제 출금액 반환
	const char* getUser(); // 이름 반환
	int inquiry(); // 잔액 반환 
};

// 이름 초기화, 잔액 0
Account::Account(const char* name) : balance(0) {
	strcpy(user, name);
}

// 입금 함수
void Account::deposit(int money) {
	balance += money;
}

// 출금 함수
int Account::withdraw(int money) {
	if (money > balance) { // 만약 잔액보다 출금하려는 돈이 많다면
		int temp = balance; // 현재 잔액 저장
		balance = 0; // 잔액을 0으로 초기화
		return temp; // 잔액 리턴 
	}
	balance -= money; // 잔액이 출금하려는 돈보다 많다면 
	return money; // 출금 금액 리턴 
}

// 이름 반환 
const char* Account::getUser() {
	return user;
}

// 잔액 반환
int Account::inquiry() {
	return balance;
}

int main() {
	Account a("황수희"); // 사용자 
	a.deposit(20000); // 20000원 입금
	cout << a.getUser() << " 잔액은 " << a.inquiry() << endl; // 사용자의 잔액 출력

	int money = a.withdraw(15000); // 15000원 출금 
	cout << money << "원 출금, "; // 출금 표시 
	cout << a.getUser() << " 잔액은 " << a.inquiry() << endl; // 현재 잔액 표시

	money = a.withdraw(8000);   // 잔액 5000 < 요청 8000 → 5000 출금
	cout << money << "원 출금, "; // 현재 남아있는 잔액을 출금 표시
	cout << a.getUser() << " 잔액은 " << a.inquiry() << endl; // 현재 잔액 표시 

	return 0;
}
