/*
Given linked list 1 -> 2 -> 3 -> 4 -> 5,

Return 4 -> 2 -> 3 -> 4 -> 5
as

for first node, 5 - 1 = 4
for second node, 4 - 2 = 2
Try to solve the problem using constant extra space.
https://www.interviewbit.com/problems/subtract/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void splitIntoTwo(struct ListNode *A, struct ListNode **f_ref, struct ListNode **b_ref) {
	struct ListNode *slow, *fast;
	slow = A;
	fast = A->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*f_ref = A;
	*b_ref = slow->next;
	slow->next = NULL;
}

void reverseList(struct ListNode **h_ref) {
	struct ListNode *current, *prev, *next;
	current = *h_ref;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*h_ref = prev;
}

void modifyFirstHalf(struct ListNode *front, struct ListNode *back) {
	while (back != NULL) {
		front->val = back->val - front->val;
		front = front->next;
		back = back->next;
	}
}
struct ListNode *concatenate(struct ListNode *front, struct ListNode *back) {
	struct ListNode *head = front;
	while (front->next != NULL)
		front = front->next;
	front->next = back;
	return head;
}

ListNode* Solution::subtract(ListNode* A) {
	if ((!A) || (A->next == NULL))
		return A;

	struct ListNode *front, *back;
	splitIntoTwo(A, &front, &back);
	reverseList(&back);
	modifyFirstHalf(front, back);
	reverseList(&back);
	A = concatenate(front, back);
	return A;
}