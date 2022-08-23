class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string,int>mp;
        for(auto it : words) mp[it] ++;
        vector<vector<string>>count(n + 1);
        for(auto it : mp) count[it.second].push_back(it.first);
        vector<string>ans;
        for(int i = n; i >= 1; i --){
            if(count[i].empty()) continue;
            for(auto str : count[i]) {
                if(k <= 0) return ans;
                ans.push_back(str);
                k --;
            }
        }
        return ans;
    }
};