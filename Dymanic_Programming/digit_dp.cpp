class Solution {
public:
    
    string subtractOne(string s) {
        int n = s.size();
        int i = n - 1;
        while(i >= 0 and s[i] == '0') {
            s[i] = '9';
            i --;
        }
        s[i] --;
        return s;
    }
    
    int dp[10][21][11][11][2][2];
    
    int go(int i, int prev_rem, int even, int odd, int is_smaller, int is_started, int k, int n, string s) {
        if(i >= n) return (even == odd and even != 0 and prev_rem == 0);
        if(dp[i][prev_rem][even][odd][is_smaller][is_started] != -1) return dp[i][prev_rem][even][odd][is_smaller][is_started];
        int end = is_smaller ? 9 : s[i] - '0';
        int ans = 0;
        for(int j = 0; j <= end; j ++) {
            int new_is_started = is_started ? 1 : (j != 0);
            int new_is_smaller = is_smaller ? 1 : (j != (s[i] - '0'));
            int new_prev_rem = ((10 * prev_rem) + j) % k;
            int new_even = ((j % 2 == 0 and j != 0) or (j == 0 and is_started)) ? even + 1 : even;
            int new_odd = ((j % 2) != 0) ? odd + 1 : odd;
            ans = (ans + go(i + 1, new_prev_rem, new_even, new_odd, new_is_smaller, new_is_started, k, n, s));
        }
        return dp[i][prev_rem][even][odd][is_smaller][is_started] = ans;
    }
    
    int numberOfBeautifulIntegers(int left, int right, int k) {
        string low = to_string(left), high = to_string(right);
        int n = low.size(), m = high.size();
        low = subtractOne(low);
        int is_smaller = 0, prev_rem = 0, even = 0, odd = 0, is_started = 0;
        memset(dp, -1, sizeof(dp));
        int a = go(0, prev_rem, even, odd, is_smaller, is_started, k, n, low);
        memset(dp, -1, sizeof(dp));
        int b = go(0, prev_rem, even, odd, is_smaller, is_started, k, m, high);
        return b - a;
    }
};