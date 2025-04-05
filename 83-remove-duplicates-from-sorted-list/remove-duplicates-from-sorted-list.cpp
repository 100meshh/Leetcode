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
    ListNode* deleteDuplicates(ListNode* head) {
         if (head == NULL || head->next == NULL) return head;
        ListNode* curr1=head;
        ListNode* curr2=head->next;
        // curr1=head;
        // curr2=head->next;
        while(curr2!=NULL)
        {
            if(curr1->val==curr2->val)
            {
                curr1->next=curr2->next;
                curr2=curr1->next;
            }else{
            curr1=curr1->next;
            curr2=curr2->next;
            }
        }
        return head;
    }
};