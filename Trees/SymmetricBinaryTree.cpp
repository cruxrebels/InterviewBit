/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

https://www.interviewbit.com/problems/symmetric-binary-tree/
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
int isSymmetricHelper(TreeNode* root1, TreeNode* root2)
{
    if (!root1 || !root2)
        return root1 == root2;
    if (root1->val != root2->val)
        return 0;
        
    return isSymmetricHelper(root1->left, root2->right) && 
            isSymmetricHelper(root1->right, root2->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return A == NULL || isSymmetricHelper(A->left, A->right);
}
