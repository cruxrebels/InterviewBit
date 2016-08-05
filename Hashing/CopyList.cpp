/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

https://www.interviewbit.com/problems/copy-list/
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if (!A)
        return NULL;
    
    RandomListNode* head = A;
    
    while (A)
    {
        RandomListNode* copyA = new RandomListNode(A->label);
        copyA->next = A->next;
        A->next = copyA;
        A = copyA->next;
    }
    A = head;
    
    while (A)
    {
        if (!A->random)             // I missed this check.
            A->next->random = NULL;
        else
            A->next->random = A->random->next;
            
        A = A->next->next;
    }
    A = head;
    
    RandomListNode* copy = A->next;
    RandomListNode* copyHead = A->next;
    
    while (A)
    {
        A->next = A->next->next;
        A = A->next;
        if (!copy->next)            // I missed this check.
            break;
        copy->next = copy->next->next;
        copy = copy->next;
    }
    
    return copyHead;
}
