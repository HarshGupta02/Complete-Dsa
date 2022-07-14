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
    
    void add(int &carry , int sum, struct Node* &curr){
        carry = (sum / 10);
        int val = sum % 10;
        struct Node* new_node = new Node(val);
        curr -> next = new_node;
        curr = new_node;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first); second = reverseList(second);
        struct Node* p1 = first;
        struct Node* p2 = second;
        int carry = 0;
        struct Node* head = new Node(-1);
        struct Node* curr = head;
        while(p1 != NULL and p2 != NULL){
            int sum = p1 -> data + p2 -> data + carry;
            add(carry,sum,curr);
            p1 = p1 -> next; p2 = p2 -> next;
        }
        while(p1 != NULL){
            int sum = p1 -> data + carry;
            add(carry,sum,curr);
            p1 = p1 -> next;
        }
        while(p2 != NULL){
            int sum = p2 -> data + carry;
            add(carry,sum,curr);
            p2 = p2 -> next;
        }
        if(carry != 0){
            struct Node* temp = new Node(carry);
            curr -> next = temp;
        }
        head = head -> next;
        head = reverseList(head);
        return head;
    }
};