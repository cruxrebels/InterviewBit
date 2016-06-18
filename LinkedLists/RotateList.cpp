/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

https://www.interviewbit.com/problems/rotate-list/
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
    while(head)
    {
        head = head->next;
        ++len;
    }
    return len;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (!A || !A->next)
        return A;
        
    auto l = length(A);
    int last = 0;
    
    if(B%l==0)
        return A;
    else if(l>B)
        last = l-B;
    else
    {
        auto b = B%l;
        last = l - b;
    }
    
    ListNode* headptr = A;
    while(last-1)
    {
        A = A->next;
        --last;
    }
    
    ListNode* tempNext, *newHead;
    tempNext = newHead = A->next;
    A->next = NULL;
    
    while(tempNext->next)
        tempNext = tempNext->next;
    
    tempNext->next = headptr;
    A = newHead;
    return A;
}
