/// TIME = O(N LOGN) + O(N) ~~ O(N LOGN), SPACE = O(N)

/*

here we sorted all the intervals and by sorting we ensured that if we find an interval not merging with the current interval
then all the intervals after the current interval will never merge so our current interval should be inserted into the ans
vector.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        pair<int,int>p = {intervals[0][0] , intervals[0][1]};
        for(int i = 0 ;i < n ; i ++){
            pair<int,int>curr = {intervals[i][0] , intervals[i][1]};
            if(curr.first <= p.second){
                p.second = max(p.second , curr.second);
            }else{
                vector<int>q; q.push_back(p.first); q.push_back(p.second);
                ans.push_back(q);
                p = curr;
            }
        }
        vector<int>q; q.push_back(p.first); q.push_back(p.second);
        ans.push_back(q);
        return ans;
    }
};