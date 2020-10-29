#include <iostream>

using namespace std;

int Fibonacci_recursive(int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
	}

}
int Fibonacci_non_recursive(int n) {
	int last = 0;
	int secondLast = 0;
	
	for (int i = 0; i < n+1; i++)
	{
		int val = last + secondLast;
		if (!val)
			last = 1;
		secondLast = last;
		last = val;
	}
	return last;
}

int main() {

	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;


	return 0;
}