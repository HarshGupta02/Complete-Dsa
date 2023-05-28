/*
so in this problem we try to first sort the cuts array so that if we decide to consider the
ith cut then the left and the right subproblem will never collide and the toal cost will be 
the current length of the rod plus the cost of left subproblem and the cost of the right
subproblem.

since on taking the ith cut, we recursively call the i-1 th and the i+1 th cut so we have
to consider the lenght of the remaining cuts on the left and the right half.

*/

class Solution {
public:
    
    static const int MAXN = 105;
    int dp[MAXN][MAXN];
    
    int f(int i, int j, vector<int> &cuts) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int idx = i; idx <= j; idx ++) {
            ans = min(ans, cuts[j + 1] - cuts[i - 1] + f(i, idx - 1, cuts) + f(idx + 1, j, cuts));
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        memset(dp, -1, sizeof(dp));
        return f(1, m, cuts);
    }
};
