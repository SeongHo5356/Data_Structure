#include <iostream>
#include <cstdlib>
#include "QueType.h"

using namespace std;


int main() {

	QueType Que;
	cout << "���� ������ : " << endl;
	int i = 0;
	while (i < 10) {
		int item = rand() % 100;
		cout << item << '\t';
		Que.Enqueue(item);

		i++;
	}
	cout << endl;

	cout << endl << "���� ������ : " << endl;

	while (!Que.IsEmpty()) {
		int item;
		Que.Dequeue(item);
		cout << item << '\t';
	}


	return 0;
}