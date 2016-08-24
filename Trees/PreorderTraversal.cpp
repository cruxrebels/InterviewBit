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

// Method 1 - Using recursion (Space complexity is more)
/*void PreOrder(TreeNode* root, vector<int>& res)
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
}*/

// Method 2 - Without using recursion (Space complexity is less, more preferred way)
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> stack;
    if (!A)
        return res;
    stack.push(A);
    
    while (!stack.empty())
    {
        TreeNode* node = stack.top();
        res.emplace_back(node->val);
        stack.pop();
        if (node->right)
            stack.push(node->right);
        if (node->left)
            stack.push(node->left);
    }
    return res;
}
