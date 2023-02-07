/*
METHOD 1: 

so here we see that if number of negatives are even so ans is size of the array.
if not then we consider all subarrays between 2 consecutive zeros and then for each 
subarray, we find the first the negative and the last negative and we just remove 
either the left part from the first negative or remove the right part from the last
negative and hence we get even number of negatives and we take the whole array as the 
answer.
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int i = 0, ans = 0;
        while(i < n){
            int left = i;
            while(left < n and nums[left] == 0) left ++;
            // so now left points to the start of a potential array
            // and right points to the end of a potential array at a 0 value
            
            // [[left1....right1][left2......right2][left3......right3]...]
            int right = left, negative = 0, first_neg = -1, last_neg = -1;
            while(right < n and nums[right] != 0){
                if(nums[right] < 0) {
                    negative ++;
                    if(first_neg == -1) first_neg = right;
                    last_neg = right;
                }
                right ++;
            }
            // now within each subarray from left to right, we have a first negative and 
            // a last negative
            if(negative % 2 == 0) ans = max(ans, right - left);
            else{
                // here we remove the left part of 1st negative as now number of negatives
                // becomes even.
                if(first_neg != -1) ans = max(ans, right - first_neg - 1);
                
                // here we remove the right part of last negative as now number of negatives
                // becomes even
                if(last_neg != -1) ans = max(ans, last_neg - left);
            }
            i = right + 1;
        }
        return ans;
    }
};

/*
METHOD 2:

here p = max lenght of subarray with positive product including the current
element.
n = max lenght of subarrya wit negative product including the current element.

if a[i] = 0 so p = 0, n = 0 as no postive or negative product subarray can be
formed.

if a[i] > 0 so we add the current element to both p and n and p will remain 
positive after multiplying and n will remain negative after multiplying. but
negative will remai negative only if n != 0 as if n = 0 so neg_prod = 0.

if a[i] < 0 so we cannot a[i] to both n and p as the parity will reverse so
we first swap p and n and then p stores max lenght with neg product and n 
stores the max lenght with pos product. so we do n ++ as the prod will become
negative anyhow but if p == 0 and we do p ++ then p contains only one element
and it will be negative but it will contradict the statement that p can only 
contain the lenght of positive product.

*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int nn = nums.size();
        int p = 0, n = 0, ans = 0;
        for(int i = 0; i < nn; i ++){
            if(nums[i] == 0) p = n = 0;
            else if(nums[i] > 0) {
                p ++; 
                if(n != 0) n ++;
                ans = max(ans, p);
            }else {
                swap(p, n);
                n ++;
                if(p != 0) p ++;
                ans = max(ans, p);
            }
        }
        return ans;
    }
};