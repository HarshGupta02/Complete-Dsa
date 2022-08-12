// METHOD 1:

class Solution {
public:

    TreeNode* lca(TreeNode* root ,int n1 ,int n2 ){
        if(root == NULL or root -> val == n1 or root -> val == n2) return root;
        TreeNode* left_node = lca(root -> left,n1,n2);
        TreeNode* right_node = lca(root -> right,n1,n2);
        if(left_node == NULL and right_node == NULL) return NULL;
        if(left_node == NULL) return right_node;
        if(right_node == NULL) return left_node;
        return root;
    }

    void dfs(TreeNode* root, int lvl, vector<int> &depth){
        if(root == NULL) return;
        depth[root -> val] = lvl;
        dfs(root -> left, lvl + 1, depth);
        dfs(root -> right, lvl + 1, depth);
    }

    void dfs_1(TreeNode* head, TreeNode* root, vector<int> &depth, TreeNode* target, int k, vector<int> &ans){
        if(root == NULL) return;
        int lcaa = lca(head, target -> val, root -> val) -> val;
        int gap = depth[target -> val] + depth[root -> val] - (2 * depth[lcaa]);
        if(gap == k) ans.push_back(root -> val);
        dfs_1(head, root -> left, depth, target, k, ans);
        dfs_1(head, root -> right, depth, target, k, ans);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        vector<int>depth(505, 0); 
        int lvl = 0;
        dfs(root, lvl, depth);
        TreeNode* head = root;
        dfs_1(head, root, depth, target, k, ans);
        return ans;
    }
};


// METHOD 2: 

/*
basically the binary tree is converted into an undirected graph by storing the parent of every
child. and then performing single source bfs from the target.

*/

class Solution {
public:
    
    void dfs(TreeNode* root, TreeNode* target, int k, map<TreeNode*, TreeNode* > &parent, TreeNode* par){
        if(root == NULL) return;
        parent[root] = par;
        dfs(root -> left, target, k, parent, root);
        dfs(root -> right, target, k, parent, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* ,TreeNode*>parent;
        map<TreeNode*,bool>seen;
        seen[target] = true;
        dfs(root, target, k, parent, root);
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(target);
        int lvl = 0;
        while(!q.empty()){
            if(lvl == k) break;
            lvl ++;
            int sz = q.size();
            for(int i = 0; i < sz; i ++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left != NULL and !seen[curr -> left]){
                    q.push(curr -> left);
                    seen[curr -> left] = true;
                }
                if(curr -> right != NULL and !seen[curr -> right]){
                    q.push(curr -> right);
                    seen[curr -> right] = true;
                }
                if(parent[curr] != NULL and !seen[parent[curr]]){
                    q.push(parent[curr]);
                    seen[parent[curr]] = true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};
