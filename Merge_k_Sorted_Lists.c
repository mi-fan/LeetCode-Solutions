//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

//1. link all the lists
//2. sort the merged list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(struct ListNode *p, struct ListNode *q);
void sortList(struct ListNode *begin, struct ListNode *end);
struct ListNode * arrangeList(struct ListNode *begin, struct ListNode *end);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(struct ListNode *p, struct ListNode *q);
void sortList(struct ListNode *begin, struct ListNode *end);
struct ListNode * arrangeList(struct ListNode *begin, struct ListNode *end);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *begin, *end;
    int i = 0;

    while (!lists[i]) i++;
	if (i >= listsSize)
		return NULL;

	begin = lists[i];

    while (i < listsSize)
    {
    	end = lists[i];

       	if (!lists[i]->next)
       	{
       		i++;
       		while (!lists[i] && i < listsSize) i++;
            
      	 	if (i >= listsSize)
        		break;
       		end->next = lists[i];
       	}
        else
       	    lists[i] = lists[i]->next;
    }

    if (begin)
    {
         sortList(begin, end);   
    }

    return begin;
}

void sortList(struct ListNode *begin, struct ListNode *end)
{
	if (begin == end)
        return;
    
    if (begin->next == end)
    {
        if (begin->val > end->val)
            swap(begin, end);
        
        return;
    }
	struct ListNode* p = arrangeList(begin, end);
    
    if (begin != p)
	    sortList(begin, p);
    
    if (p != end)
	    sortList(p->next, end);

	return;
}

struct ListNode * arrangeList(struct ListNode *begin, struct ListNode *end)
{
	struct ListNode *p = begin;
	struct ListNode *q = p->next;
	int key = p->val;

	while (q != NULL)
	{
		if (q->val < key)
		{
			p = p->next;
			swap (p, q);
		}
		q = q->next;
	}
	swap(begin, p);

	return p;
}

void swap(struct ListNode *p, struct ListNode *q)
{
	int temp = p->val;
	p->val = q->val;
	q->val = temp;

	return;
}