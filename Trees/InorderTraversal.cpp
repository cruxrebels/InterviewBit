/*
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

https://www.interviewbit.com/problems/inorder-traversal/
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
 
 // Method 1 - Using recursion
 /*void Inorder(TreeNode* root, vector<int>& res)
 {
    if (!root)
        return;
    Inorder(root->left, res);
    res.emplace_back(root->val);
    Inorder(root->right, res);
 }
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    Inorder(A, res);
    return res;
}*/

// Method 2 - Without using recursion
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    TreeNode* pCurrent = A;
    stack<TreeNode* > stack;
    
    while (!stack.empty() || pCurrent)
    {
        if (pCurrent)
        {
            stack.push(pCurrent);
            pCurrent = pCurrent->left;
        }
        else
        {
            TreeNode* pNode = stack.top();
            res.push_back(pNode->val);
            stack.pop();
            pCurrent = pNode->right;
        }
    }
    return res;
}
