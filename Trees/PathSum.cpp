/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

https://www.interviewbit.com/problems/path-sum/
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
int pathsum(TreeNode* root, int sum, const int& B)
{
    if (!root)
        return 0;
    sum += root->val;
    if (!root->left && !root->right)
        return sum == B;
    auto resl = pathsum(root->left, sum, B);
    auto resr = pathsum(root->right, sum, B);
    if (resl || resr)
        return 1;   // Lines 17-21 can be written as below:
    return 0;       // return (pathsum(root->left, sum, B) | pathsum(root->right, sum, B));
}
int Solution::hasPathSum(TreeNode* A, int B) {
    if (!A)
        return 0;
    return pathsum(A, 0, B);
}
