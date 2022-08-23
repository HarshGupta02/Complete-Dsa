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
    
    ListNode* reverseList(ListNode *head)
    {
        ListNode* p1 = head;
        if(p1 -> next == NULL) return p1;
        ListNode* p2 = p1 -> next;
        p1 -> next = NULL;
        ListNode* p3 = p2 -> next;
        while(p3 != NULL){
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p2 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseList(slow -> next);
        ListNode* p1 = head, *p2 = slow -> next;
        while(p1 != NULL and p2 != NULL){
            if(p1 -> val != p2 -> val) return false;
            p1 = p1 -> next; p2 = p2 -> next;
        }
        return true;
    }
};