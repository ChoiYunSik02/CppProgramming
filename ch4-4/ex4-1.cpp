// **********************************************
// 제 목 : C++ ch04 실습문제4 - 2번 (동적 배열 최솟값/최댓값)
// 날 짜 : 2026년 04월 13일
// 작성자 : 2101091 최윤식
// **********************************************

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "구입할 물품의 개수>>";
    cin >> n;

    int* prices = new int[n];

    cout << "물품 " << n << "개의 가격 입력>>";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int minPrice = prices[0];
    int maxPrice = prices[0];
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        if (prices[i] > maxPrice) maxPrice = prices[i];
    }

    cout << "제일 싼 가격은 " << minPrice << endl;
    cout << "제일 비싼 가격은 " << maxPrice << endl;

    delete[] prices;
    return 0;
}
