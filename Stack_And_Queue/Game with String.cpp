class Solution{
using ll = long long int;
public:
    int minValue(string s, int k){
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i = 0; i < n ; i ++) mp[s[i]] ++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second , it.first});
        }
        while(k --){
            auto p = pq.top();
            pq.pop();
            p.first --;
            pq.push(p);
        }
        ll ans = 0;
        while(!pq.empty()){
            ans += pq.top().first * pq.top().first;
            pq.pop();
        }
        return ans;
    }
};