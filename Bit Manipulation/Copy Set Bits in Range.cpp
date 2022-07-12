class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        long long int mask = (long long int)1 << (((r - l) + 1));
        mask --;
        mask = mask << (l - 1);
        mask = mask & y;
        x = x | mask;
        return x;
    }
};