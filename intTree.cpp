#include <algorithm>
#include <iostream>

#include "intTree.h"


////////////////////////////////////////
// Constructor
///////////////////////////////////////
IntTree::IntTree() : root(nullptr) {} 

////////////////////////////////////////
// Destructor
///////////////////////////////////////
IntTree::~IntTree() 
{
    int numFreed = DestroySubTree(root);
	std::cout << "Freed " << numFreed << " tree node(s)...\n";
}

////////////////////////////////////////
// Delete function
///////////////////////////////////////
int IntTree::DestroySubTree(TreeNode* nodePtr)
{
	int numDeleted = 0;

    if (nodePtr)
    {
        if (nodePtr->left)
        {
            numDeleted += DestroySubTree(nodePtr->left);
        }
        if (nodePtr->right)
        {
            numDeleted += DestroySubTree(nodePtr->right);
        }

        delete nodePtr;
		numDeleted++;
    }

	return numDeleted;
}

////////////////////////////////////////
// Public Insert Function
///////////////////////////////////////
void IntTree::InsertNode(int num) 
{
    TreeNode* newNode = new TreeNode(num);

    Insert(root, newNode);
}

////////////////////////////////////////
// RECURSIVE Private Insert Function
///////////////////////////////////////
void IntTree::Insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
    if (nodePtr == nullptr)
    {
        nodePtr = newNode; // create new node
    }
    else if (newNode->data < nodePtr->data)
    {
        Insert(nodePtr->left, newNode); // insert into left subtree
    }
    else
    {
        Insert(nodePtr->right, newNode); // insert into right subtree
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
    if (nodePtr)
    {
        InOrder(nodePtr->left); // traverse left subtree
        std::cout << nodePtr->data << " "; // print data
        InOrder(nodePtr->right); // traverse right subtree
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
    if (nullptr == nodePtr)
    {
        return 0;
    }

    if (nullptr == nodePtr->left && nullptr == nodePtr->right) // leaf node
    {
        return 1;
    }

    return GetLeafCount(nodePtr->left) + GetLeafCount(nodePtr->right);
}

////////////////////////////////////////
// Public Height Function
///////////////////////////////////////
int IntTree::DisplayTreeHeight()
{
    return GetTreeHeight(root);
}

////////////////////////////////////////
// RECURSIVE Private Height Function
///////////////////////////////////////
int IntTree::GetTreeHeight(TreeNode* nodePtr)
{
    if (nullptr == nodePtr)
    {
        return 0;
    }

    return 1 + std::max(GetTreeHeight(nodePtr->left),
            GetTreeHeight(nodePtr->right));
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
    if (nullptr == root)
    {
        return 0;
    }

    if (1 == level)
    {
        return 1;
    }

    return GetWidth(root->left, level-1) + GetWidth(root->right, level-1);
}

////////////////////////////////////////
// Private Max Width Function
///////////////////////////////////////
int IntTree::GetMaxWidth(TreeNode* root)
{
    int maxWidth = 0;
    int width = 0;
    int numLevels = GetTreeHeight(root);

    for (int i = 1; i <= numLevels; ++i)
    {
        width = GetWidth(root, i);

        if (width > maxWidth)
        {
            maxWidth = width;
        }
    }

    return maxWidth;
}
