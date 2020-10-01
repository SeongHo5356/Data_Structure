#include <iostream>
#include "StackTType.h"

using namespace std;


int main() {

	StackType<int> stack;
	StackType<int> stack_B;
	StackType<int> stack_C;
	StackType<int> stack_D;

	for (int i = 1; i <= 6; i++) {
		stack.Push(i); //스택에 1,2,3,4,5,6을 넣는다.
	}
/*
	while (!stack.IsEmpty()) { // 스택에 원소가 없을 때까지 반복한다.
		int result = stack.Top(); // 가장 최근에 넣은 값을 가져온다
		stack.Pop(); // 가장 최근에 넣은 아이템을 제거한다.
		cout << result << endl;
	}
*/
	while (!stack.IsEmpty()) // 스택에 원소가 없을 떄가지
	{
		int result = stack.Top(); 
		stack_C.Push(result); // 임시로 저장할 리스트에 반대 순서로 저장함
		stack.Pop();
	}

	while (!stack_C.IsEmpty())
	{
		int result = stack_C.Top();
		stack_B.Push(result); // 기존 리스트를 복사할 리스트
		stack.Push(result); // 기존 리스트 복구
		stack_C.Pop();
	}



	return 0;
}

