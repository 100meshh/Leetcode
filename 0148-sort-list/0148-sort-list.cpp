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
    ListNode* sortList(ListNode* head) {

        // Approach:-ll(given) to array bnao - to - usi ll me value dalo firse(sorted)
        vector<int>ans;
        if(head==NULL || head->next==NULL) return head;
        ans.push_back(head->val);
        ListNode* temp=head->next;
        while(temp)
        {
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        int i=0;
        temp=head;
        for(int i=0;i<ans.size();i++)
        {
            temp->val=ans[i];
            temp=temp->next;
        }
        return head;
        
    }
};