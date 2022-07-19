class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void mirror(Node* &node) {
        if(node == NULL) return;
        Node* p1 = node -> left , *p2 = node -> right;
        node -> left = p2; node -> right = p1;
        mirror(node -> left);
        mirror(node -> right);
    }
    
    vector<int> rightView(Node *root)
    {
        mirror(root);
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
};