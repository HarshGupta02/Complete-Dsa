class Solution {
  public:
    string lexicographicallySmallest(string s, int k) {
        int n = s.size();
        if((n & (n - 1)) == 0) k/=2;
        else k*=2;
        if(k > n) return "-1";
        string ans = "";
        k = n - k; // k denotes the number of characters to remain.
        for(int i = 0; i < n; i ++){
            if(ans.empty()) ans.push_back(s[i]);
            else{
                while(!ans.empty() and ans.back() > s[i] and ((ans.size() - 1) + (n - i)) >= k){
                    ans.pop_back();
                }
                ans.push_back(s[i]);
            }
        }
        while(ans.size() > k) ans.pop_back();
        return (ans.empty() ? "-1" : ans);
    }
};