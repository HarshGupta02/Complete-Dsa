/*
here we first find the first number which is power of 2 that is less than n(2 ^ x). for 
numbers less than 2 ^ x , cnt += (2^x)/2 * x;

then we remove all the MSB from remaining numbers so cnt += (n - 2 ^ x) + 1;

then we recursive call for cnt += solve(n - 2 ^ x);

*/


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int countSetBits(int n)
    {
        if(n == 0) return 0;
        int cnt = 0;
        int temp = n;
        int x = 0;
        while(temp != 0){
            x ++; temp >>= 1;
        }
        x --;
        int diff = (n - (1 << x));
        cnt += (1 << (x - 1)) * x + (diff + 1) + countSetBits(diff);
        return cnt;
    }
};