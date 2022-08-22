// TIME = O(N) USING BUCKET SORT.

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<vector<char>>count(n + 1);
        unordered_map<char,int>mp;
        for(auto ch : s) mp[ch] ++;
        for(auto it : mp) count[it.second].push_back(it.first);
        string ans = "";
        for(int i = n; i >= 1; i --){
            if(count[i].empty()) continue;
            for(auto ch : count[i]){
                int cnt = i;
                while(cnt --) ans.push_back(ch);
            }
        }
        return ans;
    }
};