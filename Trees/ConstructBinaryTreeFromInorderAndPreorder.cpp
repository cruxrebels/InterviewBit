/*
Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
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
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    vector<TreeNode *> st;
    int ptrInOrder = 0;
    int ptrPreOrder = 0;
    TreeNode * root;
    TreeNode * temp;
    root = new TreeNode(preorder[ptrPreOrder++]);
    st.push_back(root);
    while(ptrPreOrder < preorder.size()){
        if(st.back()->val == inorder[ptrInOrder]){
            temp = st.back();
            st.pop_back();
            ptrInOrder++;
            if(!st.empty() && st.back()->val == inorder[ptrInOrder]){
                continue;
            }else{
                temp->right = new TreeNode(preorder[ptrPreOrder++]);
                st.push_back(temp->right);
            }
            
        }else{
            temp = new TreeNode(preorder[ptrPreOrder++]);
            st.back()->left = temp;
            st.push_back(temp);
        }
    }
    return root;
}
