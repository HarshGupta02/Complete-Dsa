class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n1 = s.size(), n2 = words.size();
        vector<int>ans;
        if(n1 == 0 or n2 == 0) return ans;
        unordered_map<string,int>mp;
        for(auto it : words) mp[it] ++;
        int len = words[0].size();
        for(int i = 0; i < n1 - (n2 * len) + 1; i ++){ // O(10 ^ 4)
            unordered_map<string,int>seen;
            int j;
            for(j = 0; j < n2; j ++){ // O(5 * 10 ^ 3)
                string curr = s.substr(i + j * len, len); // O(30)
                if(mp.find(curr) != mp.end()){
                    seen[curr] ++;
                    if(seen[curr] > mp[curr]) break;
                }else break;
            }
            if(j == n2) ans.push_back(i); 
        }
        return ans;
    }
};