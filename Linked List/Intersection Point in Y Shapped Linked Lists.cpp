/*
here we move both the pointers simultaneously and if one reaches null we place it on the head of the other
list. and this will ensure that at one time, both will move in same position and collide as swapping is done
so that both the pointers travel the same distance.

*/

int intersectPoint(Node* head1, Node* head2)
{
    struct Node* p1 = head1;
    struct Node* p2 = head2;
    while(p1 != p2){
        p1 = p1 -> next; p2 = p2 -> next;
        if(p1 == NULL) p1 = head2;
        else if(p2 == NULL) p2 = head1;
        else continue;
    }
    return p1 -> data;
}