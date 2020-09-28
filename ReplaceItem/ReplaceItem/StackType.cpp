// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

void StackType::ReplaceItem(int olditem, int newItem) 
{
    for (int i = top; i > -1 ; i--)
        if (items[i] == olditem) {
            items[i] = newItem;
        }

/*    StackType stack_C;

    while (!IsEmpty()) {
        int item = Top();
        if (item == olditem) {
            stack_C.Push(newItem);
        }
        else {
            stack_C.Push(item);
        }
        Pop();
    }

    while (!stack_C.IsEmpty()) {
        int item = stack_C.Top();
        this->Push(item);
        stack_C.Pop();
    }
*/


}




