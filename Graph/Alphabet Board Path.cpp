/* METHOD 1: here we just used a single source bfs for each character of string
to the next character of the string.

TIME = O(26 * N)

*/

class Solution {
public:
    
    vector<string> grid = {{"abcde"}, {"fghij"}, {"klmno"}, {"pqrst"}, {"uvwxy"}, {"z####"}};
    
    array<int, 4> dx = {0, 1, 0, -1};
    array<int, 4> dy = {1, 0, -1, 0};
    array<char, 4> dir = {'R', 'D', 'L', 'U'};
    
    bool isSafe(int x, int y, vector<vector<bool>> &seen){
        return (x >= 0 and x < 6 and y >= 0 and y < 5 and !seen[x][y] and grid[x][y] != '#');
    }
    
    string bfs(char src, char dest){
        vector<vector<bool>> seen(6, vector<bool> (5, false));
        map<char, string> mp;
        int s_x, s_y, d_x, d_y;
        for(int i = 0; i < 6; i ++){
            for(int j = 0; j < 5; j ++){
                if(grid[i][j] == src) { s_x = i; s_y = j; }
                if(grid[i][j] == dest){ d_x = i; d_y = j; }
            }
        }
        queue<pair<int,int>> q;
        q.push({s_x, s_y});
        seen[s_x][s_y] = true;
        while(!q.empty()){
            int curr_x = q.front().first, curr_y = q.front().second;
            q.pop();
            if(curr_x == d_x and curr_y == d_y) return mp[dest];
            for(int k = 0; k < 4; k ++){
                int new_x = curr_x + dx[k], new_y = curr_y + dy[k];
                if(isSafe(new_x, new_y, seen)){
                    mp[grid[new_x][new_y]] = mp[grid[curr_x][curr_y]] + dir[k];
                    seen[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }
        return "-1";
    }
    
    string alphabetBoardPath(string target) {
        target = "a" + target;
        int n = target.size();
        string ans = "";
        for(int i = 0; i < n - 1; i ++){
            ans += bfs(target[i], target[i + 1]) + "!";
        }
        return ans;
    }
};

// METHOD 2:

/*
here no need of bfs because to go from one character to another in the grid, the
minimum path is always gonna be the sum of difference of x coordinates and 
the differences of the y coordinates.

we handle corner case when we need to go from 'z' to some other character as in
our case we would have to go right or left first which would go out of the grid
so we first move up and now we are in the 5 x 5 grid and then perform the 
operations using the manhatten distance.

*/

class Solution {
public:
    
    string alphabetBoardPath(string target) {
        int n = target.size();
        int s_x = 0, s_y = 0;
        map<char, pair<int,int>> mp;
        char ch = 'a';
        for(int i = 0; i < 26; i ++){
            mp[ch] = {i/5, i%5};
            ch ++;
        }
        string ans = "";
        for(int i = 0; i < n; i ++){
            int d_x = mp[target[i]].first, d_y = mp[target[i]].second;
            if(target[i] != 'z' and mp['z'].first == s_x and mp['z'].second == s_y){
                ans.push_back('U');
                s_x --;
            }
            while(s_y != d_y){
                if(s_y < d_y){
                    ans.push_back('R');
                    s_y ++;
                }else{
                    ans.push_back('L');
                    s_y --;
                }
            }
            while(s_x != d_x){
                if(s_x < d_x){
                    ans.push_back('D');
                    s_x ++;
                }else{
                    ans.push_back('U');
                    s_x --;
                }
            }
            ans.push_back('!');
        }
        return ans;
    }
};