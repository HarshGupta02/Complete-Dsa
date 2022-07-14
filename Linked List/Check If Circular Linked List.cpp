bool isCircular(struct Node *head){
    struct Node* curr = head;
    while(curr != NULL){
        if(curr -> next == head) return true;
        curr = curr -> next;
    }
    return false;
}