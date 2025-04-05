/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* reverse(ListNode* curr,ListNode* prev)
    {
        if(curr==NULL)
        return prev;
        ListNode* fut=curr->next;
        curr->next=prev;
        return reverse(fut,curr);
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return NULL;
        head=reverse(head,NULL);
        int curr_max=head->val;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr)
        {
            if(curr->val<prev->val)
            {
                prev->next=curr->next;
            }
            else
            {
                prev=prev->next;
            }
            curr=curr->next;
        }
        head=reverse(head,NULL);
        return head;

       
    }
};