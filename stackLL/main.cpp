#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem_A(StackType<ItemType>& stack, ItemType oldItem, ItemType newItem);


int main() {

	StackType<ItemType> stack1;
	for (int i = 0; i < 5; i++) {
		stack1.Push(i);
	}

	StackType<ItemType> stack2;
	stack2.Copy(stack1);

	int item = 0;
	while (!stack2.IsEmpty()) {
		stack2.Pop(item);
		cout << item << endl;
	}

	return 0;
}

// client Model

void ReplaceItem_A(StackType<ItemType>& stack, ItemType oldItem, ItemType newItem) {
    StackType<ItemType> temp_stack;//����� ����
    ItemType temp_item; // top�� �޴� ������
    int item;

    while (!stack.IsEmpty()) {
        //top. pop ���
        temp_item = stack.Top();

        // top�� ����� olditem �� ���ų� �ٸ� ���, temp_stack�� �ִ� �κ�
        if (temp_item == oldItem) {
            stack.Pop(item);
            temp_stack.Push(newItem);
        }
        else {
           stack.Push(temp_item);
           temp_stack.Pop(item);
        }
    }
    while (!temp_stack.IsEmpty()) {
        temp_item = temp_stack.Top();
        stack.Push(temp_item);
        temp_stack.Pop(item);
    }

}

