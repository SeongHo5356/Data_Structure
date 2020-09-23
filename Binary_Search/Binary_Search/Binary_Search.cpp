#include <iostream>

using namespace std;

int BinarySearch(int arry[], int sizeOfArray, int value) {
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch == true) {

		midPoint = (first + last) / 2;

		if (value > arry[midPoint]) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (value == arry[midPoint]) {
			return midPoint;
		}

		else if (value < arry[midPoint]) {
			last = midPoint - 1;
			moreToSearch = (first <= last);

		}
	}

	return -1;
}
int BinarySearch_A(int arry[], int sizeOfArray, int value)
//funtion : return index of the value in array 
//			if there isn't value in the array return the largest value among small or equal values
{
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch == true) {

		midPoint = (first + last) / 2;

		if (value > arry[midPoint]) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (value == arry[midPoint]) {
			break;
		}

		else if (value < arry[midPoint]) {
			last = midPoint - 1;
			moreToSearch = (first <= last);

		}
	}
	if (value == arry[midPoint]) {
		return value;
	}
	else {
		return arry[last];
	}



}
int BinarySearch_B(int ary[], int sizeOfArray, int value)
//funtion : return index of the value in array 
//			if there isn't value in the array return the smallest value among large or equal values

{
	int midPoint;
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);

	while (moreToSearch == true) {

		midPoint = (first + last) / 2;

		if (value > ary[midPoint]) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else if (value == ary[midPoint]) {
			break;
		}

		else if (value < ary[midPoint]) {
			last = midPoint - 1;
			moreToSearch = (first <= last);

		}
	}
	if (value == ary[midPoint]) {
		return value;
	}
	else {
		return ary[first];
	}


}


int main() {

	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl; // -1 府畔
	result = BinarySearch(list, 10, 7);
	cout << result << endl; // 6 府畔
	result = BinarySearch_A(list, 10, 11);
	cout << result << endl; // 10 府畔
	result = BinarySearch_B(list, 10, 0);
	cout << result << endl; // 1 府畔

	return 0;
}