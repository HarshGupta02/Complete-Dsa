void deleteNode(struct Node **head, int key)
{
    struct Node* curr = *head;
    while(curr -> next -> data != key){
        curr = curr -> next;
    }
    curr -> next = curr -> next -> next;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    struct Node* p1 = *head_ref;
    struct Node* p2 = p1 -> next;
    struct Node* p3 = p2 -> next;
    while(p3 != *head_ref){
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p2 -> next;
    }
    p2 -> next = p1;
    p3 -> next = p2;
    *head_ref = p2;
}