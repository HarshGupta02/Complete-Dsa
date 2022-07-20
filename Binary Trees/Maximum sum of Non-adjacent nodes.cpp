class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    
    unordered_map<Node*,pair<int,int>>mp;
    
    void f(Node* root){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL){
            mp[root].first = root -> data; mp[root].second = 0;
            return;
        }
        
        f(root -> left);
        f(root -> right);
        
        if(root -> right == NULL){
            mp[root].first = root -> data + mp[root -> left].second;
            mp[root].second =  max(mp[root -> left].first,mp[root -> left].second);
            return;
        }
        
        if(root -> left == NULL){
            mp[root].first = root -> data + mp[root -> right].second;
            mp[root].second =  max(mp[root -> right].first,mp[root -> right].second);
            return;
        }
        
        mp[root].first = root -> data + mp[root -> left].second + mp[root -> right].second;
        mp[root].second = max(mp[root -> left].first,mp[root -> left].second) + 
        max(mp[root -> right].first,mp[root -> right].second);
    }
    
    int getMaxSum(Node *root) 
    {
        f(root);
        return max(mp[root].first,mp[root].second);
    }
};