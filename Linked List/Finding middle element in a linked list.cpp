class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        struct Node* slow = head;
        struct Node* fast = head;
        while(fast != NULL and fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow -> data;
    }
};