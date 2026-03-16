#include <iostream>
using namespace std;

class Triangle {
public:
	int width;
	int height;
	int getArea();
};

int Triangle::getArea() {
	return 0.5 * width * height;
}

int main() {
	Triangle tra;
	tra.width = 7;
	tra.height = 8;
	cout << "삼각형의 면적은 " << tra.getArea() << endl;
}
