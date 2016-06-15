/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

https://www.interviewbit.com/problems/merge-two-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
        
    ListNode *res = new ListNode(0); // Don't do ListNode* res = NULL; *resPtr or 
    ListNode *resPtr = res;          // filling the list gives segmentation fault.
    while(A && B)
    {
        if(A->val <= B->val)
        {
            res->next = A;
            A = A->next;
        }
        else
        {
            res->next = B;
            B = B->next;
        }
        res = res->next;
    }
    
    while(A)
    {
        res->next = A;
        res = res->next;
        A = A->next;
    }
    while(B)
    {
        res->next = B;
        res = res->next;
        B = B->next;
    }
    return resPtr->next;
}
