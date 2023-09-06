class Solution {
public:
    
    int dp[101][101][101];
    
    int go(int i, int j, int k, int n, vector<int> &boxes) {
        if(i == j) return (k + 1) * (k + 1);
        if(i > j) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int temp_i = i, temp_k = k;
        while(i + 1 <= j and boxes[i + 1] == boxes[i]) {
            i ++; k ++;
        }
        int ans = (k + 1) * (k + 1) + go(i + 1, j, 0, n, boxes);
        for(int m = i + 1; m <= j; m ++) {
            if(boxes[i] == boxes[m]) {
                ans = max(ans, go(i + 1, m - 1, 0, n, boxes) + go(m, j, k + 1, n, boxes));
            }
        }
        return dp[temp_i][j][temp_k] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, -1, sizeof(dp));
        return go(0, n - 1, 0, n, boxes);
    }
};

/*
1. so basically, here we used the concept of non self contained subproblems where the solution to a
subproblem depends on the information from the previous sub problem. 

2. so here we first use the optimization that we will consider the whole group collectively as it is
always beneficial that picking up in parts.

3. then we can either delete this group or we can try to merge this group with some other same color box
in the future.

*/