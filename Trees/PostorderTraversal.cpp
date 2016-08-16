/*
Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [3,2,1].

Using recursion is not allowed.

https://www.interviewbit.com/problems/postorder-traversal/
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
void PostOrder(TreeNode* root, vector<int>& res)
{
    if (!root)
        return;
    PostOrder(root->left, res);
    PostOrder(root->right, res);
    res.emplace_back(root->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    PostOrder(A, res);
    return res;
}
