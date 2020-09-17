#include <iostream>
#include <stdlib.h>
#include "sorted.h"
#include "ItemType.h"

using namespace std;

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	// 리스트의 current position을 초기화한다.
	// list1 과 list2 길이를 Lengthis()함수를 통해 얻는다.
	// 정렬 리스트이므로 InsertITem(...)함수에 정렬하는 기능이 있다. 
	// 따라서 list1 길이만큼 반복하여 GetNextItem(...)을 받아 result에 넣는다.
	// list2 역시 길이만큼 루프를 돌며 GetNextItem(...)로 Item을 얻고, result 에 넣는다.

	list1.ResetList();
	list2.ResetList();
	int length1 = list1.LengthIs();
	int length2 = list2.LengthIs();
	for (int i = 0; i < length1; i++) {
		result.InsertItem(list1.GetNextItem());
	}
	for (int k = 0; k < length2; k++) {
		result.InsertItem(list2.GetNextItem());
	}
}


int main() 
{
	SortedType s_list1, s_list2, s_list3; // 리스트 선언
	
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9;// 필요한 만큼 선언 

	item1.Initialize(rand() % 10);	 // item을 필요한 만큼 초기화
	item2.Initialize(rand() % 10);
	item3.Initialize(rand() % 10);
	item4.Initialize(rand() % 10);
	item5.Initialize(rand() % 10);
	item6.Initialize(rand() % 10);
	item7.Initialize(rand() % 10);
	item8.Initialize(rand() % 10);
	item9.Initialize(rand() % 10);

	s_list1.InsertItem(item1);	// 리스트에 값을 넣는다 
	s_list1.InsertItem(item2);
	s_list1.InsertItem(item3);
	s_list1.InsertItem(item4);
	s_list1.InsertItem(item5);
	s_list2.InsertItem(item6);
	s_list2.InsertItem(item7);
	s_list2.InsertItem(item8);
	s_list2.InsertItem(item9);

	MergeList(s_list1, s_list2, s_list3);

	return 0;

}