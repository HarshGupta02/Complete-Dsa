class Solution {
  public:
    int findPosition(int N) {
        if(N == 0) return -1;
        int x = (N & (N - 1));
        if(x != 0) return -1;
        int cnt = 0;
        while(N != 0){
            cnt ++; N /= 2;
        }
        return cnt;
    }
};