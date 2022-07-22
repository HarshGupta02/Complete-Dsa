class Solution {
public:
    
    vector<int>ans;
    
    void f_left(Node* root){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL) return;
        ans.push_back(root -> data);
        if(root -> left != NULL) f_left(root -> left);
        else if(root -> right != NULL) f_left(root -> right);
        else return;
    }
    
    void f_bottom(Node* root){
        if(root == NULL) return;
        if(root -> left == NULL and root -> right == NULL){
            ans.push_back(root -> data);
            return;
        }
        f_bottom(root -> left);
        f_bottom(root -> right);
    }
    
    void f_right(Node* root){
        if(root == NULL) return;
        if(root -> right != NULL) f_right(root -> right);
        else if(root -> left != NULL) f_right(root -> left);
        else return;
        ans.push_back(root -> data);
    }
    
    vector <int> boundary(Node *root)
    {
        if(root == NULL) return ans;
        if(root -> left == NULL and root -> right == NULL) return {root -> data};
        ans.push_back(root -> data);
        f_left(root -> left);
        f_bottom(root);
        f_right(root -> right);
        return ans;
    }
};