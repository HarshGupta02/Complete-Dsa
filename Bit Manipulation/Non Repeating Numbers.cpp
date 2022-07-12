/*

here if we do the xor of all the numbers , we get the result as the xor of the 2 numbers that we
need to find . so x ^ y = (xor of all numbers) = xored

now we know that the xored will have set bits which will ensure that either of x or y will have
set bit at that position and not both. so we divide all numbers with and without set bit at that
position and xor of each set will give the two numbers as both the unknown numbers will never be
present in the same set.

*/


class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int xored = 0;
        for(int i = 0; i < n ; i ++) xored ^= nums[i];
        int temp = xored;
        int i = 0;
        while(temp != 0){
            int x = temp & 1;
            if(x == 1) break;
            temp >>= 1; i ++;
        }
        int s1 = 0 , s2 = 0;
        for(int j = 0; j < n ; j ++){
            int x = nums[j] & (1 << i);
            if(x == 0) s1 ^= nums[j];
            else s2 ^= nums[j];
        }
        vector<int>curr = {s1,s2};
        sort(curr.begin(),curr.end());
        return curr;
    }
};