/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the 
 lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

https://www.interviewbit.com/problems/least-common-ancestor/
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

// Both are linear time complexity approaches
// Finding intersection of paths of val1 & val2 approach
/*bool findpath(TreeNode* root, vector<int>& path, int val)
{
    if (!root)
        return false;
    path.emplace_back(root->val);
    if (root->val == val)
        return true;
    if ((root->left && findpath(root->left, path, val)) ||
        (root->right && findpath(root->right, path, val)))
        return true;
    path.pop_back();
    return false;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    vector<int> path1, path2;
    if (!findpath(A, path1, val1) || !findpath(A, path2, val2))
        return -1;
    auto it1 = path1.cbegin();
    auto it2 = path2.cbegin();
    int same = -1;
    while (it1 != path1.cend() && it2 != path2.cend())
    {
        if (*it1 != *it2)  
            break;
        else
            same = *it1;
        ++it1; ++it2;
    }
    return same;
}*/

// Finding common node using recursion
bool find(TreeNode* root, int val)
{
    if (!root)
        return false;
    if (root->val == val)
        return true;
    if ((root->left && find(root->left, val)) || 
        (root->right && find(root->right, val)))
        return true;
    return false;
}

TreeNode* LCA(TreeNode* root, int val1, int val2)
{
    if (!root || root->val == val1 || root->val == val2)
        return root;
    
    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);
    
    if (L && R)
        return root;
    return L ? L : R;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    if (!find(A, val1) || !find(A, val2))
        return -1;
    auto ancestor = LCA(A, val1, val2);
    if (ancestor)
        return ancestor->val;
    return -1;
}
