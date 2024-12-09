#include <iostream>
#include "intTree.h"
#include <algorithm>
using namespace std;

////////////////////////////////////////
// Constructor
///////////////////////////////////////
IntTree::IntTree() : root(nullptr) {} 

////////////////////////////////////////
// Destructor
///////////////////////////////////////
IntTree::~IntTree() 
{
   DestroySubTree(root);
}

////////////////////////////////////////
// Delete function
///////////////////////////////////////
void IntTree::DestroySubTree(TreeNode* nodePtr)
{
   if (nodePtr) // Pointer is pointing at something
   {
      if (nodePtr->left) // Check left pointer
      {
         DestroySubTree(nodePtr->left); // Recursive call
      }
      if (nodePtr->right) // Check right pointer
      {
         DestroySubTree(nodePtr->right); // Recursive call
      }
      delete nodePtr;
   }
}

////////////////////////////////////////
// Public Insert Function
///////////////////////////////////////
void IntTree::InsertNode(int num) 
{
   TreeNode* newNode = nullptr; // Initialize new node

   newNode = new TreeNode(num);

   Insert(root, newNode);
}

////////////////////////////////////////
// RECURSIVE Private Insert Function
///////////////////////////////////////
void IntTree::Insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
   if (nodePtr == nullptr) // Tree is empty
   {
      nodePtr = newNode; // Create new node
   }
   else if (newNode->data < nodePtr->data) // If new node is less than current
   {
      Insert(nodePtr->left, newNode); // Go left uisng recursion
   }
   else // If new node is greater than current
   {
      Insert(nodePtr->right, newNode); // Go right using recursion
   }
}

////////////////////////////////////////
// Public Print Function
///////////////////////////////////////
void IntTree::DisplayInOrder() const
{
   InOrder(root);
}

////////////////////////////////////////
// RECURSIVE Private Print Function
///////////////////////////////////////
void IntTree::InOrder(TreeNode* nodePtr) const
{
   if (nodePtr) // Pointer is pointing at something
   {
      InOrder(nodePtr->left); // Go left using recursion
      cout << nodePtr->data << " "; // Print data
      InOrder(nodePtr->right); // Go right using recursion
   }
}

////////////////////////////////////////
// Public Leaf Count Function
///////////////////////////////////////
int IntTree::CountLeafNodes()
{
   return GetLeafCount(root);
}

////////////////////////////////////////
// RECURSIVE Private Leaf Count Function
///////////////////////////////////////
int IntTree::GetLeafCount(TreeNode* nodePtr)
{
   if (nodePtr == nullptr) // Tree is empty
   {
      return 0;
   }
   if (nodePtr->left == nullptr && nodePtr->right == nullptr) // Property of leaf nodes
   {
      return 1;
   }
   return GetLeafCount(nodePtr->left) + GetLeafCount(nodePtr->right); // Recursive call 
}

////////////////////////////////////////
// Public Height Function
///////////////////////////////////////
int IntTree::DisplayTreeHeight()
{
   return GetTreeHeight(root);
}

////////////////////////////////////////
// RECURSIVE Private Leaf Count Function
///////////////////////////////////////
int IntTree::GetTreeHeight(TreeNode* nodePtr)
{
   if (nodePtr == nullptr) // Tree is empty
   {
      return -1;
   }
   return 1 + max(GetTreeHeight(nodePtr->left), GetTreeHeight(nodePtr->right)); // Add one plus the max of left or right
}

////////////////////////////////////////
// Public Width Function
///////////////////////////////////////
int IntTree::DisplayMaxWidth()
{
   return GetMaxWidth(root);
}

////////////////////////////////////////
// RECURSIVE Private Width Function
///////////////////////////////////////
int IntTree::GetWidth(TreeNode* root, int level)
{
   if (root == nullptr) // Tree empty
   {
      return 0;
   }
   if (level == 1) // One node inserted
   {
      return 1;
   }
   return GetWidth(root->left, level - 1) + GetWidth(root->right, level - 1); // Recursive call traverse through tree
   
}

////////////////////////////////////////
// Private Max Width Function
///////////////////////////////////////
int IntTree::GetMaxWidth(TreeNode* root)
{
   int maxWidth = 0; // Variable initialization
   int width;
   int num_levels = GetTreeHeight(root) + 1; // Number of levels is one more than height
   int i;

   for (i = 0; i < num_levels; ++i) // Go through levels
   {
      width = GetWidth(root, i + 1); // Call Private Recursive function
      if (width > maxWidth) // Current width greater than current max
      {
         maxWidth = width; // Make max width new width
      }
   }
   return maxWidth;
}

