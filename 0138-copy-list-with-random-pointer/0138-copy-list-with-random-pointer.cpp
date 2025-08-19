/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        //make a copy
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }

        //copy random pointer also
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        //separate two lls
        temp=head;
        Node* newhead=head->next;
        Node* newtemp=newhead;
        while(temp){
            temp->next=newtemp->next;
            temp=temp->next;
            if(temp!=NULL){
                newtemp->next=temp->next;
                newtemp=newtemp->next;
            }
        }
        return newhead;
    }
};