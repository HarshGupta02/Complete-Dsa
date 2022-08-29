class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int excess = 0, req = 0, start = 0;
        for(int i = 0; i < n; i ++){
            excess = (excess + gas[i] - cost[i]);
            if(excess < 0){
                start = i + 1;
                req += excess;
                excess = 0;
            }
        }
        if(excess + req < 0) return -1;
        return start;
    }
};