#ifndef INTTREE_H_
#define INTTREE_H_

class IntTree
{
	public:
		IntTree();
		~IntTree();

		void InsertNode(int);
		void DisplayInOrder() const;
		int CountLeafNodes();
		int DisplayTreeHeight();
		int DisplayMaxWidth();

	private:
		struct TreeNode
		{
			int data;
			TreeNode* left;
			TreeNode* right;
			TreeNode(int d) : data(d), left(nullptr), right(nullptr) {};
		};

		TreeNode* root = nullptr;

		void Insert(TreeNode*&, TreeNode*&);
		void DestroySubTree(TreeNode*);
		void InOrder(TreeNode*) const;
		int GetLeafCount(TreeNode*);
		int GetTreeHeight(TreeNode*);
		int GetWidth(TreeNode*, int);
		int GetMaxWidth(TreeNode*);
};

#endif // TREE_H_
