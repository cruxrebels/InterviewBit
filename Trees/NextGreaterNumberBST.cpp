/*
Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.

https://www.interviewbit.com/problems/next-greater-number-bst/
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
TreeNode* FindCurrentNode(TreeNode* A, int B)
{
    if (!A || A->val == B)
        return A;
    else if (A->val >= B)
        return FindCurrentNode(A->left, B);
    else if (A->val < B)
        return FindCurrentNode(A->right, B);
}

/*TreeNode* FindParentNode(TreeNode* root, TreeNode* dest)  // Doesn't work properly
{
    if (!root || root->left == dest || root->right == dest)
        return root;
    else if (root->val >= dest->val)
        return FindParentNode(root->left, dest);
    else if (root->val < dest->val)
        return FindParentNode(root->right, dest);
}*/

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* currNode = FindCurrentNode(A, B);
    if (!currNode)
        return currNode;
    
    TreeNode* currTemp = currNode;
    TreeNode* nxtGrt = NULL;
    
    if (currNode->right)    //Find deepest left leaf
    {
        currTemp = currTemp->right;
        while (currTemp->left)
            currTemp = currTemp->left;
        nxtGrt = currTemp;
    }
    else if (!currNode->right)  
    {
        /*TreeNode* parent = FindParentNode(A, currNode);
        if (parent)
        {
            if (parent->right == currNode) //Find nearest ancestor
                nxtGrt = FindParentNode(A, parent);
            else if (parent->left == currNode) //Find immediate parent
                nxtGrt = parent;
        }*/
        TreeNode* ancestor = A;
        while (ancestor != currNode)
        {
            if (currNode->val < ancestor->val)
            {
                nxtGrt = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
    }
    return nxtGrt;
}
