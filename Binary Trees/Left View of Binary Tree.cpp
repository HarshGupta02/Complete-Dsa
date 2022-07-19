// Approach 1 :

vector<int> leftView(Node *root)
{
    vector<int>ans;
    if(root == NULL) return ans;
    int level = 1;
    queue<pair<Node*,int>>q;
    q.push({root,level});
    bitset<105>visited;
    while(!q.empty()){
        Node* parent = q.front().first;
        int par_level = q.front().second;
        if(!visited[par_level]){
            visited[par_level] = 1; ans.push_back(parent -> data);
        }
        q.pop();
        if(parent -> left != NULL) q.push({parent -> left , par_level + 1});
        if(parent -> right != NULL) q.push({parent -> right , par_level + 1});
    }
    return ans;
}

// Approach 2 : 

void f(Node* root , int level , vector<int> &ans){
    if(root == NULL) return ;
    if(level == (int)ans.size()) ans.push_back(root -> data);
    f(root -> left,level + 1, ans);
    f(root -> right,level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int>ans;
    f(root,0,ans);
    return ans;
}