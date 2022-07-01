class Solution{
    public:
    int removals(vector<int>& a, int k){
        int n = a.size();
        sort(a.begin() , a.end());
        if(a.back() - a.front() <= k) return 0;
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i ++){
            int A_min = a[i];
            int A_max = k + A_min; /// a_max <= k + a_min
            auto it = upper_bound(a.begin(),a.end(),A_max);
            int idx;
            if(it != a.end()){
                it --; idx = it - a.begin();
                ans = min(ans , i + (n - 1 - idx));
            }else{
                ans = min(ans , i);
            }
        }
        return ans;
    }
};