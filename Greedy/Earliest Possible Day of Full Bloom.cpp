/*
1. plant the higher plant times when the growth time of other plants
is happening.
2. sort the pairs on the basis of plant time.

p = [1,2,2,3] 
g = [2,1,1,2]

3. sum of all the plant times is the min time for the bloom and the
ans will always be greater than the curr sum because of the growth and the bloom.

4. since we have to plant exactly one seed on each day so the plant time
never matters, whether we perform earlier or later. it will take the same 
total number of days for plantation. so it comes down to the growth time.

5. so we plant those seed first that have higher growth time because in 
that time, other seeds can be planted. but if we do the opposite that is
plant the higher growth times later then it is possible that days are not
fully utilised and the plant is just growing and no other plantation is
happening at that time.

*/

class Solution {
public:
    
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second > p2.second;
    }
    
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n = plant.size();
        vector<pair<int,int>>v;
        for(int i = 0; i < n; i ++){
            v.push_back({plant[i], grow[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0, plant_time = 0;
        for(int i = 0; i < n; i ++){
            plant_time += v[i].first;
            ans = max(ans, plant_time + v[i].second);
        }
        return ans;
    }
};