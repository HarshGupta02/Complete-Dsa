class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n = s.size(), m = p.size();
        if(n < m) return {};
        vector<int>vn(26, 0), vg(26, 0);
        for(int i = 0; i < m; i ++) vn[p[i] - 'a'] ++;
        for(int i = 0; i < m; i ++) vg[s[i] - 'a'] ++;
        int left = 0, right = m - 1;
        while(left < n and right < n){
            if(vg == vn) ans.push_back(left);
            vg[s[left] - 'a'] --;
            left ++; right ++;
            if(right < n) vg[s[right] - 'a'] ++;
        }
        return ans;
    }
};