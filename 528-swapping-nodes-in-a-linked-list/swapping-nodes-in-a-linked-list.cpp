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
    ListNode* swapNodes(ListNode* head, int k)
    {
        vector<int>ans;
        ListNode* temp = head;
        while (temp)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        int i = k - 1;        // corrected index
        int j = n - k;        // corrected index
        if (i >= 0 && j >= 0 && i < n && j < n) {
            swap(ans[i], ans[j]); // swapping the values
        }

        temp = head;
        for (int i = 0; i < ans.size(); i++)
        {
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }

};