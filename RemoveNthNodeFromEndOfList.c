/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//relatively not so elegant
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode **arr; //an array of list address
    int i = 0;
    
    arr = (struct ListNode **)malloc(50*sizeof(struct ListNode *));
   	arr[0] = head;
    head = head->next;
   	i++;
    while (head != NULL)
    {
        arr[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
    	arr[i] = head;
    	head = head->next;
    	i++;
    }
    arr[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
    arr[i] = NULL;
    
    if (n == i) //remove the head
    {
        return arr[1];
    }
    else if (n == 1)
    {
        (arr[i - n - 1])->next = NULL;
    }
    else (arr[i - n - 1])->next = (arr[i - n])->next;

  	return arr[0];
}
