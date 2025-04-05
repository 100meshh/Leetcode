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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        while(curr1 && curr2)
        {
            if(curr1->val <= curr2->val)
            {
            temp->next=curr1;
            temp=temp->next;
            curr1=curr1->next;
            }
            else
            {
                temp->next=curr2;
                temp=temp->next;
                curr2=curr2->next;
            }
        }
        if(curr1)
        temp->next=curr1;
        else
        temp->next=curr2;
        // delete extra node
        temp=head;
        head=head->next;
        delete temp;
        return head;
    }
};