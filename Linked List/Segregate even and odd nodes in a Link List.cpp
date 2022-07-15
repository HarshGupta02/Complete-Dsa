class Solution{
public:
    Node* divide(int N, Node *head){
        struct Node* first_odd = NULL;
        struct Node* first_even = NULL;
        struct Node* curr = head;
        while(curr != NULL){
            if(curr -> data % 2 == 0){
                first_even = curr; break;
            }
            curr = curr -> next;
        }
        curr = head;
        while(curr != NULL){
            if(curr -> data % 2 == 1){
                first_odd = curr; break;
            }
            curr = curr -> next;
        }
        if(first_odd == NULL or first_even == NULL) return head;
        struct Node* start_odd = first_odd;
        struct Node* start_even = first_even;
        curr = head;
        while(curr != NULL){
            if(curr == first_odd or curr == first_even){
                curr = curr -> next; continue;
            }
            if(curr -> data % 2 == 1){
                first_odd -> next = curr;
                first_odd = curr;
            }else{
                first_even -> next = curr;
                first_even = curr;
            }
            curr = curr -> next;
        }
        first_odd -> next = NULL;
        first_even -> next = start_odd;
        return start_even;
    }
};