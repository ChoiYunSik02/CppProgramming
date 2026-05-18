// **********************************************
// 제 목 : C++ ch06-3 실습과제 2 - MyMath 클래스
// 날 짜 : 2026년 05월 18일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

class MyMath {
public:
    // 배열 arr의 n개 원소 중 최대값 반환 (static 멤버 함수)
    static int GetMax(int arr[], int n) {
        int maxVal = arr[0];           // 첫 번째 원소를 최대값 후보로 초기화
        for (int i = 1; i < n; i++) { // 두 번째 원소부터 순차 비교
            if (arr[i] > maxVal)       // 현재 원소가 최대값보다 크면
                maxVal = arr[i];       // 최대값 갱신
        }
        return maxVal;                 // 최종 최대값 반환
    }

    // 배열 arr의 n개 원소 중 최소값 반환 (static 멤버 함수)
    static int GetMin(int arr[], int n) {
        int minVal = arr[0];           // 첫 번째 원소를 최소값 후보로 초기화
        for (int i = 1; i < n; i++) { // 두 번째 원소부터 순차 비교
            if (arr[i] < minVal)       // 현재 원소가 최소값보다 작으면
                minVal = arr[i];       // 최소값 갱신
        }
        return minVal;                 // 최종 최소값 반환
    }
};

int main() {
    int x[5] = { 20, 30, -5, 2, -30 };  // 정수 배열 초기화

    // 클래스명::함수명 으로 static 멤버 함수 호출 (객체 생성 불필요)
    cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;  // 출력: 30
    cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;  // 출력: -30

    return 0;
}
