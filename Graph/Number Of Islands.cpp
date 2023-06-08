// M1:

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 1);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    
    int get_parent(int a) {
        return (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);
        if(rank[b] < rank[a]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {
            rank[a] ++;
            parent[b] = a;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        int k = op.size();
        DSU dsu(k);
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1; i < k; i ++) {
            for(int j = 0; j < i; j ++) {
                int xi = op[i][0], yi = op[i][1];
                int xj = op[j][0], yj = op[j][1];
                if(abs(xi - xj) >= 2 or abs(yi - yj) >= 2) continue;
                if(abs(xi - xj) == 1 and abs(yi - yj) == 1) continue;
                if(dsu.get_parent(i) == dsu.get_parent(j)) continue;
                dsu.mergee(i, j);
            }
            int comp = 0;
            for(int j = 0; j <= i; j ++) {
                if(dsu.parent[j] == j) comp ++;
            }
            ans.push_back(comp);
        }
        return ans;
    }
};

// M2:

/*
in this method, we basically we consider each cell as a node in dsu and change indices
and on any island, we increase count by 1. then check for all its 4 neighbours. if
not seen then continue. else if both have different parent then merge them and 
decrease count by 1.
*/

class DSU{
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n); rank.resize(n, 1);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    
    int get_parent(int a) {
        return (parent[a] == a ? a : get_parent(parent[a]));
    }
    
    void mergee(int a, int b) {
        a = get_parent(a);
        b = get_parent(b);
        if(rank[b] < rank[a]) parent[b] = a;
        else if(rank[a] < rank[b]) parent[a] = b;
        else {
            rank[a] ++;
            parent[b] = a;
        }
    }
};

class Solution {
  public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        int k = op.size();
        vector<vector<bool>> seen(n, vector<bool> (m, false));
        DSU dsu(n * m);
        vector<int> ans;
        int cnt = 0;
        for(auto it : op) {
            int curr_node = it[0] * m + it[1];
            if(seen[it[0]][it[1]]) {
                ans.push_back(cnt);
                continue;
            }
            seen[it[0]][it[1]] = true;
            cnt ++;
            for(int k = 0; k < 4; k ++) {
                int new_x = it[0] + dx[k], new_y = it[1] + dy[k];
                if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and seen[new_x][new_y]) {
                    int new_node = new_x * m + new_y;
                    if(dsu.get_parent(curr_node) != dsu.get_parent(new_node)) {
                        dsu.mergee(curr_node, new_node);
                        cnt --;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};