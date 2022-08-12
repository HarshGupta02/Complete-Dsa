class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x != 0 or y != 0){
            if((x & 1) != (y & 1)) cnt ++;
            x = x >> 1; y = y >> 1;
        }
        return cnt;
    }
};