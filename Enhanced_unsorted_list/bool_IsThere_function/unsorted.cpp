// Implementation file for Unsorted.h

#include "unsorted.h"
UnsortedType::UnsortedType()
{
  length = 0;
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

bool UnsortedType::IsThere(ItemType& item) {
// Pre: List has been initialized

    while (currentPos != length) {
        
        if (item.ComparedTo(info[currentPos+1])== EQUAL) {
            return true;
        }
        currentPos++;
    }
    return false;
}

int UnsortedType::ItemInList(ItemType& item, UnsortedType CaseList) {
// pre: List has been initialized
// Post : currentPos is updated to last postion
//		if find item in CaseList, currentPos is updated to position of item in CaseList

 

    bool find = false;

    do {
        if (item.ComparedTo(info[currentPos + 1]) == EQUAL) {
            find = true;
            break;
        }
        else
            find = false;

        CaseList.currentPos++;
    } while (CaseList.currentPos != CaseList.length);

    return CaseList.currentPos;
}

void UnsortedType::SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2) {
// Pre: List has been initialized and is not empty
// Post: List1 contains all the items of list whose keys are less than or equal to item's key		
//	     List2 contains all the items of list whose keys are greater than item's key
    
    while (currentPos != list.length) {
        currentPos++;

        if (list.info[currentPos].ComparedTo(item) == GREATER) {
            list2.InsertItem(list.info[currentPos]);
        }
        else {
            list1.InsertItem(list.info[currentPos]);
        }
    }

}
