#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	UnsortedType<int> list;
	NodeType<int>* temp;

	list.InsertItem(3);
	list.InsertItem(2);
	list.InsertItem(4);
	list.InsertItem(1);
	list.InsertItem(5);
	
	temp = list.getListData();


	list.Sort(temp);
	
	int item;

	for (int i = 0; i < 5; i++) {
		list.GetNextItem(item);
		cout << item << endl;
	}

	return 0;
}