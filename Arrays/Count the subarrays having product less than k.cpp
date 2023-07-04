class Solution{
  public:
    using ll = long long int;
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(k == 1) return 0;
        ll p = 1, cnt = 0;
        int i = 0, j = 0;
        while(i < n and j < n) {
            p *= a[j];
            while(p >= k) {
                p /= a[i];
                i ++;
            }
            cnt += (j - i) + 1;
            j ++;
        }
        return cnt;
    }
};