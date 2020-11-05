#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const; 
  void RetrieveItem(ItemType& item, bool& found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  void GetNextItem (ItemType& item, OrderType order, 
       bool& finished);
  void Print(std::ofstream& outFile) const;

  
  // Recursive version:
  // 노드 내 최솟값을 찾음
  TreeNode* PtrToSuccessor_recursive(TreeNode*& tree); // 파라메터 타입: (1) TreeNode* or (2) TreeNode*&
  // Nonrecursive version:
  TreeNode* PtrToSuccessor_non_recursive(TreeNode*& tree); // 파라메터 타입: (1) TreeNode* or (2) TreeNode*&

  // 다음 계승자를 찾아서 tree 자리에 집어넣음 
  void DeleteNode(TreeNode*& tree); //이미 구현된 소스에 수정하세요.


  // binary search tree 인지 검사해줌
  bool IsBST();// 클래스에 IsBST 함수를 선언하세요.

  //노드의 좌우가 NULL인 노드를 찾을 때까지 반복하면서, 찾으면 1을 반환하여 노드의
  //개수를 카운트 한다.
  int LeafCount();

  // child 가 하나인 parent 의 개수를 탐색
  int SingleParentCount();
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

