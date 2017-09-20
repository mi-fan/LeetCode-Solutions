/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swapTwo(struct ListNode **p, struct ListNode **q);

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode **lists;
    struct ListNode *p, *begin;
    int size, base, i;

    if (head == NULL || head->next == NULL || k == 1)
    	return head;

    begin = head;
    size = 0;
    i = 0;
    while (head)  //find end and length
    {
        size++;
        head = head->next;
    }
    head = begin;
    lists = (struct ListNode **)malloc(size*sizeof(struct ListNode*));
    while (head)  //save nodes to array
    {
     	lists[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
     	lists[i] = head;
     	head = head->next;
     	i++;
    }

    base = 0;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    while (base + k <= size)
    {
    	for (i = 0; i < k/2; i++) //reverse 0~(k-1)
    	{
    		swapTwo(&lists[base + i], &lists[base + k - i - 1]);
    	}
    	base += k;
    }
    lists[size - 1]->next = NULL;
    for (i = 0; i < size - 1; i++)
    {
    	lists[i]->next = lists[i + 1];
    }
    return lists[0];
}

void swapTwo(struct ListNode **p, struct ListNode **q)
{
	struct ListNode *temp = *p;
	*p = *q;
	*q = temp;
	return;
}