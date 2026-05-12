// **********************************************
// 제 목 : C++ ch05-4 실습과제2 - string 클래스를 이용한 깊은 복사
// 날 짜 : 2026년 05월 12일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
#include <cstring>
using namespace std;

class Person {
	string name;
	int id;
public:
	Person(int id, const string& name);
	// 복사 생성자 불필요 (string이 자동으로 깊은 복사 수행)
	// 소멸자 불필요 (string이 자동으로 메모리 해제)
	void changeName(const string& name);
	void show() { cout << id << ',' << name << endl; }
};

// 생성자 구현
Person::Person(int id, const string& name) {
	this->id = id;
	this->name = name; // string 대입
}

// 이름 변경함수
void Person::changeName(const string& name) {
	if (name.length() > this->name.length()) return;
	this->name = name;
}

int main() {

	Person father(1, "Kitae");          // 일반 생성자 호출
	Person daughter(father);            // 디폴트 복사 생성자 호출
	// string이 자동으로 깊은 복사 수행
	cout << "daughter 객체 생성 직후 ----" << endl;
	father.show();                      // 1,Kitae 출력
	daughter.show();                    // 1,Kitae 출력

	daughter.changeName("Grace");       // daughter의 이름만 변경
	cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
	father.show();                      // 1,Kitae (father는 영향 없음)
	daughter.show();                    // 1,Grace

	return 0;
	// father, daughter 소멸 시 string이 자동으로 메모리 해제
}
