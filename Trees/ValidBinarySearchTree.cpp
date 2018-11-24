/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

https://www.interviewbit.com/problems/valid-binary-search-tree/
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
int isValidBSTHelper(TreeNode* root, int minValue, int maxValue)
{
    if (!root)  
        return 1;
    if (root->val > minValue && root->val < maxValue
        && isValidBSTHelper(root->left, minValue, root->val)
        && isValidBSTHelper(root->right, root->val, maxValue))
        return 1;
    else
        return 0;
}
int Solution::isValidBST(TreeNode* A) {
    return isValidBSTHelper(A, INT_MIN, INT_MAX);
}

// Brute force solution

/*int isValidLeftSubtree(TreeNode* left, int data) {
    if (!left)
        return 1;
    else if (left->val < data && isValidLeftSubtree(left->left, data)
                && isValidLeftSubtree(left->right, data))
        return 1;
    else
        return 0;
}

int isValidRightSubtree(TreeNode* right, int data) {
    if (!right)
        return 1;
    else if (right->val > data && isValidRightSubtree(right->left, data)
                && isValidRightSubtree(right->right, data))
        return 1;
    else
        return 0;
}

int Solution::isValidBST(TreeNode* A) {
    if (!A)
        return 1;
    return (isValidLeftSubtree(A->left, A->val) && isValidRightSubtree(A->right, A->val)
            && isValidBST(A->left) && isValidBST(A->right));
}*/
