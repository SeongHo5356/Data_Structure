#include <iostream>

using namespace std;

int NumPaths(int row, int col, int n) {
	if (row == n || col == n) {
		return 1;
	}
	else {
		return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
	}
}

int mat[50][50];
int NumPaths_revised(int row, int col, int n) {
	if (mat[row][col] == -1) {
		if (row == 1 || col == 1) {
			mat[row][col] = 1;
		}
		else {
			mat[row][col] = NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
		}
	}
	return mat[n][n];
}

int main() {

	for (int i = 0; i < 50; i++) {
		for (int k = 0; k < 50; k++) {
			mat[i][k] = -1;
		}
	}

	cout << NumPaths(1,1,5) << endl;
	cout << NumPaths_revised(1, 1, 5) << endl;

	return 0;
}