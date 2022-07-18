class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int>ans;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* tp = q.front();
            ans.push_back(tp -> data);
            q.pop();
            if(tp -> left != NULL) q.push(tp -> left);
            if(tp -> right != NULL) q.push(tp -> right);
        }
        return ans;
    }
};