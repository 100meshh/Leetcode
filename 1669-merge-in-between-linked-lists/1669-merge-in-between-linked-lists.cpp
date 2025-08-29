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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* curr=list1;
        while(curr){
            count++;
            curr=curr->next;
        }
        curr=list1;
        ListNode* prev=NULL;
        while(a--){
            prev=curr;
            curr=curr->next;
        }
        curr=list1;
        while(b--){
            curr=curr->next;
        }
        curr=curr->next;
        ListNode* tail=list2; 
        prev->next=tail;
        while(tail->next){
            tail=tail->next;
        }
        tail->next=curr;
        return list1;
    }
};