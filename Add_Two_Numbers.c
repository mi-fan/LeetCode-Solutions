You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head = l3;
    int add = 0;
    int p, q;

    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    while (l1 != NULL || l2 != NULL)
    {
    	if (l1) p = l1->val;
    	else p = 0;
    	if (l2) q = l2->val;
    	else q = 0; 
    	l3->val = p + q + add;
    	if (l3->val >= 10)
    	{
    		add = 1;
    		l3->val -= 10;
    	}
    	else
    		add = 0;
        
    	if (l1) l1 = l1->next;
    	if (l2) l2 = l2->next;
        
    	if (l1 == NULL && l2 == NULL)
    		break;
    
    	l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    	l3 = l3->next;
    }
    
    if (add)
    {
        l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        l3 = l3->next;
    	l3->val = 1;
    }
    l3->next = NULL;

    return head;
}