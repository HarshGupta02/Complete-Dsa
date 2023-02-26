/*
here we use modified dijkstra and d[i][j] = tells the min time to reach (i,j) from
(0, 0). if our reach time is less than the grid value so we have to wait for that 
many seconds and we wait by oscillating back and forth from where we just came or
with the parent and then we reach a new node. if new_time < d[i][j] so update
d[i][j] = new_time.

*/

struct Edge{
    int timee, x, y;
    Edge(int timee, int x, int y){
        this -> timee = timee;
        this -> x = x;
        this -> y = y;
    }
};

struct cmp {
    bool operator()(Edge const& e1, Edge const& e2){
        return e1.timee > e2.timee;
    }
};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool isSafe(int x, int y, int n, int m) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        vector<vector<int>> d(n, vector<int> (m, 1e9));
        d[0][0] = 0;
        priority_queue<Edge, vector<Edge>, cmp> q;
        q.push(Edge(0, 0, 0));
        while(!q.empty()){
            int curr_time = q.top().timee, curr_x = q.top().x, curr_y = q.top().y;
            q.pop();
            for(int k = 0; k < 4; k ++){
                int new_x = curr_x + dx[k], new_y = curr_y + dy[k];
                if(!isSafe(new_x, new_y, n, m)) continue;
                int wait = max(0, grid[new_x][new_y] - curr_time - 1);
                if(wait % 2 == 1) wait ++;
                int new_time = curr_time + wait + 1;
                if(new_time < d[new_x][new_y]){
                    d[new_x][new_y] = new_time;
                    q.push(Edge(d[new_x][new_y], new_x, new_y));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};