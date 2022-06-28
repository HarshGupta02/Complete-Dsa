class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        pair<int,int>parent = {intervals[0][0] , intervals[0][1]};
        vector<vector<int>>ans;
        for(int i = 1; i < n ; i ++){
            pair<int,int>curr = {intervals[i][0] , intervals[i][1]};
            if(curr.first <= parent.second){
                parent.second = max(parent.second , curr.second);
            }else{
                vector<int>curr_v = {parent.first , parent.second};
                ans.push_back(curr_v);
                parent = curr;
            }
        }
        vector<int>curr_v = {parent.first , parent.second};
        ans.push_back(curr_v);
        return ans;
    }
};