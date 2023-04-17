class TreeAncestor {
public:
    vector<vector<int>> dp;
    static const int LOG = 20;
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(LOG, vector<int> (n, -1));
        for(int i = 0; i < n; i ++) dp[0][i] = parent[i];
        for(int i = 1; i < LOG; i ++) {
            for(int j = 0; j < n; j ++) {
                int above_par = dp[i - 1][j];
                if(above_par != -1) dp[i][j] = dp[i - 1][above_par];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < LOG; i ++) {
            if(k & (1 << i)) {
                node = dp[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */