/*
here we use slow and fast pointer and we first move the fast pointer by n distance and then move slow and fast
pointer together and this ensures that the gap will always be n and when fast pointer reaches end so the slow will
be the ans as it will be n distance from behind.
*/


int getNthFromLast(Node *head, int n)
{
    struct Node* slow = head;
    struct Node* fast = head;
    int temp = n - 1;
    while(temp > 0){
        fast = fast -> next;
        if(fast == NULL) break;
        temp --;
    }
    if(temp != 0) return -1;
    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow -> data;
}

// METHOD 2:

class Solution{
public:
    int getNthFromLast(Node *head, int n){
        Node* slow = head, *fast = head;
        while(fast != NULL) {
            if(n > 0) {
                fast = fast -> next;
                n --;
            }else {
                slow = slow -> next;
                fast = fast -> next;
            }
        }
        if(n > 0) return -1;
        return slow -> data;
    }
};