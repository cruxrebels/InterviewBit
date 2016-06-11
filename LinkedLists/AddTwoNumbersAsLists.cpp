/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

https://www.interviewbit.com/problems/add-two-numbers-as-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
        
    int carry = 0, sum = 0;
    sum = A->val + B->val + carry;
    ListNode* newHead = new ListNode(sum%10);
    carry = sum/10;
    A = A->next;
    B = B->next;
    ListNode* newHeadPtr = newHead;
    
    while(A || B || carry)
    {
        sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        ListNode* temp = new ListNode(sum%10);
        carry = sum/10;
        newHead->next = temp;
        newHead = newHead->next;
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    
    return newHeadPtr;
}
