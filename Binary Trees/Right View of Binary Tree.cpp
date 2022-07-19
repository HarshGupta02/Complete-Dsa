/// Approach 1: find the mirror image of the tree and view from left side which
// is equivalent to viewing original tree from right tree.

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

// Approach 2: here we traverse the tree at each level in opp direction that is
// first go to right side and then to the left side.

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    vector<int> rightView(Node *root)
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
            if(parent -> right != NULL) q.push({parent -> right , par_level + 1});
            if(parent -> left != NULL) q.push({parent -> left , par_level + 1});
        }
        return ans;
    }
};

// problem with this approach is that it is storing all the nodes which is takes a
// SC of O(N).

// Approach 3 : so here the size of vector tells the max number of levels traversed.

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void f(Node* root , int level,vector<int> &ans){
        if(root == NULL) return;
        if((int)ans.size() == level) ans.push_back(root -> data);
        f(root -> right,level + 1,ans);
        f(root -> left,level + 1,ans);
    }
    
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        f(root,0,ans);
        return ans;
    }
};