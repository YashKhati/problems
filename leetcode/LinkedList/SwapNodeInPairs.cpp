class Solution {
public:
    ListNode* getAns(ListNode * head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head->next;
        head->next=temp->next;
        temp->next=head;
        head->next=getAns(head->next);
        return temp;
    }
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL)
        {
            return head;
        }
        ListNode* ans=head;
        ans=getAns(head);
        return ans;
    }
};
