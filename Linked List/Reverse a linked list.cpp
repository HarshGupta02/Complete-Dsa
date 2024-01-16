// ITERATIVE

class Solution
{
    public:
    //Function to reverse a linked list.
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
    }struct Node* reverseList(struct Node *head)
    {
  
    
};

// RECURSIVE

class Solution
{
    public:
    //Function to reverse a linked list.
    
    void Reverse(struct Node* &p1 , struct Node* &p2,struct Node* &p3){
        if(p3 == NULL) return;
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p2 -> next;
        Reverse(p1,p2,p3);
    }
    
    struct Node* reverseList(struct Node *head)
    {
        struct Node* p1 = head;
        if(p1 -> next == NULL) return p1;
        struct Node* p2 = p1 -> next;
        p1 -> next = NULL;
        struct Node* p3 = p2 -> next;
        Reverse(p1,p2,p3);
        p2 -> next = p1;
        return p2;
    }
    
};