class Solution
{
    public:
    string rearrangeString(string str)
    {
        vector<int>freq(26,0);
        int n = str.size();
        for(int i = 0; i < n ; i ++){
            freq[str[i] - 'a'] ++;
        }
        int nax = -1;
        char ch;
        for(int i = 0; i < 26; i ++){
            if(freq[i] > nax){
                nax = freq[i];
                ch = 'a' + i;
            }
        }
        if(nax > (n + 1)/2) return "-1";
        string ans(n , ' ');
        int idx = 0;
        while(nax --){
            ans[idx] = ch;
            idx += 2;
        }
        freq[ch - 'a'] = 0;
        for(int i = 0; i < 26 ;i ++){
            while(freq[i] --){
                idx = (idx >= n) ? 1 : idx;
                ans[idx] = 'a' + i;
                idx += 2;
            }
        }
        return ans;
    }
};