class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    map<int,int>mp;
	    for(int i = 0; i < n ; i ++){
	        mp[nums[i]] = i;
	    }
	    int k = 0;
	    int cnt = 0;
	    for(auto it : mp){
	        int to_insert = it.first;
	        int to_replace = nums[k];
	        if(to_insert != to_replace){
	            cnt ++;
	            swap(nums[it.second] , nums[k]);
	            mp[to_insert] = k; mp[to_replace] = it.second;
	        }
	        k ++;
	    }
	    return cnt;
	}
};

// 10,19,6,3,5 => 3,19,6,10,5 => 3,5,6,10,19

// 2,8,5,4 => 2,4,5,8

// for each element we can find the minimum element to the right(if any and
// swap it).

// 9
// 7 16 14 17 6 9 5 3 18 => 3 16 14 17 6 9 5 7 18 =>  3 5 14 17 6 9 16 7 18 => 3 5 6 17 14 9 16 7 18
// => 3 5 6 7 14 9 16 17 18 => 3 5 6 7 9 14 16 17 18

// idx: 0  1  2  3 4 5 6 7  8
//      7 16 14 17 6 9 5 3 18
     
//      3 5 6 7 9 14 16 17 18

// {3,7} {5,6} {6,4} {7,0} {14,2} {9,5} {16,1} {17,3} {18,8}