// Recursive :

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    
    void f(Node* root , vector<int> &ans){
        if(root == NULL) return;
        f(root -> left,ans);
        ans.push_back(root -> data);
        f(root -> right,ans);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        f(root,ans);
        return ans;
    }
};

// Iterative :

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        stack<Node*>stk;
        vector<int>ans;
        Node* curr = root;
        while(curr != NULL or !stk.empty()){
            while(curr != NULL){
                stk.push(curr);
                curr = curr -> left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        return ans;
    }
};