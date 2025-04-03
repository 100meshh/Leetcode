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
    // ListNode* Reverse(ListNode *curr, ListNode *prev)
    // {
    //     if(curr == NULL)
    //     return prev;

    //     ListNode *front =curr->next;
    //     curr->next=prev;
    //     return Reverse(front,curr);
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 =Reverse(l1,NULL);
        // l2 =Reverse(l2,NULL);
        ListNode *curr1=l1,*curr2=l2;
        ListNode *head = new ListNode(0);
        ListNode *tail= head;
        int sum,carry=0;


        while(curr1 && curr2)
        {
            sum=curr1->val+curr2->val+carry;
            tail->next=new ListNode(sum%10);
            curr1=curr1->next;
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(curr1)
        {
            sum=curr1->val+carry;
            tail->next=new ListNode(sum%10);
            curr1=curr1->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(curr2)
        {
            sum=curr2->val+carry;
            tail->next = new ListNode(sum%10);
            curr2 =curr2->next;
            tail=tail->next;
            carry =sum/10;
        }
        while(carry)
        {
            tail->next =new ListNode(carry%10);
            tail=tail->next;
            carry/=10;
        };
        // ListNode* result = Reverse(head->next, NULL);  
        ListNode* result = head->next;  

        // // Remove leading zero if present
        // if (result->val == 0 && result->next != NULL) {  
        //     result = result->next;  
        // }  
        return result;
    }
};