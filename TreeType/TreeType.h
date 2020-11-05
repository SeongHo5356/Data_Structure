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
  // ��� �� �ּڰ��� ã��
  TreeNode* PtrToSuccessor_recursive(TreeNode*& tree); // �Ķ���� Ÿ��: (1) TreeNode* or (2) TreeNode*&
  // Nonrecursive version:
  TreeNode* PtrToSuccessor_non_recursive(TreeNode*& tree); // �Ķ���� Ÿ��: (1) TreeNode* or (2) TreeNode*&

  // ���� ����ڸ� ã�Ƽ� tree �ڸ��� ������� 
  void DeleteNode(TreeNode*& tree); //�̹� ������ �ҽ��� �����ϼ���.


  // binary search tree ���� �˻�����
  bool IsBST();// Ŭ������ IsBST �Լ��� �����ϼ���.

  //����� �¿찡 NULL�� ��带 ã�� ������ �ݺ��ϸ鼭, ã���� 1�� ��ȯ�Ͽ� �����
  //������ ī��Ʈ �Ѵ�.
  int LeafCount();

  // child �� �ϳ��� parent �� ������ Ž��
  int SingleParentCount();
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

