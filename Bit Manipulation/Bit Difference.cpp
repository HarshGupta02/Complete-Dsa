class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int i = 0;
        int cnt = 0;
        while(i < 20){
            int bit1 = a & (1 << i);
            int bit2 = b & (1 << i);
            if(bit1 != bit2) cnt ++; i ++;
        }
        return cnt;
    }
};