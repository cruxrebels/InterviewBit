/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
min depth = 2.

https://www.interviewbit.com/problems/min-depth-of-binary-tree/
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
int depth(TreeNode* A)
{
    if (!A)
        return INT_MAX;
    if (!A->left && !A->right)
        return 1;
    return 1 + min(depth(A->left), depth(A->right));
}
int Solution::minDepth(TreeNode* A) {
    if (!A)
        return 0;
    else if (!A->left && !A->right)
        return 1;
    return depth(A);
}
