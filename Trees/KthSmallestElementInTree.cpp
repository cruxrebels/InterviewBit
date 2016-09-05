/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
 
https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
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
void inorder(TreeNode* root, int& smallest, int k, int& it)
{
    if (!root)
        return;
    inorder(root->left, smallest, k, it);
    ++it;
    if (it == k)
    {
        smallest = root->val;
        return;
    }
    inorder(root->right, smallest, k, it);
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int smallest = -1;
    int it = 0;
    inorder(root, smallest, k, it);
    return smallest;
}
