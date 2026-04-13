//
// 제목: 3장 실습문제 1번
//

#include <iostream>
#include <cstring> // C언어 스타일 문자열 함수(strcpy 등)를 쓰기 위한 헤더입니다.
using namespace std;

class Picture {
    int width, height; // 사진의 가로, 세로 길이를 저장합니다.
    char place[50];    // 촬영 장소를 저장할 50칸짜리 문자 배열입니다. (string 대체)
public:
    Picture(); // 매개변수가 없는 기본 생성자입니다.
    Picture(int w, int h, const char* p); // 가로, 세로, 장소를 받는 생성자입니다.
    
    // 외부에서 멤버 변수의 값을 읽어갈 수 있도록 해주는 Getter 함수들입니다.
    int getWidth() { return width; }
    int getHeight() { return height; }
    char* getPlace() { return place; }
};

// [위임 생성자]
// 매개변수 없이 Picture()가 호출되면, 아래에 있는 매개변수 3개짜리(타겟) 생성자에게
// 5, 7, "모름"을 넘겨서 대신 초기화하라고 일을 맡깁니다.
Picture::Picture() : Picture(5, 7, "모름") { } 

// [타겟 생성자 & 멤버 초기화 리스트]
// 객체가 만들어질 때 width에는 w값을, height에는 h값을 바로 넣습니다. (: width(w), height(h))
Picture::Picture(int w, int h, const char* p) : width(w), height(h) {
    // 문자 배열은 '=' 기호로 값을 넣을 수 없어서 strcpy(도착지, 출발지)로 복사해 넣습니다.
    strcpy(place, p); 
}

int main() {
    Picture pic; // 위임 생성자가 불려서 가로 0, 세로 0, 빈 장소로 초기화됩니다.
    Picture mt(10, 14, "한라산"); // 타겟 생성자가 불려서 설정됩니다.
    
    // 각 객체의 정보를 화면에 출력합니다.
    cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
    cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
}
