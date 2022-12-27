// METHOD 1:

/*
here we try to insert an element into a map and always take the last element of the map as it 
gives the greatest value and we decrease freq of an element as it is removed from the array 
and if it's freq becomes 0 so it is erased from the map.
*/

ll mod_add(ll a,ll b){
    if(a+b<=MOD)
     return a+b;
    return ((a+b+MOD)%MOD);
}

ll mod_sub(ll a,ll b){
    if(a-b<=MOD)
     return a-b;
    return ((a-b+MOD)%MOD);
}

ll mod_mul(ll a,ll b){
    if(a*b<=MOD)
     return a*b;
    return ((a*b+MOD)%MOD);
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(int i = 0; i < k; i ++){
            mp[nums[i]] ++;
        }
        vector<int>ans;
        auto it = mp.rbegin();
        ans.push_back(it -> first);
        for(int i = k; i < n; i ++){
            mp[nums[i - k]] --;
            if(mp[nums[i - k]] == 0){
                mp.erase(nums[i - k]);
            }
            mp[nums[i]] ++;
            it = mp.rbegin();
            ans.push_back(it -> first);
        }
        return ans;
    }
};

// METHOD 2:

/*
here we first find the nge of each element. then we see all k sized windows starting from i
and check for j from i where nge[j] lies in the given window. if it lies so j = nge[j] and j 
keeps on changing position until the nge[j] exceeds the current window. that value of j is the 
max value in the window. 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nge(n, n);
        stack<int>stk;
        for(int i = 0; i < n; i ++){
            if(stk.empty() or nums[stk.top()] > nums[i]) stk.push(i);
            else{
                while(!stk.empty() and nums[stk.top()] <= nums[i]){
                    nge[stk.top()] = i;
                    stk.pop();
                }
                stk.push(i);
            }
        }
        vector<int>ans;
        int j = 0;
        for(int i = 0; i <= n - k; i ++){
            if(j < i) j = i;
            while(nge[j] < i + k) j = nge[j];
            ans.push_back(nums[j]);
        }
        return ans;
    }
};

// METHOD 3:

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i = 0; i < n; i ++){
            if(!dq.empty() and dq.front() == i - k) dq.pop_front();
            while(!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};