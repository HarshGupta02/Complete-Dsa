Node* findIntersection(Node* head1, Node* head2)
{
    struct Node* p1 = head1;
    struct Node* p2 = head2;
    struct Node* head = new Node(-1);
    struct Node* curr = head;
    while(p1 != NULL and p2 != NULL){
        if(p1 -> data < p2 -> data){
            p1 = p1 -> next; continue;
        }
        if(p1 -> data > p2 -> data){
            p2 = p2 -> next; continue;
        }
        struct Node* new_node = new Node(p1 -> data);
        curr -> next = new_node;
        curr = new_node;
        p1 = p1 -> next; p2 = p2 -> next;
    }
    head = head -> next;
    return head;
}