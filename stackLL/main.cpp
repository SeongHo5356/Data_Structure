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
    StackType<ItemType> temp_stack;//백업용 스택
    ItemType temp_item; // top을 받는 아이템
    int item;

    while (!stack.IsEmpty()) {
        //top. pop 사용
        temp_item = stack.Top();

        // top의 결과가 olditem 과 같거나 다를 경우, temp_stack에 넣는 부분
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

