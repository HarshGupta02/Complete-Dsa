/*
here we assume the fact that we try to assign 2 possible candidates to each element if 
there are no 2 possible candidates. but if there are and an element is not equal to '
either of the 2 possible candidate then that element cancels both the elements contribution 
or tries to cancel both the major elements else we increment either of the 2 possible 
candidates if they match. also we need to ensure that both the major elements are not same.

*/

class Solution {
public:
    using ll = long long int;
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        ll major1 = -1e10, freq1 = 0;
        ll major2 = -1e10, freq2 = 0;
        for(int i = 0; i < n; i ++) {
            if(freq1 == 0 and nums[i] != major2) {
                major1 = nums[i];
                freq1 = 1;
            }else if(freq2 == 0 and nums[i] != major1) {
                major2 = nums[i];
                freq2 = 1;
            }else if(nums[i] == major1) freq1 ++;
            else if(nums[i] == major2) freq2 ++;
            else {
                freq1 --; freq2 --;
            }
        }
        vector<int> ans;
        freq1 = 0; freq2 = 0;
        for(int i = 0; i < n; i ++) {
            if(nums[i] == major1) freq1 ++;
            if(nums[i] == major2) freq2 ++;
        }
        int req = n/3 + 1;
        if(freq1 >= req) ans.push_back(major1);
        if(freq2 >= req) ans.push_back(major2);
        return ans;
    }
};