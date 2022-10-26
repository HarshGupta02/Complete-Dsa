/* 
TIME = O(N * LOGN), SPACE = O(N)

here we first remove the duplicates from the array and sort the array as the continous
array will just have unique elements. then we consider each elemenet as the min element 
of the continous array and count all the elements that lie in the range of a[i] to
a[i] + (n - 1) and take the max of all common elements. then we return n - max_common.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int>s; for(auto it : nums) s.insert(it);
        vector<int>v; for(auto it : s) v.push_back(it);
        int m = v.size(), ans = 0;
        for(int i = 0; i < m; i ++){
            auto it = lower_bound(v.begin() + i, v.end(), v[i] + (n - 1));
            if(it != v.end()){
                int idx = it - v.begin();
                if(*it == (v[i] + (n - 1))) ans = max(ans, idx - i + 1);       
                else ans = max(ans, idx - i);
            }else ans = max(ans, m - i);
        }
        return n - ans;
    }
};

// 2 3 4 5    n = 4, m = 4
// 1 2 3 98 99 101 103

/*
1. continous = [2,3,4,5], [1,2,3,4,5]
2. order does not matter => can sort.
3. max operations to make continuous = n
4. the min element is imp as it decides the max element as max = min + (n - 1).
5. removing an element that has occurence as 1 and lies within the max range is
never useful as 1 extra operation is needed to get him.
6. try to choose each element as min element and check how many are
already present in the array.

[1,10,100,1000] => 



*/