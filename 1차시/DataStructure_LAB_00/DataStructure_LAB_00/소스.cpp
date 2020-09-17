#include <iostream>
#include <string>

using namespace std;

class Point {
private:
	int x; int y;

public:
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void setXY(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};