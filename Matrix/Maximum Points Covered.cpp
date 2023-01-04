class Solution {
  public:
    int maximumpoints(vector<vector<int> > arr, int n, int x, int y) {
        const int MAXN = 1e3 + 2;
        int a[MAXN][MAXN];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i ++){
            a[arr[i][0]][arr[i][1]] ++;
        }
        for(int i = 1; i < MAXN; i ++){
            for(int j = 1; j < MAXN; j ++){
                a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        }
        int ans = 0;
        for(int i = x + 1; i < MAXN; i ++){
            for(int j = y + 1; j < MAXN; j ++){
                int cnt = a[i][j] - a[i - x - 1][j] - a[i][j - y - 1] + a[i - x - 1][j - y - 1];
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

/*

since max size of coordinates is 1000 so we can make use of it. we can consider
all possible rectangles with given sides and count the number of points within it,
using the concept of prefix sum on 2d matrix.

*/