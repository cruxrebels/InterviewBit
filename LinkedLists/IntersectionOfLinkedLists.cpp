/*

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

https://www.interviewbit.com/problems/intersection-of-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int len(ListNode* head)
 {
    int l = 0;
    while(head->next != NULL)
    {
        ++l;
        head = head->next;
    }
    return l;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    if(!A || !B)
        return NULL;
    int lenA = len(A);
    int lenB = len(B);
    int lenDiff = lenA - lenB;
    ListNode *pa = A;
    ListNode *pb = B;
    if(lenDiff > 0) {
        while(lenDiff != 0) {
            pa = pa->next;
            lenDiff--;
        }
    }
    else if(lenDiff < 0) {
        while(lenDiff != 0) {
            pb = pb->next;
            lenDiff++;
        }
    }
    while(pa && pb) {
        if(pa == pb)
            return pa;
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}
