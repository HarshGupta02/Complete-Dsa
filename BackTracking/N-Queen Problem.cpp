/// METHOD 1: TIME = O(N ^ N + (N ^ N) * 3 * N) , SPACE = O(N ^ 2).

/*
here we try to fill the queens col wise, with one queen in each col and then
checking for each row within that col. and we check only three directions for 
safety.
*/

class Solution{
public:

    bool isSafe(vector<vector<char>>& grid, int n, int rows, int cols){
        int curr_x = rows, curr_y = cols;
        // left-upper-diagonal
        while(rows >= 0 and cols >= 0){
            if(grid[rows][cols] == 'Q') return false;
            rows --; cols --;
        }
        // left row
        rows = curr_x; cols = curr_y;
        while(cols >= 0){
            if(grid[rows][cols] == 'Q') return false;
            cols --;
        }
        // left-lower-diagonal
        rows = curr_x; cols = curr_y;
        while(rows < n and cols >= 0){
            if(grid[rows][cols] == 'Q') return false;
            rows ++; cols --;
        }
        return true;
    }

    void f(int col, vector<vector<char>> &grid, vector<vector<int>> &ans, int n){
        if(col == n){
            vector<int>curr;
            for(int j = 0; j < n ; j ++){
                for(int i = 0; i < n ; i ++){
                    if(grid[i][j] == 'Q') curr.push_back(i + 1);
                }
            }
            ans.push_back(curr);
            return;
        }
        for(int rows = 0; rows < n ; rows ++){
            if(isSafe(grid, n, rows, col)){
                grid[rows][col] = 'Q';
                f(col + 1, grid, ans, n);
                grid[rows][col] = '#';
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<char>>grid(n,vector<char>(n,'#'));
        f(0,grid,ans,n);
        return ans;
    }
};

// METHOD 2: TIME = O(N ^ N) , SPACE = O(N ^ 2 + N + 2 * N - 1 + 2 * N - 1) ~ O(N ^ N).

/*
here we have hashed the left_row, upper_left_diagonal and lower_left_diagonal
whenever we insert a queen at a given cell. and when we insert a queen at given cell
then thje hashed values of all the three vectors should be 0;
*/

class Solution{
public:

    void f(int col, vector<vector<char>> &grid, vector<vector<int>> &ans, int n, vector<int> &left_row, vector<int> &left_upper, vector<int> &left_lower){
        if(col == n){
            vector<int>curr;
            for(int j = 0; j < n ; j ++){
                for(int i = 0; i < n ; i ++){
                    if(grid[i][j] == 'Q') curr.push_back(i + 1);
                }
            }
            ans.push_back(curr);
            return;
        }
        for(int rows = 0; rows < n ; rows ++){
            if(left_row[rows] == 0 and left_lower[rows + col] == 0 and left_upper[n - 1 + col - rows] == 0){
                grid[rows][col] = 'Q';
                left_row[rows] = left_lower[rows + col] = left_upper[n - 1 + col - rows] = 1;
                f(col + 1, grid, ans, n, left_row, left_upper, left_lower);
                grid[rows][col] = '#';
                left_row[rows] = left_lower[rows + col] = left_upper[n - 1 + col - rows] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<char>>grid(n,vector<char>(n,'#'));
        vector<int>left_row(n,0), left_upper(2 * n - 1, 0), left_lower(2 * n - 1, 0);
        f(0, grid, ans, n, left_row, left_upper, left_lower);
        return ans;
    }
};