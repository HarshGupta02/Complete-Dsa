Node *removeDuplicates(Node *head)
{
    if(head == NULL) return NULL;
    if(head -> next == NULL) return head;
    struct Node* p1 = head;
    struct Node* p2 = head -> next;
    while(p2 != NULL){
        int val1 = p1 -> data;
        int val2 = p2 -> data;
        if(val1 != val2){
            p1 -> next = p2;
            p1 = p2;
        }
        p2 = p2 -> next;
    }
    p1 -> next = NULL;
    return head;
}