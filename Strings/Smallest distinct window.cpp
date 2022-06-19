class Solution{
    public:
    int findSubString(string str)
    {
        int n = str.size();
        unordered_set<char>st;
        unordered_map<char,int>mp;
        for(int i = 0; i < n; i++){
            st.insert(str[i]);
        }
        int unq = st.size();
        unordered_set<char>curr;
        int i = 0, j = 0;
        int ans = INT_MAX;
        while(j < n){
            curr.insert(str[j]);
            mp[str[j]] ++;
            if(curr.size() != unq){
                j ++; continue;
            }
            while(mp[str[i]] != 1){
                mp[str[i]] --;
                i ++;
            }
            ans = min(ans , (j - i) + 1);
            j ++;
        }
        return ans;
    }
};