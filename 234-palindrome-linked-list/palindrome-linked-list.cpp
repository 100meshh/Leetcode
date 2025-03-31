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
    bool isPalindrome(ListNode* head) {

        // method 1 by using vector(extra space)

        // vector<int>ans;
        // ListNode *temp=head;
        // while(temp)
        // {
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int start=0;
        // int end=ans.size()-1;
        // while(start<=end)
        // {
        //     if(ans[start]!=ans[end])
        //     {
        //         return false;
        //     }
        //     start++;
        //     end--;
        // }
        // return true;

        // method 2 no use of extra space
        if(head->next==NULL)
        return true;
        int count=0;
        ListNode *temp =head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(count--)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        ListNode *front = NULL;
        prev=NULL;
        while(curr)
        {
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        ListNode *head1=head,*head2=prev;
        while(head1)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return 1;
        
    }
};