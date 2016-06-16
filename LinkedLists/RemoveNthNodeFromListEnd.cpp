/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
* If n is greater than the size of the list, remove the first node of the list. 
Try doing it using constant additional space.

https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        ++len;
    }
    return len;
}
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(!A)
        return A;
    if(B==0)
        B = 1;
        
    auto l = length(A);
    int last;
    bool remFirst = false;
    
    if(B<l)
        last = l - B;
    else
        remFirst = true;
        
    if(remFirst)
    {
        A = A->next;
        return A;
    }
    
    ListNode* head = A;
    while(last-1)
    {
        A = A->next;
        --last;
    }
    
    A->next = A->next->next;
    
    return head;
}
