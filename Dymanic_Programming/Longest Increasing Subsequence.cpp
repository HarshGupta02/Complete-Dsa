/// TIME = O(N * LOGN) , SPACE = O(2 * N) ~ O(N)

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>ans;
        vector<int>arr; for(int i = 0; i < n ; i ++) arr.push_back(a[i]);
        int cnt = 0;
        for(int i = 0; i < n ; i ++){
            if(ans.empty() or arr[i] > ans.back()){
                ans.push_back(arr[i]);
                cnt ++;
            }
            else{
                int idx = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }
        return ans.size();
    }
};