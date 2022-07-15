struct Node* reverseDLL(struct Node * head)
{
    struct Node* curr = head;
    struct Node* nxt;
    while(curr -> next != NULL){
        nxt = curr -> next;
        curr -> next = curr -> prev;
        curr -> prev = nxt;
        curr = nxt;
    }
    curr -> next = curr -> prev;
    curr -> prev = nxt;
    return curr;
}