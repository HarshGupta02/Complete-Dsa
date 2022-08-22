// TIME = O(N * LOG N), SPACE = O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        for(auto it : nums) mp[it] ++;
        priority_queue<pair<int,int>>pq;
        for(auto it : mp) pq.push({it.second, it.first});
        vector<int>ans;
        while(k --){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};

// TIME = O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>count(n + 1);
        unordered_map<int,int>mp;
        for(auto it : nums) mp[it] ++;
        for(auto it : mp){
            count[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i = n; i >= 1; i --){
            if(count[i].empty()) continue;
            for(auto num : count[i]){
                if(k > 0){
                    k --;
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

/*
here we use the reverse trick as we need most frequent element so our aim
should be on the occurences of a particular number which can be max n.
and in linear time (iterating from back), we can get the top k frequent 
elements. so count[i] stores those elements whose freq is i.

opp is not preferred because our element with max freq might be somewhere
in the middle of the array and to first k elements with max freq is time
consuming.

*/