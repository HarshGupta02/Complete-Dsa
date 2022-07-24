void f_p(Node* root, Node* &p , int key){
    if(root == NULL) return;
    if(key <= root -> key) f_p(root -> left,p,key);
    else{p = root; f_p(root -> right,p,key);}
}

void f_r(Node* root, Node* &s , int key){
    if(root == NULL) return;
    if(key >= root -> key) f_r(root -> right,s,key);
    else{s = root; f_r(root -> left,s,key);}
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* p = NULL;
    f_p(root,p,key); pre = p;
    Node* s = NULL;
    f_r(root,s,key); suc = s;
}