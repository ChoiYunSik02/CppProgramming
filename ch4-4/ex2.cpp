# 실습과제 2 - 문자열 이어붙이기 (줄별 설명)

---

## 실행 결과 예시

```
문자열 입력 : hello
이어진 문자열: <1>hello
문자열 입력 : world
이어진 문자열: <1>hello<2>world
문자열 입력 : C++
이어진 문자열: <1>hello<2>world<3>C++
문자열 입력 : quit
```

---

## 전체 코드 (줄별 설명)

```cpp
// 표준 입출력 헤더 (cout, cin 사용)
#include <iostream>

// string 클래스 사용을 위한 헤더
#include <string>

// std:: 접두사 생략을 위한 선언
using namespace std;

int main() {

    // 지금까지 이어붙인 전체 문자열 저장 변수, 처음엔 빈 문자열로 초기화
    string result = "";

    // 몇 번째 입력인지 번호를 추적하는 카운터, 1부터 시작
    int count = 1;

    // "quit"를 입력할 때까지 계속 반복
    while (true) {

        // 이번에 입력받을 문자열을 저장하는 임시 변수
        string input;

        // 입력 안내 문구 출력 (줄바꿈 없이)
        cout << "문자열 입력 : ";

        // 엔터키('\n')를 구분문자로 삼아 한 줄 전체를 input에 저장
        // cin >> 와 달리 공백도 그대로 포함해서 읽음
        getline(cin, input, '\n');

        // input이 "quit"이면 while 루프 즉시 탈출 → 프로그램 종료
        if (input == "quit") break;

        // "<번호>입력값" 형태를 result 뒤에 이어붙임
        // to_string(count) : 정수를 문자열로 변환 (예: 2 → "2")
        // "+" : string 연결 연산자
        // "+=" : result = result + 새 조각
        result += "<" + to_string(count) + ">" + input;

        // 다음 입력을 위해 번호 1 증가
        count++;

        // 현재까지 누적된 전체 문자열 출력
        cout << "이어진 문자열: " << result << endl;
    }

    return 0;
}
```

---

## 핵심 동작 예시 (count=2, input="world" 일 때)

```
result 현재값  →  "<1>hello"
to_string(2)  →  "2"
조립 결과      →  "<" + "2" + ">" + "world"  =  "<2>world"
result +=      →  "<1>hello" + "<2>world"    =  "<1>hello<2>world"
```
