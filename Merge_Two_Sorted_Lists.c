/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
   struct ListNode *head, *l3;
    
    if (l2 == NULL)
    	return l1;
    if (l1 == NULL)
    	return l2;
    
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));

    head = l3;
    
    if (l1->val < l2->val)
    {
    	l3->val = l1->val;
    	l1 = l1->next;
    }
    else
    {
    	l3->val = l2->val;
    	l2 = l2->next;
    }
  

    while (l1 != NULL && l2 != NULL)
    {
        l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        l3 = l3->next;
        
	    if (l1->val < l2->val)
	    {
	    	l3->val = l1->val;
	    	l1 = l1->next;
	    }
	    else
	    {
	    	l3->val = l2->val;
	    	l2 = l2->next;
	    }
	}
    
    if (l2 == NULL)
    {
        l3->next = l1;
    }           
    else
    {
        l3->next = l2;
    }

	return head;
}