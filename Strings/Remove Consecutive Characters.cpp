class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        int n = S.size();
        string ans = "";
        ans += S.front();
        for(int i = 1 ; i < n ; i ++){
            if(S[i] == S[i - 1]) continue;
            ans += S[i];
        }
        return ans;
    }
};