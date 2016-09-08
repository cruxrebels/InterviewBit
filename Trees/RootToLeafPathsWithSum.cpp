/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
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
void allpaths(vector<vector<int>>& res, vector<int>& temp, TreeNode* A, int sum)
{
    if (!A)
        return;
    sum -= A->val;
    temp.emplace_back(A->val);
    if (!A->left && !A->right && sum == 0)
        res.emplace_back(temp);
    if (A->left)
        allpaths(res, temp, A->left, sum);
    if (A->right)
        allpaths(res, temp, A->right, sum);
    temp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> temp;
    int i = 0;
    allpaths(res, temp, root, sum);
    return res;
}
