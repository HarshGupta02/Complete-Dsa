/*
so we basically check the longest common prefix in both the numbers.
the first bit which is not set then there will always be a number 
between them that will result in all zeros so in the final answer, 
all bits will be set to zero after the first mismatch.
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int mask = 0;
        for(int bit = 31; bit >= 0; bit --) {
            if((left & (1 << bit)) != (right & (1 << bit))) break;
            else mask |= (left & (1 << bit));
        }
        return mask;
    }
};