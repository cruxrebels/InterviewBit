/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for constant space.
 Note 2: The tree need not be a perfect binary tree.
 
https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode* nextRight(TreeLinkNode* current)
{
    TreeLinkNode* currNext = current->next;
    
    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    if (!A)
        return;
    A->next = NULL;
    while (A)
    {
        TreeLinkNode* B = A;
        while (B)
        {
            if (B->left)
            {
                if (B->right)
                    B->left->next = B->right;
                else
                    B->left->next = nextRight(B);
            }
            if (B->right)
                B->right->next = nextRight(B);
                
            B = B->next;
        }
        if (A->left)
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = nextRight(A);
    }
    
    // Queue approach, less time complexity
    /*queue<TreeLinkNode*> Q;
    if (A)
        Q.push(A);
    A->next = NULL;
    
    while (!Q.empty())
    {
        TreeLinkNode* node = Q.front();
        if (node->left)
        {
            Q.push(node->left);
            if (node->right)
                node->left->next = node->right;
            else
                node->left->next = nextRight(node);
        }
        if (node->right)
        {
            Q.push(node->right);
            node->right->next = nextRight(node);
        }
        
        Q.pop();
    }*/
}
