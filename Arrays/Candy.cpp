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