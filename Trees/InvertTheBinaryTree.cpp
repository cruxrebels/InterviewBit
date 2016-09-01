/*
Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4

https://www.interviewbit.com/problems/invert-the-binary-tree/
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
void invert(TreeNode* root)
{
    if (!root || (!root->left && !root->right))
        return;
    invert(root->left);
    invert(root->right);
    TreeNode* tempLNode = root->left;
    root->left = root->right;
    root->right = tempLNode;
}
TreeNode* Solution::invertTree(TreeNode* root) {
    invert(root);
    return root;
}
