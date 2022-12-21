class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1) return false;
        vector<int> lps(n, 0);
        int i = 1, len = 0;
        while(i < n){
            if(s[i] == s[len]){
                len ++;
                lps[i] = len;
                i ++;
            }else{
                if(len > 0) len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i ++;
                }
            }
        }
        int l = lps[n - 1];
        return (l != 0 and l % (n - l) == 0 ? true : false);
    }
};