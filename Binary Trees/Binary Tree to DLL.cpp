// here we use the concept that we keep on assigning the links as we encounter the 
// nodes in the inorder way.

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    void f(Node* root , int &occ , Node* &head , Node* &prev){
        if(root == NULL) return;
        f(root -> left,occ,head,prev);
        if(occ == 0){
            occ = 1; head = root; prev = root;
        }else{
            prev -> right = root;
            prev -> right -> left = prev;
            prev = prev -> right;
        }
        f(root -> right,occ,head,prev);
    }
    
    Node * bToDLL(Node *root)
    {
        Node* head = NULL , * prev = NULL;
        int occ = 0;
        f(root,occ,head,prev);
        return head;
    }
};