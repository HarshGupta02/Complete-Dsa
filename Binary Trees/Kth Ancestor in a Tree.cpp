void f(Node* root , int &k , int node , bool &found , Node* &ans){
    if(root == NULL) return;
    if(root -> data == node){
        found = true; return;
    }
    f(root -> left,k,node,found,ans);
    if(found == true){
        if(k == 1){
            ans = root;
        }
        k --; return;
    }
    f(root -> right,k,node,found,ans);
    if(found == true){
        if(k == 1){
            ans = root;
        }
        k --; return;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    bool found = false;
    Node* ans = NULL;
    f(root,k,node,found,ans);
    if(!found or ans == NULL) return -1;
    return ans -> data;
}