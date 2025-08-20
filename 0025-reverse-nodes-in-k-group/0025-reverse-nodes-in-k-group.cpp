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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;

        while(true){
            // Check if there are k nodes ahead
            ListNode* check = first;
            int count = 0;
            while(count < k && check->next){
                check = check->next;
                count++;
            }
            if(count < k) break; // not enough nodes to reverse

            ListNode* second = first->next; // start of current group
            ListNode* prev = first;
            ListNode* curr = first->next;
            ListNode* front;

            int x = k;
            while(x--){
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            first->next = prev;     // connect previous part to new head
            second->next = curr;    // connect tail to next part
            first = second;         // move first to the tail for next group
        }

        head = dummy->next; 
        delete dummy; // safely delete dummy
        return head;
    }
};
