/*
here we can either select a job or not select the job. if we select a job then we find the 
lower_bound of the job that starts with the current job's end time and then we again decide to 
either accept it or not accept it.
*/

class Solution {
public:
    
    vector<int> dp;
    
    int f(int i, int n, vector<vector<int>> &v, vector<int> &startTime){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int idx = lower_bound(startTime.begin(), startTime.end(), v[i][1]) - startTime.begin();
        int pick = v[i][2] + f(idx, n, v, startTime);
        int not_pick = f(i + 1, n, v, startTime);
        return dp[i] = max(pick, not_pick);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp.resize(n, -1);
        vector<vector<int>> v;
        vector<int> st;
        for(int i = 0; i < n; i ++){
            st.push_back(startTime[i]); // as cannot apply lower_bound on vector of vectors.
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end());
        sort(startTime.begin(), startTime.end());
        return f(0, n, v, startTime);
    }
};