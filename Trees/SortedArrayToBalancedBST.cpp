/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
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

TreeNode* createBST(const vector<int>& A, int i, int j)
{
    if (i>j)
        return NULL;
    auto mid = (i+j) >> 1;
    TreeNode* root = new TreeNode(A[mid]);
    if (i==j)
        return root;
    root->left = createBST(A, i, mid-1);
    root->right = createBST(A, mid+1, j);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if (A.empty())
        return NULL;
    return createBST(A, 0, A.size()-1);
}
