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
    ListNode* reverseList(ListNode* head) {
        vector<int>ans;
        ListNode *curr=head,*fut=NULL,*prev=NULL;
        while(curr)
        {
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        head=prev;
        return head;
        
    }
};