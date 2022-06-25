class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>a;
        for(int i = 0 ;i < n ; i ++){
            a.push_back({end[i] , start[i]});
        }
        sort(a.begin() , a.end());
        int cnt = 1;
        int prev_start = a[0].second;
        int prev_end = a[0].first;
        for(int i = 1; i < n ; i ++){
            int curr_start = a[i].second;
            int curr_end = a[i].first;
            if(curr_start > prev_end){
                cnt ++;
                prev_start = curr_start; prev_end = curr_end;
            }
        }
        return cnt;
    }
};