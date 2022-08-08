// TIME = O(9 ^ (N * N)) , SPACE = O(N * N)

class Solution {
public:
    
    bool isSafe(int x, int y, char c, vector<vector<char>> &board){
        for(int i = 0; i < 9; i ++){
            if(board[x][i] == c) return false;
            if(board[i][y] == c) return false;
            if(board[3 * (x/3) + i/3][3 * (y/3) + i % 3] == c) return false;
        }
        return true;
    }
    
    bool f(vector<vector<char>>& board){
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; k ++){
                        if(isSafe(i, j, k, board)){
                            board[i][j] = k;
                            if(f(board) == true){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        // this ensures that when neither of cell is empty so it is true always.
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};