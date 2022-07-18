class Solution{
    public:
    //Function to find the height of a binary tree.
    
    void f(struct Node* node , int &curr , int &ans){
        if(node == NULL){
            ans = max(ans, curr);
            return;
        }
        curr ++;
        f(node -> left,curr,ans);
        f(node -> right,curr,ans);
        curr --;
    }
    
    int height(struct Node* node){
        int curr = 0 , ans = 0;
        f(node , curr, ans);
        return ans;
    }
};