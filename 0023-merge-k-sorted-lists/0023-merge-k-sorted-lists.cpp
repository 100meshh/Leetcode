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
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//     }
// };

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Your code here
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> P;
for (int i = 0; i < k; ++i) {
    if (lists[i] != nullptr) {
        P.push(lists[i]);
    }
}
        ListNode* root = new ListNode(0);
        ListNode* tail= root;
        ListNode* temp;
        while(!P.empty()){
            temp=P.top();
            P.pop();
            tail->next=temp;
            tail=tail->next;
            
        if(temp->next){
            P.push(temp->next);
        }
        }
        return root->next;
    }
};