int maxStop(vector<vector<int>> &trains, int n, int m)
{
    sort(trains.begin() , trains.end() , [&](const vector<int> &a , const vector<int> &b) -> bool{
        if(a[2] != b[2]) return a[2] < b[2];
        else return a[1] < b[1];
    });
    int ans = 0;
    bitset<3005>visited;
    int prev_start , prev_end;
    for(int i = 0 ; i < n ; i ++){
        int p = trains[i][2];
        if(!visited[p]){
            prev_start = trains[i][0]; prev_end = trains[i][1];
            visited[p] = 1; ans ++ ;
        }
        int curr_start = trains[i][0] , curr_end = trains[i][1];
        if(curr_start == prev_start and curr_end == prev_end) continue;
        if(curr_start >= prev_end){
            ans ++;
            prev_start = curr_start; prev_end = curr_end;
        }
    }
    return ans;
}