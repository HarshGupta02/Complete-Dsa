// TIME = O(N), SPACE = O(N).

class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n, 1);
        for(int i = n - 1; i >= 0 ; i --){
            if(i + 1 < n and a[i] > a[i + 1] and ans[i] <= ans[i + 1]) ans[i] = ans[i + 1] + 1;
        }
        for(int i = 0; i < n ; i ++){
            if(i - 1 >= 0 and a[i] > a[i - 1] and ans[i] <= ans[i - 1]) ans[i] = ans[i - 1] + 1;
        }
        int sum = 0;
        for(auto it : ans) sum += it;
        return sum;
    }
};

// TIME = O(N), SPACE = O(1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, candy = n;
        while(i < n) {
            if(ratings[i] == ratings[i - 1]) {
                i ++; continue;
            }
            // increasing peak
            int peaks = 0;
            while(i < n and ratings[i] > ratings[i - 1]) {
                peaks ++;
                candy += peaks;
                i ++;
            }
            // decreasing peak or increasing valley
            int valley = 0;
            while(i < n and ratings[i] < ratings[i - 1]) {
                valley ++;
                candy += valley;
                i ++;
            }
            // since candy included both peak and valley so needed only max of them so removed min of them
            candy -= min(peaks, valley);
        }
        return candy;
    }
};