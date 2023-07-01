/*
M1 : ALWAYS TRUE => if alice starts first then alice will always win because the sum of
stones is odd so alice can pick all the odd indexed stones or all the even indexed stones
depending on whose sum is bigger(they cannot be equal as sum of all stones is odd).

also if alice picks up any indexed stone so it will have the same parity stones to pick 
in the next turns.
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        for(auto it : piles) sum += it;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int gap = 0; gap < n; gap ++) {
            for(int i = 0, j = gap; i < n and j < n; i ++, j ++) {
                if(gap == 0) dp[i][j] = piles[i];
                else if(gap == 1) dp[i][j] = max(piles[i], piles[j]);
                else dp[i][j] = max(piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
        int alice_score = dp[0][n - 1], bob_score = sum - dp[0][n - 1];
        return alice_score > bob_score;
    }
};