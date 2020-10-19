#include <iostream>

using namespace std;

int main() {
	int value;
	value = 500;
	char* charPtr;
	char string[10] = "GOOD luck";
	charPtr = string;

	cout << &value << endl;
	cout << value << endl;;
	cout << &charPtr<<endl;
	cout << charPtr << endl;
	cout << *charPtr << endl;
	cout << &string[2] << endl;

	return 0;
}