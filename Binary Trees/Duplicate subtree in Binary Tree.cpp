/*
Here we use the prop that if there are duplicate subtrees then its traversal order 
will be same. and we return a delimiter in case of a null node as there can be 
same order of nodes for non duplicate subtrees.

*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    unordered_map<string,int>mp;
    
    string f(Node* root){
        if(root == NULL) return "$";
        string s = "";
        if(root -> left == NULL and root -> right == NULL){
            s += to_string(root -> data);
            return s;
        }
        s += f(root -> left) + to_string(root -> data) + f(root -> right);
        mp[s] ++;
        return s;
    }
    
    int dupSub(Node *root) {
        string curr = f(root);
        for(auto it : mp) if(it.second >= 2) return 1;
        return 0;
    }
};