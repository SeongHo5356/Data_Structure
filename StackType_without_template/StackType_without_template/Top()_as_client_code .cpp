#include <iostream>
#include "StackType.h"

using namespace std;

int main() {



	return 0;
}
ItemType Top(StackType stack) {
	
	if (stack.IsEmpty())
		throw EmptyStack();

	else {
		int item = stack.Pop();
		stack.Push(item);
	}

	return item;
}

ItemType StackType::Top() {
	if (IsEmpty())
		throw EmptyStack();
	else
		return items[top];

}

bool Identical(StackType stack1, StackType stack2) {
	StackType stack1_copy;
	StackType stack2_copy;

	while (!stack1.IsEmpty() || stack2.IsEmpty()) {
		int item1 = stack1.Top();
		int item2 = stack2.Top();
		stack1_copy.Push(item1);
		stack2_copy.Push(item2);
		stack1.Pop();
		stack2.Pop();

		if (item1 != item2) {

			while (!stack1_copy.IsEmpty()) {
				int item = stack1_copy.Top();
				stack1.Push(item);
				stack1_copy.Pop();

			}

			while (!stack2_copy.IsEmpty()) {
				int item = stack2_copy.Top();
				stack1.Push(item);
				stack2_copy.Pop();
			}

			return false; 
		}
	}
	if (stack1.IsEmpty() && stack2.IsEmpty()) {
		while (!stack1_copy.IsEmpty()) {
			int item = stack1_copy.Top();
			stack1.Push(item);
			stack1_copy.Pop();
		}

		while (!stack2_copy.IsEmpty()) {
			int item = stack2_copy.Top();
			stack1.Push(item);
			stack1_copy.Pop();
		}

		return true;
	}
	else {
		while (!stack1_copy.IsEmpty()) {
			int item = stack1_copy.Top();
			stack1.Push(item);
			stack1_copy.Pop();
		}

		while (!stack2_copy.IsEmpty()) {
			int item = stack2_copy.Top();
			stack1.Push(item);
			stack2.Pop();
		}
	}

		return false;
}



