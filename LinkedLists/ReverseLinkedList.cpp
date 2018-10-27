/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

https://www.interviewbit.com/problems/reverse-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Recursive approach
/*ListNode* RecursiveReverse(ListNode* prev, ListNode* curr, ListNode* head)
{
    if (!curr->next)
    {
        curr->next = prev;
        head = curr;
        return head;
    }
    ListNode* next = curr->next;
    curr->next = prev;
    return RecursiveReverse(curr, next, head);
}*/

ListNode* Solution::reverseList(ListNode* A) {
    // Recursive approach
    /*if (!A)
        return A;
    return RecursiveReverse(NULL, A, A);*/
    
    // Iterative approach
    ListNode* prev = NULL;
    ListNode* current = A;
    ListNode* next = A;
    
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    A = prev;
    return A;
}
