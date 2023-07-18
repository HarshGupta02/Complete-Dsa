/*
so here we see that if we take xor of all numbers so we get the xor of the two 
numbers that have odd occurence. now it is sure that atleast one bit of the xor 
will be set otherwise both numbers will be same but it is not possible.

so we find the bit position, which is set in xor value and segregate all numbers
into two group - one group that contain all those numbers that have set bit at that
position and other group that contain all numbers that have unset bit at that
position. it is sure that both the odd occ numbers will be in diff group as 
since their xor at this bit was 1, so both have diff bit at that position.

*/

class Solution{
    public:
    using ll = long long int;
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        ll xorr = 0;
        for(int i = 0; i < n; i ++) xorr ^= arr[i];
        ll set_bit = -1;
        for(ll i = 0; i <= 40; i ++) {
            if(xorr & (1 << i)) {
                set_bit = i;
                break;
            }
        }
        assert(set_bit != -1);
        ll g1 = 0, g2 = 0;
        for(ll i = 0; i < n; i ++) {
            if(arr[i] & (1 << set_bit)) g1 ^= arr[i];
            else g2 ^= arr[i];
        }
        if(g1 > g2) return {g1, g2};
        return {g2, g1};
    }
};