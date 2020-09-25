#include <iostream>

using namespace std;


class FullStack
	// Exception class thrown by Push when stack is full.
{};



class DoubleStack {
public:

	DoubleStack(int _Top, int _Bot)
	{
		Top = _Top;
		Bottom = _Bot;
	}

	DoubleStack()
	{
		Top = 199;
		Bottom = 0;
	}

	int getTop() const
	{
		return Top;
	}

	int getBottom() const
	{
		return Bottom;
	}

	void setTop(int _Top)
	{
		Top = _Top;
	}

	void setBottom(int _Bot)
	{
		Bottom = _Bot;
	}

	bool DecideSide(int item) const
	{ // 1000보다 작거나 같은 수일 시 false return, 1000보다 큰 수일 시 true return
		if (item <= 1000) {
			return false;
		}
		else
			return true;
	}
	void push(int item) {
		if (IsFull() == true)
			throw FullStack();
		else {
			if (DecideSide(item) == false) {
				pushFront(item);
			}

			else {
				pushBack(item);
			}
		}

	}

	void pushFront(int item) 
	{

		items[Bottom] = item;
		Bottom++;
		
	}

	void pushBack(int item)
	{
		items[Top] = item;
		Top--;
		
	}

	bool IsFull() const
	{
		if (Top + 1 == Bottom)
			return true;
		else
			return false;
	}

	bool IsThere(int item) const
	{
		for (int i = 0; i <= Bottom; i++) {
			if (items[i] == item)
				return true;
		}

		for (int i = 199; i >= Top; i--) {
			if (items[i] == item)
				return true;
		}

		return false;
	}

	bool IsEmpty() const 
	{
		if (Bottom == 0 && Top == 200)
			return true;
		else
			return false;
	}

	void PrintBot() const 
	{
		for (int i = 0; i < Bottom; i++) {
			cout << items[i] << '\t';
		}
		cout << endl;
	}

	void PrintTop() const 
	{
		for (int i = 199; i > Top; i--) {
			cout << items[i] << '\t';
		}
		cout << endl;
	}
	void Print() const 
	{
		cout << "Bottom Stack" << endl;
		PrintBot();
		cout << "Top Stack" << endl;
		PrintTop();
		cout << endl;
	}


private:
	int Top ; // 1000을 넘는 변수를 저장하는 스택의 flag
	int Bottom ; // 1000보다 작은 변수를 저장하는 스택의 flag
	int items[200];
};

int main() {

	DoubleStack stack;

	for (int i = 1; i <= 5; i++) {
		stack.push(i);
		stack.Print();
	}
	for (int i = 2000; i >= 1996; i--) {
		stack.push(i);
		stack.Print();
	}


	return 0;
}