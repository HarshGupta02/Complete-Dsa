class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        struct Node* p1 = head;
        struct Node* p2 = head;
        while(p2 -> next != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
            if(p1 == NULL or p2 == NULL) return false;
            if(p1 == p2) return true;
        }
        return false;
    }
};