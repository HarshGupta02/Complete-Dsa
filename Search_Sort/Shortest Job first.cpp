class Solution {
  public:
    using ll = long long int;
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        ll t = 0, ans = 0;
        for(int i = 0; i < n; i ++) {
            t += bt[i];
            ans += (t - bt[i]);
        }
        return ans/n;
    }
};