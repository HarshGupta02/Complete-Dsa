class Solution {
  public:
    int setBits(int N) {
        int cnt = 0;
        while(N != 0){
            cnt += (1 & N);
            N >>= 1;
        }
        return cnt;
    }
};