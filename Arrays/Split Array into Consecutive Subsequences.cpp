/*
here each element has the option to either add to an existing subsequence or create a new
subsequence from here.

it is always better to add to an existing subsequence first because it is possible that there
are no elements with value curr + 1 and curr + 2 but if there are ,then they will automatically
be covered in the first case.

*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq_mp, hypo_mp;
        for(auto it : nums) freq_mp[it] ++;
        for(int i = 0; i < n ; i ++){
            int curr = nums[i];
            if(freq_mp[curr] == 0) continue;
            if(hypo_mp[curr] == 0){
                // no one is demanding so start a new subsequence from here and take next two elements.
                if(freq_mp[curr + 1] > 0 and freq_mp[curr + 2] > 0){
                    freq_mp[curr + 1] --; freq_mp[curr + 2] --;
                    hypo_mp[curr + 3] ++;
                }else return false;
                
            }else{
                // it is demanded so add to prev subsequence
                hypo_mp[curr] --;
                hypo_mp[curr + 1] ++; // this is demanded in future
            }
            freq_mp[curr] --;
        }
        // for(auto it : hypo_mp) cout << it.first << " " << it.second << endl;
        return true;
    }
};