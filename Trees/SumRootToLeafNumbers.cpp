/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
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
int sum(TreeNode* root, int total) {
    if (!root)
        return 0;
        
    total = ((total*10)%1003 + root->val)%1003;
    if (!root->left && !root->right)
        return total;
    return (sum(root->left, total)%1003 + sum(root->right, total)%1003)%1003;
}

int Solution::sumNumbers(TreeNode* A) {
    return sum(A, 0);
}
