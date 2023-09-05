/*
it uses the concept of BFS + Priority Queue. it is used because, we can keep track of the previous
cells also and expand them accordingly.

*/

using vi = vector<int>;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

class cmp{
public:
    bool operator()(const vi &a, const vi &b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size(), sz = queries.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < sz; i ++) v.push_back({queries[i], i});
        sort(v.begin(), v.end());
        vector<int> ans(sz);
        priority_queue<vi, vector<vi>, cmp> pq;
        vector<vector<bool>> seen(n, vector<bool> (m, false));
        pq.push({grid[0][0], 0, 0});
        seen[0][0] = true;
        int cnt = 0;
        for(int i = 0; i < sz; i ++) {
            int q = v[i].first, idx = v[i].second;
            while(!pq.empty() and q > pq.top()[0]) {
                cnt ++;
                int cx = pq.top()[1], cy = pq.top()[2]; pq.pop();
                for(int k = 0; k < 4; k ++) {
                    int nx = cx + dx[k], ny = cy + dy[k];
                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and !seen[nx][ny]) {
                        pq.push({grid[nx][ny], nx, ny});
                        seen[nx][ny] = true;
                    }
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
};