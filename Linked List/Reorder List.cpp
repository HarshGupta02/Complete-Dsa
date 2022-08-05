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
    
    ListNode* reverseLinkedList(ListNode* root){
        if(root == NULL) return NULL;
        if(root -> next == NULL) return root;
        if(root -> next -> next == NULL){
            ListNode* p1 = root, * p2 = root -> next;
            p1 -> next = NULL; p2 -> next = p1;
            return p2;
        }
        ListNode *p1 = root, *p2 = p1 -> next, *p3 = p2 -> next;
        p1 -> next = NULL;
        while(p3 != NULL){
            p2 -> next = p1;
            p1 = p2; p2 = p3; p3 = p2 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL or head -> next == NULL) return;
        ListNode* slow = head, *fast = head;
        while(fast -> next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // slow is the middle point
        ListNode* to_reverse = slow -> next;
        slow -> next = reverseLinkedList(to_reverse);
        ListNode* p1 = head, *p2 = slow -> next;
        while(p2 -> next != NULL){
            ListNode* p11 = p1 -> next, *p22 = p2 -> next;
            p1 -> next = p2;
            p2 -> next = p11;
            p1 = p11; p2 = p22;
        }
        ListNode* nxt = p1 -> next;
        p1 -> next = p2;
        if(p1 == slow) {
            p2 -> next = NULL;
        }
        else{
            p2 -> next = nxt; nxt -> next = NULL;
        }
    }
};