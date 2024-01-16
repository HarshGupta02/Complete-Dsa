/*
here see that the number of set bits in a number can be the answer if the only
type of operation is subtraction, so we can try to reduce the number of set bits by
adding some number to the original number.

if the bit is 0 so go to next bit. if the bit is 1 then check the group of 
consecutive ones. if only a single bit so subtract else if group of 2 or more bits
so add 1 as adding will add just one bit to the right of the group and all
consecutive bits will reduce to 0.

*/

class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n > 0){
            if((n & 1) == 1){
                ans ++;
                n >>= 1;
                if((n & 1) == 1) n ++;
            }else n >>= 1;
        }
        return ans;
    }
};