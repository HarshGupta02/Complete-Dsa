/*
TIME = O(N * M), SPACE = O(1)

so here we try to merge multiple linked lists so using this idea, we first use the 
concept of merging 2 sorted linked lists and return the head of the merged linked list
to the previous function call using recursion and then again call the merge function.
so we use recursion and our base case is returing the head of the last linked list.

*/

class Solution {
public:

    Node* mergee(Node* a, Node* b){
        Node* temp = new Node(0);
        Node* res = temp;
        while(a != NULL and b != NULL){
            if(a -> data < b -> data){
                temp -> bottom = a;
                temp = temp -> bottom;
                a = a -> bottom;
            }else{
                temp -> bottom = b;
                temp = temp -> bottom;
                b = b -> bottom;
            }
        }
        if(a != NULL) temp -> bottom = a;
        else temp -> bottom = b;
        return res -> bottom;
    }
    
    Node *flatten(Node *root){
        if(root == NULL or root -> next == NULL) return root;
        root -> next = flatten(root -> next);
        root = mergee(root, root -> next);
        return root;
    }
};