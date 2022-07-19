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