class Solution {
public:
    
    using ll = long long int;
    
    bool check(ll mid, vector<int> &d, int m, int k, int n){
        ll together = 0, made = 0;
        for(int i = 0; i < n ; i ++){
            if(mid >= d[i]){
                together ++;
            }else{
                made += together/k;
                together = 0;
            }
        }
        made += together/k;
        if(made >= m) return true;
        return false;
    }
    
    int minDays(vector<int>& d, int m, int k) {
        int n = d.size();
        ll nax = *max_element(d.begin(), d.end());
        ll low = 1, high = nax;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(check(mid, d, m, k, n)){
                ans = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

/// can apply binary search on number of days to wait.

/*
let's say we wait for x days so can we make m bouquets in  x days
*/