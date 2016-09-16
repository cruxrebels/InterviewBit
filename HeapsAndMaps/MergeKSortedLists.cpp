/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20

https://www.interviewbit.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Compare
{
    bool operator()(ListNode* const& a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if (A.empty())
        return NULL;
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    priority_queue<ListNode*, vector<ListNode*>, Compare> PQ;
    
    for (auto i = 0; i<A.size(); ++i)
    {
        if (A[i])
            PQ.emplace(A[i]);
    }
    
    while (!PQ.empty())
    {
        tail->next = PQ.top();
        PQ.pop();
        tail = tail->next;
        if (tail->next)
            PQ.emplace(tail->next);
    }
    return dummy->next;
}
