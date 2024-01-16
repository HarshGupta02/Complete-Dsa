class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i ++) v.push_back({aliceValues[i], bobValues[i]});
        sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
           return a.first + a.second > b.first + b.second; 
        });
        int alice = 0, bob = 0, chance = 0;
        for(int i = 0; i < n; i ++) {
            if(chance == 0) alice += v[i].first;
            else bob += v[i].second;
            chance = 1 - chance;
        }
        return (alice > bob ? 1 : alice == bob ? 0 : -1);
    }
};

// alice : [2,4,3]
// bob   : [1,6,7]

// alice should choose a stone that has max value for him so that he can pick it up
// and also max value for bob so that bob cannot pick it up.
    
// a : 
// b : 

// a => 6 
// b => 7
    
// alice : [1,2]
// bob   : [3,1]

// a : 
// b : 

// a => 2
// b => 3