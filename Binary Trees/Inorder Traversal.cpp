// Recursive : TIME = O(N) , SPACE = O(HEIGHT OF TREE)

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

// Iterative : TIME = O(N) , SPACE = O(HEIGHT OF TREE)

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

/// MORRIS TRAVERSAL : TIME = O(N) , SPACE = O(1)

/*
here we know that we reach the data of the root after visiting the rightmost node
of the left subtree and so if we don't have a connection so we first 
establish it and then curr goes to left and if there is already a connection
then we first break the connection and then go right.
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        Node* curr = root;
        while(curr != NULL){
            if(curr -> left == NULL){
                ans.push_back(curr -> data);
                curr = curr -> right;
            }else{
                Node* prev = curr -> left;
                while(prev -> right != NULL and prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == NULL){
                    prev -> right = curr;
                    curr = curr -> left;
                }else{
                    prev -> right = NULL;
                    ans.push_back(curr -> data);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};