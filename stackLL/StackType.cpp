// Implementation file for StackType.h

#include <cstddef>
#include <new>
#include "StackType.h"
void StackType<ItemType>::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    NodeType* location;
    location = new NodeType;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
  }
}
void StackType<ItemType>::Pop(int& item)
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    item = tempPtr->info;
    delete tempPtr;
  }
}
ItemType StackType<ItemType>::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr->info;  
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return (topPtr == NULL);
}
template <class ItemType>
bool StackType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc)
  {
    return true;
  }
}

StackType<ItemType>::~StackType()
// Post: stack is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

StackType<ItemType>::StackType()	// Class constructor.
{
    topPtr = NULL;
}
StackType<ItemType>::StackType(const StackType<ItemType>& anotherStack) {
    NodeType* ptr1;
    NodeType* ptr2;
    if (anotherStack.topPtr == NULL)
        topPtr = NULL;
    else {
        topPtr = new NodeType;
        topPtr->info = anotherStack.topPtr->info;
        ptr1 = anotherStack.topPtr->next;
        ptr2 = topPtr;
        while (ptr1 != NULL) {
            ptr2->next = new NodeType;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
    }
}



//Member function
void StackType<ItemType>::ReplaceItem_B(ItemType oldItem, ItemType newItem) {
    //함수 설명 : 링크 구조로 연결되어 있는 노드들을 top에서부터 시작하여 하나씩 검사하여
    //            new item 으로 변화시켜준다

    NodeType* location = topPtr; //현재 노드를 가리키기 위한 포인터 선언 및 초기화
    while (location != NULL) {
        if (location->info == oldItem) {
            location->info = newItem;
            location = location->next;
        }
        else {
            location = location->next;
        }

    }
    delete location;
}

void StackType<ItemType>::Copy(StackType& anotherStack) {
    NodeType* ptr1;
    NodeType* ptr2;
    if (anotherStack.topPtr == NULL) {
        topPtr = NULL;
    }   
    else { //allocate memory for first node
        topPtr = new NodeType;
        topPtr->info = anotherStack.topPtr->info;
        ptr2 = topPtr;
        ptr1 = anotherStack.topPtr->next;
        while (ptr1 != NULL) {                  //deep copy other nodes 
            ptr2->next = new NodeType;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
    }
}