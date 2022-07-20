class Solution
{
    public:
    
    int f(Node* root , bool &is){
        if(root == NULL) return 0;
        if(root -> left == NULL and root -> right == NULL) return root -> data;
        int left_sum = f(root -> left,is);
        int right_sum = f(root -> right,is);
        if(left_sum + right_sum != root -> data){
            is = false; return 0;
        }
        return left_sum + right_sum + root -> data;
    }
    
    bool isSumTree(Node* root)
    {
        bool is = true;
        int x = f(root,is);
        return is;
    }
};