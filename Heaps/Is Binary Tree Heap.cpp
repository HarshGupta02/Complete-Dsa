/*
here completeness means that all the levels other than the last level must
be completely filled and the nodes in the last level must be filled from 
extreme left to right. 

after we see the first null node , any not null node must not appear. if it
appears so it means that the tree is not complete.

*/

class Solution {
  public:
  
    bool heap(Node* &root){
        if(root == NULL) return true;
        if(root -> left == NULL and root -> right == NULL) return true;
        bool can = isHeap(root -> left) and isHeap(root -> right);
        if(can == true){
            if(root -> left != NULL and root -> left -> data >= root -> data) return false;
            if(root -> right != NULL and root -> right -> data >= root -> data) return false;
            return true;
        }
        else return false;
    }
    
    bool completeness(Node* &root){
        queue<Node*>q;
        q.push(root);
        bool seen = false;
        while(!q.empty()){
            Node* curr_node = q.front(); q.pop();
            if(curr_node == NULL){
                seen = true;
            }else{
                if(seen == true) return false;
                q.push(curr_node -> left);
                q.push(curr_node -> right);
            }
        }
        return true;
    }
    
    bool isHeap(struct Node* root) {
        return heap(root) and completeness(root);
    }
};