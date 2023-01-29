/* 
Q : Count all such Quadruplets that satisfy the below two conditions =>
1. i < j < k < l
2. nums[i] < nums[k] < nums[j] < nums[l].

can be done in O(N^2) considering the constraints so we try to fix 2 indexes
and in such cases, we always choose the middle indexes. so here we choose
j and k as we can do some precomputation on indexes and values.

before[i][j] = count of all indexes <= j such that a[indexes] < a[i].
after[i][j] = count of all indexes >= j such that a[indexes] > a[i].

*/

class Solution {
public:
    using ll = long long int;
    
    vector<vector<int>> fb(vector<int> &nums){
        int n = nums.size();
        // before[i][j] = count of all indexes <= j such that a[indexes] < a[i].
        vector<vector<int>> before(n, vector<int> (n, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < i; j ++){
                before[i][j] = (j == 0 ? 0 : before[i][j - 1]);
                if(nums[j] < nums[i]) before[i][j] ++;
            }
        }
        return before;
    }
    
    vector<vector<int>> fa(vector<int> &nums){
        int n = nums.size();
        // after[i][j] = count of all indexes >= j such that a[indexes] > a[i].
        vector<vector<int>> after(n, vector<int> (n, 0));
        for(int i = 0; i < n; i ++){
            for(int j = n - 1; j > i; j --){
                after[i][j] = (j == n - 1 ? 0 : after[i][j + 1]);
                if(nums[i] < nums[j]) after[i][j] ++;
            }
        }
        return after;
    }
    
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        vector<vector<int>> before = fb(nums);
        vector<vector<int>> after = fa(nums);
        for(int j = 1; j < n - 2; j ++){
            for(int k = j + 1; k < n - 1; k ++){
                if(nums[k] >= nums[j]) continue;
                ans += before[k][j - 1] * after[j][k + 1];
            }
        }
        return ans;
    }
};