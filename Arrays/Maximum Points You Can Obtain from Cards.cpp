class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = n - k;
        int curr = 0;
        for(int i = r; i < n; i ++) curr += cardPoints[i];
        int ans = curr;
        while(r < n) {
            curr = curr - cardPoints[r] + cardPoints[l];
            ans = max(ans, curr);
            r ++; l ++;
        }
        return ans;
    }
};

/*

so we choose some elements from the left and some elements from 
the right so we maintain a sliding window of size n - k and keep
on sliding it to the right starting from the left. in this way, 
we will have some subset of left and right as cards picked.

*/