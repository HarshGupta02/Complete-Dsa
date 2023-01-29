/*
Q: Count of triplets in an Array (i, j, k) such that i < j < k and a[k] < a[i] < a[j]
*/

/*
METHOD 1: TIME = O(N ^ 3), SPACE = O(1)
*/

class Solution {
public:
    int getTriplets(vector<int> nums){
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                for(int k = j + 1; k < n; k ++){
                    if(a[k] < a[i] and a[i] < a[j]) ans ++;
                }
            }
        }
        return ans;
    }
};

/*
METHOD 2: TIME = O(N ^ 2), SPACE = O(1)
*/

class Solution {
public:
    int getTriplets(vector<int> nums){
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int cnt = 0;
            for(int j = i + 1; j < n; j ++){
                if(a[i] < a[j]) cnt ++;
                else ans += cnt;
            }
        }
        return ans;
    }
};

/*
Q: Count of triplets in an Array (i, j, k) such that i < j < k and a[i] < a[j] < a[k]
METHOD 2: TIME = O(N ^ 2), SPACE = O(N)
*/

class Solution {
public:
    int getTriplets(vector<int> nums){
        int n = nums.size();
        vector<int> bigger(n, 0);
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                if(nums[i] < nums[j]) bigger[i] ++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n - 1; j ++){
                ans += bigger[j + 1];
            }
        }
        return ans;
    }
};