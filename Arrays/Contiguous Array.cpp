/*
here we converted all 0's to -1 so that we can find max subarray sum with sum = 0
and we store the first occ of each new sum and compare it with the index, when next time 
an already existing sum comes in place.
*/

// TIME = O(N * LOGN), SPACE = O(N)

class Solution {
public:
    int findMaxLength(vector<int>& a) {
        // 0 -> -1
        // find the max length subarray with 0 sum
        int n = a.size();
        int sum = 0, ans = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i = 0; i < n ; i ++){
            sum += (a[i] == 1 ? 1 : -1);
            if(mp.find(sum) != mp.end()){
                if(i - mp[sum] > ans){
                    ans = i - mp[sum];
                }
            }else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};