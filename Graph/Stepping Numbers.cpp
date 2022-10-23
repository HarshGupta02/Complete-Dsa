class Solution{
public:

    void f(int num, int n, int m, int &ans){
        if(num > m) return;
        if(num >= n and num <= m) ans ++;
        int last = num % 10;
        if(last - 1 >= 0) f(10 * num + (last - 1), n, m, ans);
        if(last + 1 <= 9) f(10 * num + (last + 1), n, m, ans);
    }

    int steppingNumbers(int n, int m){
        int ans = 0;
        for(int i = 1; i <= 9; i ++){
            f(i, n, m, ans);
        }
        if(n == 0) ans ++;
        return ans;
    }
};