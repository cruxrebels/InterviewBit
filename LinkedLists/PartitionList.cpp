/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

https://www.interviewbit.com/problems/partition-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A || !A->next)
        return A;
    ListNode* first, *second, *f, *s;
    first = second = f = s = NULL;
    while (A)
    {
        if(A->val < B)
        {
            if(!first)
                f = first = A;           
            else
            {
                first->next = A;
                first = first->next;
            }
        }
        else
        {
            if(!second)
                s = second = A;
            else
            {
                second->next = A;
                second = second->next;
            }
        }
        A = A->next;
    }
    if(s)
        second->next = NULL;
        
    if(f)
    {
        first->next = s;
        return f;
    }
    return s;
}
