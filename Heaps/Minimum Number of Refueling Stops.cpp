/*
TIME = O(N * LOGN), SPACE = O(N)

here we first see that if we don't use any station so we can reach a max distance
of "start fuel". if this dist >= target so ans = 0. 

but if not so we need more fuel. the max distance that we have travelled would have
surpassed some stations so we can reach them use their fuel to go farther distance
than the current max distance. so since we want the min stops so we take the gas
of the station with the max gas.

this ensures that we reach curr_max + (max_gas). we could have also choosen more than
one gas station but there is no need as we could choose that second station or 
someone better in the next chance.

*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int max_reach = startFuel;
        int ans = 0;
        priority_queue<int>pq;
        int i = 0;
        while(max_reach < target){
            while(i < n and stations[i][0] <= max_reach) pq.push(stations[i ++][1]);
            if(pq.empty()) return -1;
            max_reach += pq.top(); pq.pop();
            ans ++;
        }
        return ans;
    }
};