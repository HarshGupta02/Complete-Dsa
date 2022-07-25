/// recursive :

void f(Node* root , vector<int> &ans){
    if(root == NULL) return;
    ans.push_back(root -> data);
    f(root -> left,ans);
    f(root -> right,ans);
}

vector <int> preorder(Node* root)
{
    vector<int>ans;
    f(root,ans);
    return ans;
}

/// iterative :

vector <int> preorder(Node* root)
{
    vector<int>ans;
    stack<Node*>stk;
    Node* curr = root;
    while(curr != NULL or !stk.empty()){
        while(curr != NULL){
            stk.push(curr);
            ans.push_back(curr -> data);
            curr = curr -> left;
        }
        curr = stk.top();
        stk.pop();
        curr = curr -> right;
    }
    return ans;
}

// MORRIS TRAVERSAL : TIME : O(N) , SPACE = O(1)

vector <int> preorder(Node* root)
{
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
                ans.push_back(curr -> data);
                curr = curr -> left;
            }else{
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return ans;
}