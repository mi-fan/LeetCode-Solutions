//Given a linked list, swap every two adjacent nodes and return its head.

//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.

//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *begin, *p, *q, *r, *s;

	if ((!head) || !(head->next))
		return head;

	begin = head->next;
	p = head;

	while(p->next)
	{
		q = p->next;
		if ((r = q->next) != NULL)
		{
			p->next = r;
			q->next = p;
            if (begin != q)
                s->next = q;
		}
		else
		{
            s->next = q;
			q->next = p;
			p->next = NULL;
			break;
		}
        s = p;
		p = r;
	}


	return begin;
}