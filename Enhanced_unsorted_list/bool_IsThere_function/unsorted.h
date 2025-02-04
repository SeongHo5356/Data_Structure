#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 

class UnsortedType 
{
public:
  UnsortedType();
  // Constructor
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int LengthIs() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  void RetrieveItem(ItemType& item, bool& found);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and item is a copy of
  //       someItem; otherwise found = false and item is unchanged.
  //       List is unchanged.

  void InsertItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType& item);
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  bool IsThere(ItemType& item);
  // Functions: Check whether there is a item in the list
  // Pre:	List has been initialized

  int ItemInList(ItemType& item, UnsortedType CaseList);
  // Functions: Check whether there is a item in the CaseList
  // Pre: List has been initialized
  // Post : currentPos is updated to last postion
  //		if find item in CaseList, currentPos is updated to position of item in CaseList
 
  void SplitLists(UnsortedType list, ItemType item, UnsortedType& list1, UnsortedType& list2);
  // Functions: Divides list into two lists according to the key of item 
  // Pre: List has been initialized and is not empty
  // Post: List1 contains all the items of list whose keys are less than or equal to item's key		
  //	   List2 contains all the items of list whose keys are greater than item's key

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};
