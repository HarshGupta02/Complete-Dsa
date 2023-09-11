/*
so here we see the contribution of each character from 1 to 26 (A to Z). 
we see on the left and on the right, the first occurence of that character
on the left and right and multiply the size of the two arrays on the left
and the right.
*/


class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> mp(26);
        for(int i = 0; i < 26; i ++) mp[i].push_back(-1);
        for(int i = 0; i < n; i ++) mp[s[i] - 'A'].push_back(i);
        for(int i = 0; i < 26; i ++) mp[i].push_back(n);
        int ans = 0;
        for(int i = 0; i < 26; i ++) {
            for(int j = 1; j < mp[i].size() - 1; j ++) {
                ans += (mp[i][j] - mp[i][j - 1]) * (mp[i][j + 1] - mp[i][j]);
            }
        }
        return ans;
    }
};