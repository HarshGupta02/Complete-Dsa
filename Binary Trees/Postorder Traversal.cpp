/// recursive :

void f(Node* root , vector<int> &ans){
    if(root == NULL) return;
    f(root -> left,ans);
    f(root -> right,ans);
    ans.push_back(root -> data);
}

vector <int> postOrder(Node* root)
{
    vector<int>ans;
    f(root,ans);
    return ans;
}


/// iterative :

