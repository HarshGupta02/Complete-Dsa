/*
Here we have serialised each subtree of the given tree . first add the curr value
separated by a wildcard char , then the left string , followed by wildcard char and 
them the right string.
*/

class Solution {
public:
    
    unordered_map<string,pair<int,TreeNode*>>mp;

    string f(TreeNode* root){
        if(root == NULL) return "$";
        string curr = "";
        if(root -> left == NULL and root -> right == NULL){
            curr = to_string(root -> val);
            mp[curr].first ++;  mp[curr].second = root;
            return curr;
        }
        curr += to_string(root -> val) + "@" +f(root -> left) + "%" + f(root -> right);
        mp[curr].first ++;  mp[curr].second = root;
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        f(root);
        for(auto it : mp){
            if(it.second.first >= 2) ans.push_back(it.second.second);
        }
        return ans;
    }
};