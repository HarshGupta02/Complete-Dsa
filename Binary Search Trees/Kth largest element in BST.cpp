class Solution
{
    public:
    int ans = INT_MAX;
    
    void f(Node* root , int &k){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL){
            k --; if(k == 0) ans = min(ans , root -> data);
            return;
        }
        f(root -> right,k);
        k --; if(k == 0) ans = min(ans, root -> data);
        f(root -> left,k);
    }
    
    int kthLargest(Node *root, int k)
    {
        f(root , k);
        return (k <= 0 ? ans : -1);
    }
};