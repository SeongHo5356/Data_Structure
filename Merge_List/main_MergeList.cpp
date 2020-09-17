#include <iostream>
#include <stdlib.h>
#include "sorted.h"
#include "ItemType.h"

using namespace std;

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	// ����Ʈ�� current position�� �ʱ�ȭ�Ѵ�.
	// list1 �� list2 ���̸� Lengthis()�Լ��� ���� ��´�.
	// ���� ����Ʈ�̹Ƿ� InsertITem(...)�Լ��� �����ϴ� ����� �ִ�. 
	// ���� list1 ���̸�ŭ �ݺ��Ͽ� GetNextItem(...)�� �޾� result�� �ִ´�.
	// list2 ���� ���̸�ŭ ������ ���� GetNextItem(...)�� Item�� ���, result �� �ִ´�.

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
	SortedType s_list1, s_list2, s_list3; // ����Ʈ ����
	
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9;// �ʿ��� ��ŭ ���� 

	item1.Initialize(rand() % 10);	 // item�� �ʿ��� ��ŭ �ʱ�ȭ
	item2.Initialize(rand() % 10);
	item3.Initialize(rand() % 10);
	item4.Initialize(rand() % 10);
	item5.Initialize(rand() % 10);
	item6.Initialize(rand() % 10);
	item7.Initialize(rand() % 10);
	item8.Initialize(rand() % 10);
	item9.Initialize(rand() % 10);

	s_list1.InsertItem(item1);	// ����Ʈ�� ���� �ִ´� 
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