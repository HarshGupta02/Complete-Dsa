// METHOD 1:

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node -> next;
        while(curr -> next != NULL){
            node -> val = curr -> val;
            node = node -> next;
            curr = curr -> next;
        }
        node -> val = curr -> val;
        node -> next = NULL;
    }
};

// METHOD 2:

class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};