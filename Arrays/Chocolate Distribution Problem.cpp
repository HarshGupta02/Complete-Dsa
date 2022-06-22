class Solution{
    public:
    using ll = long long int;
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin() , a.end());
        ll mini = 1e18;
        for(int i = 0 ; i + m - 1 < n ; i ++){
            mini = min(mini , a[i + m - 1] - a[i]);
        }
        return mini;
    }   
};