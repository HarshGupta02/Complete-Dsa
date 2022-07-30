// TIME = O(3 ^ (N ^ 2)) , SPACE = O(N ^ 2 + L) , WHERE  L = LENGTH OF PATH.

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

char dir[4] = {'L','U','R','D'};

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<bool>>& visited){
        return (x >= 0 and y >= 0 and x < n and y < n and m[x][y] != 0 and !visited[x][y]);
    }
    
    void f(vector<vector<int>> &m, int n , vector<string>& ans, int x, int y, vector<vector<bool>>& visited,string &temp){
        if(x == n - 1 and y == n - 1){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < 4; i ++){
            int curr_x = x + dx[i], curr_y = y + dy[i];
            if(isSafe(m, n, curr_x, curr_y, visited)){
                visited[x][y] = true;
                temp.push_back(dir[i]);
                f(m, n, ans, curr_x, curr_y, visited,temp);
                temp.pop_back();
                visited[x][y] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!(m[0][0] and m[n - 1][n - 1])){
            vector<string>curr; curr.push_back("-1"); return curr;
        }
        vector<string>ans;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        string temp = "";
        f(m,n,ans,0,0,visited,temp);
        return ans;
    }
};