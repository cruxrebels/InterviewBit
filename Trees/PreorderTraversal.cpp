/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

https://www.interviewbit.com/problems/preorder-traversal/
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
void PreOrder(TreeNode* root, vector<int>& res)
{
    if (!root)
        return;
    res.emplace_back(root->val);
    PreOrder(root->left, res);
    PreOrder(root->right, res);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    PreOrder(A, res);
    return res;
}
