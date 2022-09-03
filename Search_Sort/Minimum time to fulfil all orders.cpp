/*

here we apply binary search on the time and we check what max number of donuts can be made
by a certain person within this time. then we sum up all the count of donuts and if it comes
out to be >= n then they can be make n donuts in more time than assumed time so go backward
else go forward.

low = if the person with lowest rank makes only 1 dount.
high = if the person with highest rank makes all the donuts.

*/


class Solution{
    public:
    
    bool check(int mid, int n, int l, vector<int> &a){
        int cnt = 0;
        for(int i = 0; i < l; i ++){
            int time_taken = 0;
            int time_will_take = a[i];
            while(time_taken + time_will_take <= mid){
                cnt ++;
                time_taken += time_will_take;
                time_will_take += a[i];
            }
        }
        return (cnt >= n ? true : false);
    }
    
    int findMinTime(int n, vector<int>&a, int l){
        int low = 0, high = 1e9;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, n, l, a)){
                ans = mid; high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

// a person with rank r can make n donuts=>

// r + 2r + 3r + 4r + ... + nr => r(1 + 2 + 3 ... + n)

// => r * (n * (n + 1))/2 minutes 

// 4 approaches => 1. bfs, 2. dp, 3. binary search, 4. greedy