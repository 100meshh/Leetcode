#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    
    unordered_map<int, Node*> mpp;
    int capacity;
    Node *head, *tail;

    // Remove a node from the linked list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        if(prevNode) prevNode->next = nextNode;
        if(nextNode) nextNode->prev = prevNode;
    }

    // Insert node right after head
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity_) {
        capacity = capacity_;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if(mpp.size() == capacity) {
                Node* lru = tail->prev;
                deleteNode(lru);
                mpp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            insertAfterHead(node);
            mpp[key] = node;
        }
    }
};
