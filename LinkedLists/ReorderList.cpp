/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

https://www.interviewbit.com/problems/reorder-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* mid)
{
    if(!mid || !mid->next)
        return mid;
    ListNode *curr, *next, *prev;
    prev = mid; //didn't understand this part; should be NULL but that doesn't works.
    curr = mid->next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = curr;
    return prev;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    ListNode* head = l1;
    l1 = l1->next;
    bool alteringListFlag = true;
    ListNode* p = head;
    while(l1 && l2)
    {
        if(!alteringListFlag)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        alteringListFlag = !alteringListFlag;
        p = p->next;
    }
    
    if(l1)
        p->next = l1;
    else
        p->next = l2;
    return head;
}

ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next || !A->next->next)
        return A;
    ListNode *p, *q;
    p = q = A;
    while (q->next && q->next->next)
    {
        p = p->next;
        q = q->next->next;
    }
    ListNode* mid = p->next;
    p->next = NULL;
    
    //now p is middle pointer
    //reverse p->next to end
    ListNode* secondHalfPointer = reverse(mid);
    
    /*q = p->next;
    while (q->next){
        ListNode* tmp = p->next;
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = tmp;
    }*/
     
    //reorder
    return A = merge(A, secondHalfPointer);
    /*q = A;
    while (p!=q && p->next){
        ListNode* tmp = q->next;
        q->next = p->next;
        p->next = p->next->next;
        q->next->next = tmp;
        q=q->next->next;
    }
    return A;*/
}
