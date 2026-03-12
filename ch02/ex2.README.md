# 1장 실습과제 2 — 이름/주소/학번/차종 출력

---

## 소스코드

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "이름 : 홍길동" << endl;
    cout << "주소 : 군산시 대학로 558" << endl;
    cout << "학번 : 201012" << endl;
    cout << "차종 : 벤츠" << endl;
    return 0;
}
```

---

## 코드 설명

| 라인 | 설명 |
|------|------|
| `#include <iostream>` | 표준 입출력 스트림 헤더 포함 — `cout`, `endl` 사용을 위해 필요 |
| `using namespace std;` | `std::cout` 대신 `cout` 으로 줄여 쓸 수 있게 선언 |
| `int main()` | 프로그램의 시작점 |
| `cout << "..." << endl;` | 문자열을 표준 출력(모니터)에 출력. `endl`은 줄바꿈 |
| `return 0;` | 프로그램 정상 종료 |

---

## 실행 결과

```
이름 : 홍길동
주소 : 군산시 대학로 558
학번 : 201012
차종 : 벤츠
```
