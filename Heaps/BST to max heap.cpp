class Solution{
  public:
    
    void Inorder(Node* &root , vector<int> &a){
        if(root == NULL) return;
        Inorder(root -> right,a);
        a.push_back(root -> data);
        Inorder(root -> left,a);
    }
    
    void f(Node* &root , vector<int> &a, int &idx){
        if(root == NULL) return;
        root -> data = a[idx]; idx ++;
        f(root -> right , a , idx);
        f(root -> left, a , idx);
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int>a;
        Inorder(root, a);
        int idx = 0;
        f(root , a, idx);
    }    
};