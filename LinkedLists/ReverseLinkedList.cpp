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
ListNode* Solution::reverseList(ListNode* A) {
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
