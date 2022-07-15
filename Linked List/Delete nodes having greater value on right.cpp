class Solution
{
    public:
    
    struct Node* reverseList(struct Node *head)
    {
        struct Node* p1 = head;
        if(p1 -> next == NULL) return p1;
        struct Node* p2 = p1 -> next;
        p1 -> next = NULL;
        struct Node* p3 = p2 -> next;
        while(p3 != NULL){
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p2 -> next;
        }
        p2 -> next = p1;
        return p2;
    }
    
    Node *compute(Node *head)
    {
        head = reverseList(head);
        struct Node* curr = head -> next;
        struct Node* prev = head;
        int nax = prev -> data;
        while(curr != NULL){
            nax = max(nax , curr -> data);
            if(nax > curr -> data){
                prev -> next = curr -> next;
                curr = curr -> next;
            }else{
                prev = curr;
                curr = curr -> next;
            }
        }
        head = reverseList(head);
        return head;
    }
    
};