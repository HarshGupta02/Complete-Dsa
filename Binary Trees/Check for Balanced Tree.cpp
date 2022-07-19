class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int f(Node* root , bool &is){
        if(root == NULL) return -1;
        if(root -> left == NULL and root -> right == NULL) return 0;
        int left_max = f(root -> left , is);
        int right_max = f(root -> right , is);
        if(abs(left_max - right_max) > 1) is = false;
        return 1 + max(left_max,right_max);
    }
    
    bool isBalanced(Node *root)
    {
        bool is = true;
        int x = f(root,is);
        return is;
    }
};