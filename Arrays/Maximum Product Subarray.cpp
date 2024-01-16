// METHOD 1:

class Solution{
public:
    using ll = long long int;
	long long maxProduct(vector<int> arr, int n) {
	    ll maxi = 1, mini = 1;
	    ll glob_max = INT_MIN;
	    for(int i = 0; i < n ;i ++){
	        if(arr[i] < 0) swap(maxi , mini);
	        maxi = max((ll)arr[i] , maxi * arr[i]);
	        mini = min((ll)arr[i] , mini * arr[i]);
	        glob_max = max(glob_max , maxi);
	    }
	    return glob_max;
	}
};

// METHOD 2:

/*
here we use the concept that =>
1. if all numbers are positive so choose whole array
2. if there are even number of negative numbers still choose the whole array.
3. if there are odd number of negative numbers so try to ignore each negative numbers and 
take the max of product of left half and right half. so left half and right half will
contain even no of negative numbers and with max length and hence will give max product.
taking higher no of even negative numbers is always beneficial.
4. if there are 0's in array then never choose a subarray with 0 as will always give 0.
so partition array into subarrays such that each subarray does not contain 0. if pre or
suf = 0 then set them to 1 and go to the next element.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suf = 1, ans = INT_MIN;
        for(int i = 0; i < n; i ++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n - i - 1];
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};