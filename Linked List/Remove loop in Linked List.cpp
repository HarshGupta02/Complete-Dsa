class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        struct Node* p1 = head;
        struct Node* p2 = head;
        struct Node* p = head;
        while(p2 -> next != NULL){
            p1 = p1 -> next;
            p2 = p2 -> next -> next;
            if(p2 == NULL) return;
            if(p1 == p2){
                while(p1 != p){
                    p = p -> next; p1 = p1 -> next;
                }
                break;
            }
        }
        int enc = 0;
        struct Node* prev = head;
        while(prev -> next != NULL){
            if(prev -> next == p and enc == 1){
                prev -> next = NULL; return;
            }
            if(prev -> next == p and enc == 0){
                enc = 1;
            }
            prev = prev -> next;
        }
    }
};