#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& st, int olditem, int newitem);

int main() {

	StackType stack; 
	
	stack.Push(3);
	stack.Push(5);
	stack.Push(7);
	stack.Push(3);
	stack.Push(8);
	stack.Push(9);
	stack.Push(3);
	stack.Push(8);

	cout << "current stack items" << endl;
	cout << "8, 3, 9, 8, 3, 7, 5, 3 " << endl;
	cout << "Change 3 in the stack item list to 5" << endl;

	stack.ReplaceItem(3, 5);
//	ReplaceItem(stack, 3, 5);

	while (!stack.IsEmpty()) {

		int item = stack.Top();
		stack.Pop();

		cout << "Item : " << item << endl;

	}


	return 0;
}

void ReplaceItem(StackType& st, int olditem, int newitem)
// 새로운 사본 stackType을 생성하여 olditem 과 일치하는 값을 newitem으로 사본 stackType 에 저장한다.
// 다음 임시로 생성했던 stack에서 아이템을 top,pop을 통해 꺼내면서 st에 다시 집어넣음 
{
	StackType stack_C;
	while (!st.IsEmpty()) {

		int item = st.Top();
		st.Pop();
		if (item == olditem) {
			stack_C.Push(newitem);
		}
		else {
			stack_C.Push(item);
		}

	}

	while (!stack_C.IsEmpty()) {
		int item = stack_C.Top();
		
		stack_C.Pop();
		st.Push(item);
	}

}
