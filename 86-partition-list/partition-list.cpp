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
ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode(0);
    ListNode* r1 = new ListNode(0);
    ListNode* temp_l1 = l1;
    ListNode* temp_l2 = r1;
    ListNode* curr = head;

    while (curr) {
        if (curr->val < x) {
            temp_l1->next = new ListNode(curr->val);
            temp_l1 = temp_l1->next;
        } else {
            temp_l2->next = new ListNode(curr->val);
            temp_l2 = temp_l2->next;
        }
        curr = curr->next; 
    }

    temp_l1->next = r1->next; 
    return l1->next; 
}

};