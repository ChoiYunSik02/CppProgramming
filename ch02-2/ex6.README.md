# 2장 실습문제 10번 — 영문 텍스트 단어 개수 출력

---

## 코드 설명

| 라인 | 설명 |
|------|------|
| `#include <sstream>` | `istringstream` 사용을 위한 헤더 포함 |
| `char buf[256];` | 한 줄 입력을 저장할 C-스타일 문자 배열 |
| `while (true)` | exit 입력 전까지 무한 반복 |
| `cin.getline(buf, 256)` | 공백 포함 한 줄 전체를 입력받아 buf에 저장 |
| `string(buf) == "exit"` | 입력값이 "exit"이면 반복문 탈출 |
| `istringstream iss(buf)` | 문자열 buf를 스트림으로 변환하여 단어 추출 준비 |
| `while (iss >> word)` | 공백을 기준으로 단어를 하나씩 추출하며 반복 |
| `count++` | 단어 하나 추출될 때마다 카운트 증가 |

### 단어 카운팅 동작 방식

```
입력: "I love C++ very much."
           ↓ istringstream
word = "I"       → count = 1
word = "love"    → count = 2
word = "C++"     → count = 3
word = "very"    → count = 4
word = "much."   → count = 5
```

- 빈 줄 입력 시 `iss >> word`가 한 번도 실행되지 않아 count = 0

---

## 실행 결과

<img width="812" height="288" alt="스크린샷 2026-03-12 170838" src="https://github.com/user-attachments/assets/f6c91e4f-6c8b-4131-9948-6b27bec6fec7" />

