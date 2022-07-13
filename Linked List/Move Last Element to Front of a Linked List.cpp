class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head == NULL or head -> next == NULL) return head;
        struct ListNode* p1 = head;
        struct ListNode* p2 = head -> next;
        while(p2 -> next != NULL){
            p1 = p2;
            p2 = p2 -> next;
        }
        p2 -> next = head;
        p1 -> next = NULL;
        return p2;
    }
};