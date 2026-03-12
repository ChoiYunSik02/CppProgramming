# ch2-2 실습과제3번 — 학번, 이름, 주소 입력 및 출력

---

## 코드 설명

| 라인 | 설명 |
|------|------|
| `#include <string>` | string 자료형 사용을 위한 헤더 포함 |
| `int id;` | 학번을 저장할 정수형 변수 선언 |
| `string name, address;` | 이름, 주소를 저장할 문자열 변수 선언 |
| `cin >> id;` | 키보드에서 학번(정수)을 입력받아 저장 |
| `cin.ignore();` | `cin >>` 후 버퍼에 남아있는 엔터키(`\n`)를 제거 |
| `getline(cin, name);` | 공백 포함 한 줄 전체를 이름으로 입력받아 저장 |
| `getline(cin, address);` | 공백 포함 한 줄 전체를 주소로 입력받아 저장 |

### cin.ignore()가 필요한 이유

```
cin >> id;       // 숫자만 읽고 엔터키('\n')는 버퍼에 남음
cin.ignore();    // 버퍼에 남은 '\n' 제거
getline(...)     // 제거하지 않으면 getline이 '\n'을 읽고 바로 종료됨
```

- `cin >>` 는 엔터키를 버퍼에 남기기 때문에, 이후 `getline()` 사용 전에 반드시 `cin.ignore()`로 버퍼를 비워야 한다.
- `getline()` 은 공백을 포함한 한 줄 전체를 읽기 때문에 이름, 주소처럼 띄어쓰기가 있는 입력에 적합하다.

---

## 실행 결과
<img width="804" height="246" alt="스크린샷 2026-03-12 164636" src="https://github.com/user-attachments/assets/b3148207-2ccf-44ff-bce8-fe561205b9f9" />



