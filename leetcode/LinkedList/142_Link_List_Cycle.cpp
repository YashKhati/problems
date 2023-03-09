/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head || !head->next)
            return nullptr;
        
        ListNode *fast=head,*slow=head;

		//we will find the intersecting point of fast and slow if exist
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(slow != fast && fast && fast->next);
		
		//check if the cycle is there or not
        if(!fast  || ! fast->next)
        {
            return nullptr;
        }
        else{
		//if present then we will take slow to the head
            slow=head;
			//while they dont meet again we will increment distance by one 
            while(fast != slow){
                fast=fast->next;
                slow=slow->next;
            }
        }
		//returning the slow
        return slow;
        
    }
};
