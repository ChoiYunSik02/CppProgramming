# 실습과제 2 소스코드 설명 — MyMath 클래스

## 문제 요약

배열 데이터 중 **최대값**과 **최소값**을 구하는 함수를 포함하는 `MyMath` 클래스를 작성한다.  
함수는 `static` 멤버 함수로 선언하여 객체 생성 없이 `MyMath::GetMax(...)` 형태로 호출한다.

---

## 전체 구조

```
MyMath 클래스
├── static int GetMax(int arr[], int n)  ← 최대값 반환
└── static int GetMin(int arr[], int n)  ← 최소값 반환
```

---

## 클래스 선언 상세 설명

### static 멤버 함수로 선언하는 이유

```cpp
class MyMath {
public:
    static int GetMax(int arr[], int n) { ... }
    static int GetMin(int arr[], int n) { ... }
};
```

| 항목 | 설명 |
|------|------|
| `static` | 객체 생성 없이 `클래스명::함수명()` 형태로 호출 가능 |
| 전역 함수 대신 클래스 사용 | 관련 함수들을 하나의 클래스 안에 **캡슐화**하여 이름 충돌 방지 |
| 멤버 변수 없음 | 순수 유틸리티 함수이므로 인스턴스 멤버 변수가 필요 없음 |

---

## GetMax 함수 상세 설명

```cpp
static int GetMax(int arr[], int n) {
    int maxVal = arr[0];           // ① 첫 번째 원소를 최대값 초기값으로 설정
    for (int i = 1; i < n; i++) { // ② 인덱스 1부터 n-1까지 반복
        if (arr[i] > maxVal)       // ③ 현재 원소 > 현재 최대값이면
            maxVal = arr[i];       // ④ 최대값 갱신
    }
    return maxVal;                 // ⑤ 최종 최대값 반환
}
```

**동작 추적** (배열 `{20, 30, -5, 2, -30}`):

| i | arr[i] | maxVal | 갱신? |
|---|--------|--------|-------|
| 초기 | — | 20 | — |
| 1 | 30 | 30 | ✅ |
| 2 | -5 | 30 | ❌ |
| 3 | 2 | 30 | ❌ |
| 4 | -30 | 30 | ❌ |

최종 반환: **30**

---

## GetMin 함수 상세 설명

```cpp
static int GetMin(int arr[], int n) {
    int minVal = arr[0];           // ① 첫 번째 원소를 최소값 초기값으로 설정
    for (int i = 1; i < n; i++) { // ② 인덱스 1부터 n-1까지 반복
        if (arr[i] < minVal)       // ③ 현재 원소 < 현재 최소값이면
            minVal = arr[i];       // ④ 최소값 갱신
    }
    return minVal;                 // ⑤ 최종 최소값 반환
}
```

**동작 추적** (배열 `{20, 30, -5, 2, -30}`):

| i | arr[i] | minVal | 갱신? |
|---|--------|--------|-------|
| 초기 | — | 20 | — |
| 1 | 30 | 20 | ❌ |
| 2 | -5 | -5 | ✅ |
| 3 | 2 | -5 | ❌ |
| 4 | -30 | -30 | ✅ |

최종 반환: **-30**

---

## main 함수 설명

```cpp
int x[5] = { 20, 30, -5, 2, -30 };
// 정수 배열 5개 원소 초기화

cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;
// MyMath 객체를 생성하지 않고 클래스명으로 직접 호출
// x배열의 5개 원소 중 최대값 → 30 출력

cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;
// x배열의 5개 원소 중 최소값 → -30 출력
```

---

## 실행 결과
<img width="818" height="156" alt="image" src="https://github.com/user-attachments/assets/fa05f137-cb9c-424f-a6c7-e6969a7bc602" />


---

## 핵심 포인트 정리

> ✅ **static 멤버 함수**는 객체 없이 `클래스명::함수명()` 으로 호출  
> ✅ 전역 함수를 static으로 클래스 안에 캡슐화 → 이름 충돌 방지  
> ✅ `GetMax`, `GetMin` 모두 첫 원소를 초기값으로 설정하고 선형 탐색
