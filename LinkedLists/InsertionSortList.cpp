/*
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

https://www.interviewbit.com/problems/insertion-sort-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode *sorted = NULL;
    ListNode *list = A;
    
    while(list)
    {
        ListNode* curr = list;
        list = list->next;
        
        if(!sorted || sorted->val >= curr->val)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            ListNode* temp = sorted;
            while (temp)
            {
                ListNode* s = temp;
                temp = temp->next;
                
                if (!s->next || s->next->val > curr->val)
                {
                    curr->next = s->next;
                    s->next = curr;
                    break;
                }
            }
        }
    }
    return sorted;
}

//My initial feeble attempt
/*int length(ListNode* head)
{
    int len = 0;
    while(head)
    {
        head = head->next;
        ++len;
    }
    return len;
}
int forwardShift(ListNode* head, int n)
{
    while(n-1)
    {
        head = head->next;
        --n;
    }
    return head->val;
}

ListNode* forwardShiftPtr(ListNode* head, int n)
{
    while(n-1)
        head = head->next;
    return head;
}

ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A)
        return A;
        
    auto l = length(A);
    ListNode* head = A;
    for (auto i = 2; i<l+1; ++i)
    {
        auto value = forwardShift(head, i);
        auto hole = i;
        A = forwardShiftPtr(head, hole-1);
        while(hole>1 && forwardShift(head, hole-1) > value)
        {
            ListNode* next = A->next->next;
            ListNode* nPrev = A->next;
            A->next = next;
            nPrev->next = A;
            A = nPrev;
            hole = i-1;
        }
    }
    return A;
}*/
