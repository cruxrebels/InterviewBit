/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if (!A)
        return NULL;
    ListNode* head = A;
    ListNode* curr, *next, *prev;
    prev = NULL;
    curr = A;
    next = curr->next;
    if(next)
        A = next;
    while (next)
    {
        curr->next = next->next;
        next->next = curr;
        if(prev)            
            prev->next = next;      //I had missed this part of linking 1 to 4: 2->1 ~ 4->3
        prev = curr;
        curr = curr->next;
        if(curr)
            next = curr->next;
        else
            next = NULL;
    }
    return A;
}
