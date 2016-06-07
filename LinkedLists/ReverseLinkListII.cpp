/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

https://www.interviewbit.com/problems/reverse-link-list-ii/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if (!A)
        return NULL;
    if(m==n)
        return A;
    ListNode *temp, *current, *prev, *next, *start, *end;
    int i = 1;
    temp = A;
    bool flag = false;
    if(m==1)
        flag = true;
    while(i<m)
    {
        start = temp; //(m-1)th node
        temp = temp->next;
        ++i;
    }
    current = next = temp;
    
    while(i<n)
    {
        temp = temp->next;
        ++i;
    }
    end = temp; //nth node
    prev = temp->next;
    ListNode *endplus = end->next;
    while(current != endplus)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if(flag)
        A = prev;
    else
        start->next = prev;
    return A;
}
