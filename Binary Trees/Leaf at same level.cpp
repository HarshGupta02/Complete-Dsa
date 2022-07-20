class Solution{
  public:
    /*You are required to complete this method*/
    
    int ans = -1;
    
    void f(Node* root , bool &is , int &occ, int level){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL){
            if(occ == 0){
                occ = 1;
                ans = level;
            }else{
                if(level != ans) is = false;
            }
            return;
        }
        f(root -> left,is,occ,level + 1);
        f(root -> right,is,occ,level + 1);
    }
    
    bool check(Node *root)
    {
        bool is = true;
        int occ = 0;
        f(root,is,occ,0);
        return is;
    }
};