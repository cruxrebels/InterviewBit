/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Recursive solution - Uses extra auxiliary space in stack for recursive calls.
/*void fillPreorder(vector<TreeNode*>& preOrder, TreeNode* root)
{
    if (!root)
        return;
    preOrder.emplace_back(root);
    fillPreorder(preOrder, root->left);
    fillPreorder(preOrder, root->right);
}
TreeNode* Solution::flatten(TreeNode* A) {
    if (!A)
        return A;
    vector<TreeNode*> preOrder;
    fillPreorder(preOrder, A);
    TreeNode* root = A;
    for (auto i = 1; i<preOrder.size(); ++i)
    {
        A->left = NULL;
        A->right = preOrder[i];
        A = A->right;
    }
    A->left = NULL;
    return root;
}*/

// Iterative solution - Solves inplace without using extra auxiliary space for recursion.
TreeNode* Solution::flatten(TreeNode* A) {
    if (!A)
        return A;
    TreeNode* root = A;
    
    while (A)
    {
        if (A->left)
        {
            TreeNode* rightSubTree = A->left;
            while (rightSubTree->right)
                rightSubTree = rightSubTree->right;
            rightSubTree->right = A->right;
            A->right = A->left;
            A->left = NULL;
        }
        A = A->right;
    }
    return root;
}
