/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
      
https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
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
int maxVal(int i, int j, vector<int>& A)
{
    int maxi = i;
    for (auto p = i+1; p<=j; ++p)
        if (A[maxi]<A[p])
            maxi = p;
    return maxi;
}

TreeNode* makeTree(int i, int j, vector<int>& A)
{
    if (i>j)
        return NULL;
    auto r = maxVal(i, j, A);
    TreeNode* node = new TreeNode(A[r]);
    node->left = makeTree(i, r-1, A);
    node->right = makeTree(r+1, j, A);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    if (A.empty())
        return NULL;
    return makeTree(0, A.size()-1, A);
}
