class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid - 1 >= 0 and nums[mid - 1] > nums[mid]) high = mid - 1;
            else if(mid + 1 < n and nums[mid + 1] > nums[mid]) low = mid + 1;
            else{
                ans = mid; break;
            }
        }
        return ans;
    }
};

// [1,2,1,3,5,6,4]

/*
DCD -> peak
DCU -> move up
UCD -> move up
UCU -> move anywhere

*/