/*
here we first assume that each element will be the starting of the longest consecutive 
sequence by assigning it to hashmap. then we check for each element if it's prev element is
present in hashmap or not. if yes, then it cannot be the starting of the longest consecutive
sequence(LCS). so in the end we have the starting nodes of all possible LCS. 

also each element will be present in one of the possible chains so each element will be
processed exactly once.

*/

// TIME = O(N), SPACE = O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        unordered_map<int,bool>mp;
        unordered_map<int,int>freq;
        for(auto it : nums) {
            mp[it] = true;
            freq[it] = 1;
        }
        vector<int>possible;
        for(auto it : nums){
            if(mp[it - 1]) continue;
            else{
                if(freq[it] == 1) {
                    possible.push_back(it); 
                    freq[it] --;
                }
                else continue;
            }
        }
        int nax = 1;
        for(auto it : possible){
            int ans = 1;
            while(mp[it + 1]){
                it ++; ans ++;
            }
            nax = max(nax, ans);
        }
        return nax;
    }
};