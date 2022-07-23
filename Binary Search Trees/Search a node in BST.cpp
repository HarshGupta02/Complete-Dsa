bool search(Node* root, int x) {
    if(root == NULL) return false;
    if(root -> data == x) return true;
    if(root -> data < x) return search(root -> right,x);
    return search(root -> left,x);
}