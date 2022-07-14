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
    
    Node* addOne(Node *head) 
    {
        if(head == NULL) return head;
        head = reverseList(head);
        struct Node* prev = NULL;
        struct Node* curr = head;
        int carry = 0;
        while(curr != NULL){
            int val = curr -> data;
            if(curr == head){
                curr -> data = (val + 1) % 10;
                carry = (val + 1) / 10;
            }else{
                curr -> data = (val + carry) % 10;
                carry = (val + carry) / 10;
            }
            prev = curr;
            curr = curr -> next;
        }
        if(carry != 0){
            struct Node* p = new Node(carry);
            prev -> next = p;
        }
        head = reverseList(head);
        return head;
    }
};