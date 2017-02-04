/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes: 
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

https://www.interviewbit.com/problems/palindrome-list/#
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if (!A || !A->next)
        return 1;
    stack<int> s;
    ListNode* slow = A, *fast = A;
    while (fast && fast->next)
    {
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (fast)
        slow = slow->next;
    
    while (s.size() && slow)
    {
        if (s.top() != slow->val)
            return 0;
        s.pop();
        slow = slow->next;
    }
    return 1;
}
