/*
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 
         
https://www.interviewbit.com/problems/balanced-binary-tree/
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
int height(TreeNode* node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    
    auto l = 1 + height(node->left);
    auto r = 1 + height(node->right);
    
    if (l<0 || r<0)
        return INT_MIN;
    if (abs(l-r)>1)
        return INT_MIN;
    return max(l, r);
}
int Solution::isBalanced(TreeNode* A) {
    if (height(A)<0)
        return 0;
    return 1;
}
