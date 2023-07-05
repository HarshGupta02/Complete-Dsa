class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int n = cards.size();
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i ++) {
            if(mp.find(cards[i]) != mp.end()) ans = min(ans, i - mp[cards[i]] + 1);
            mp[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
        
        // why not working ??
        // int n = cards.size();
        // unordered_map<int, int> mp;
        // int i = 0, j = 0;
        // int ans = INT_MAX;
        // while(i < n and j < n) {
        //     mp[cards[j]] ++;
        //     while(i < n and i < j and mp[cards[j]] > 1) {
        //         ans = min(ans, (j - i) + 1);
        //         if(cards[i] == cards[j]) mp[cards[i]] --;
        //         i ++;
        //     }
        //     j ++;
        // }
        // return ans == INT_MAX ? -1 : ans;
    }
};