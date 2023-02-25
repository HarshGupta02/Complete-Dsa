/*
so here we first sort the projects in ascending order of the capital and we keep on
pushing all those projects that have capital less than w. after selecting all 
such projects, we choose the project which has max profit and they are guranteed to
have capital less than w.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i ++){
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int i = 0;
        while(k --){
            while(i < n and v[i].first <= w){
                pq.push(v[i].second);
                i ++;
            }
            if(pq.empty()) break;
            w += pq.top(); pq.pop();
        }
        return w;
    }
};

/*

1. so first we should sort the capital in ascending order and if same capital so sort the
profits in decreasing order. (greedy but may be wrong).

2. always choose that project that has min capital and max profit.

{capital, profit}
[{0,1}, {1,3}, {1,2}]

*/