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
    ListNode* swapPairs(ListNode* head) {
        //copy ll in vector
        vector<int>arr;
        ListNode* curr=head;
        if(!head)return NULL;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        //swap in array
        int i=0;
        int j=i+1;
        int n=arr.size();
        while(i<n && j<n){
            swap(arr[i],arr[j]);
            i=j+1;
            j=i+1;
        }
        //put back in ll
        ListNode* temp=head;
        for(int i=0;i<arr.size();i++){
            temp->val=arr[i];
            temp=temp->next;
        }
        return head;

    }
};