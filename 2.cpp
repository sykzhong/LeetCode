#include <stdlib.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int sum = l1->val + l2->val;
		ListNode *head = new ListNode(sum%10);
		int flag = sum / 10;
		ListNode *tmpnode = head;
		int v1 =0, v2 = 0;
		while(l1->next != NULL || l2->next != NULL || flag != 0)
		{
			
			v1 = (l1->next == NULL ? 0 : l1->next->val);
			v2 = (l2->next == NULL ? 0 : l2->next->val);
			if(l1->next != NULL)
				l1 = l1->next;
			if(l2->next != NULL)
				l2 = l2->next;
			sum = v1 + v2 + flag;
			flag = sum/10;
			tmpnode->next = new ListNode(sum%10);
			tmpnode = tmpnode->next;
		}
		return head;
    }
};