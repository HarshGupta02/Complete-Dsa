class Solution {
public:
    Node *rotateDLL(Node *head,int p)
    {
        Node* tail = head;
        while(tail -> next != NULL){
            tail = tail -> next;
        }
        Node* curr = head;
        p--;
        while(p --){
            curr = curr -> next;
        }
        head -> prev = tail;
        tail -> next = head;
        head = curr -> next;
        curr -> next = NULL;
        head -> prev = NULL;
        return head;
    }
};