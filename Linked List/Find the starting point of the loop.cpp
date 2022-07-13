/*
we know that if both the slow and fast pointer meet at some place then the starting poing of the loop is at 
equal distances from the head node and the intersection node of slow and fast pointer.

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head -> next == NULL) return NULL;
        struct ListNode* p1 = head;
        struct ListNode* p2 = head;
        struct ListNode* p = head;
        while(p2 -> next != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
            if(p2 == NULL) return NULL;
            if(p1 == p2){
                while(p1 != p){
                    p = p -> next; p1 = p1 -> next;
                }
                return p;
            }
        }
        return NULL;
    }
};