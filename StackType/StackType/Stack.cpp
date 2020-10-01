#include <iostream>
#include "StackTType.h"

using namespace std;


int main() {

	StackType<int> stack;
	StackType<int> stack_B;
	StackType<int> stack_C;
	StackType<int> stack_D;

	for (int i = 1; i <= 6; i++) {
		stack.Push(i); //���ÿ� 1,2,3,4,5,6�� �ִ´�.
	}
/*
	while (!stack.IsEmpty()) { // ���ÿ� ���Ұ� ���� ������ �ݺ��Ѵ�.
		int result = stack.Top(); // ���� �ֱٿ� ���� ���� �����´�
		stack.Pop(); // ���� �ֱٿ� ���� �������� �����Ѵ�.
		cout << result << endl;
	}
*/
	while (!stack.IsEmpty()) // ���ÿ� ���Ұ� ���� ������
	{
		int result = stack.Top(); 
		stack_C.Push(result); // �ӽ÷� ������ ����Ʈ�� �ݴ� ������ ������
		stack.Pop();
	}

	while (!stack_C.IsEmpty())
	{
		int result = stack_C.Top();
		stack_B.Push(result); // ���� ����Ʈ�� ������ ����Ʈ
		stack.Push(result); // ���� ����Ʈ ����
		stack_C.Pop();
	}



	return 0;
}

