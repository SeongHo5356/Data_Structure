#include <iostream>

using namespace std;

float SqrRoot_recursion(float number, float approx, float tol) {
	if (fabs(approx * approx - number) <= tol) {
		return approx;
	}
	else {
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
	}
}

float SqrRoot_non_recursion(float number, float approx, float tol) {
	
	while(fabs(approx*approx - number) > tol){
		approx = ((approx * approx) + number) / (2 * approx);
	}
	return approx;
}

int main() {

	float number = 2;
	float approx = 1;
	float tol = 0.1;
	cout << "ºñÀç±Í Á¦°ö±Ù ÇÔ¼ö" << endl;
	cout << SqrRoot_non_recursion(2, 1, 0.1) << endl;
	cout << "Àç±Í Á¦°ö±Ù ÇÔ¼ö" << endl;
	cout << SqrRoot_recursion(2, 1, 0.1) << endl;

	return 0;
}