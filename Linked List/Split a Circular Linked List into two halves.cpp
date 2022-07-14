void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast -> next != head and fast -> next -> next != head){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(fast -> next == head){
        fast -> next = slow -> next;
        slow -> next = head;
        *head1_ref = (slow -> next);
        *head2_ref = (fast -> next);
    }else{
        fast -> next -> next = slow -> next;
        slow -> next = head;
        *head1_ref = (slow -> next);
        *head2_ref = (fast -> next -> next);
    }
}