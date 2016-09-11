/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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
int findIndex(vector<int> &inorder, int i, int j, int val)
{
    for (auto b = i; b<=j; ++b)
        if (inorder[b]==val)
            return b;
}
TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    TreeNode* node = new TreeNode(preorder[p++]);
    if (i==j)
        return node;
    int in = findIndex(inorder, i, j, node->val);
    node->left = makeTree(preorder, inorder, i, in-1, p);
    node->right = makeTree(preorder, inorder, in+1, j, p);
    return node;
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty())
        return NULL;
    int p = 0;
    return makeTree(preorder, inorder, 0, inorder.size()-1, p);
}
