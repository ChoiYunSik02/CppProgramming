//// **********************************************
//// 제 목 : ch04-3 실습과제 5번
//// 날 짜 : 2026년 04월 7일
//// 작성자 : 2101091 최윤식
//// **********************************************

#include <iostream>
using namespace std;

class Sphere {
    int radius;
public:
    void setRadius(int r) {
        radius = r;
    }

    double getVolume() {
        return (4.0 / 3.0) * 3.14 * radius * radius * radius;
    }
};

int main() {
    int n;
    cout << "생성하고자 하는 구의 개수: ";
    cin >> n;

    Sphere* arr = new Sphere[n];

    for (int i = 0; i < n; i++) {
        int r;
        cout << "구" << i + 1 << "의 반지름: ";
        cin >> r;
        arr[i].setRadius(r);
    }

    for (int i = 0; i < n; i++) {
        cout << "구" << i + 1 << "의 부피 " << arr[i].getVolume() << "\n";
    }

    delete[] arr;
    return 0;
}
