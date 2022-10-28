// METHOD 1: TIME = O(LOG C * SQRT(C)), SPACE = O(1)

class Solution {
public:
    using ll = long long int;
    
    int f(int n){
        ll low = 0, high = n;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(mid * mid == (ll)n) return mid;
            if(mid * mid < (ll)n) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); i ++){
            int x = c - (i * i);
            int y = f(x);
            if(y * y == x) return true;
        }
        return false;
    }
};

// METHOD 2 : TIME = O(LOG C + SQRT(C))

class Solution {
public:
    using ll = long long int;
    bool judgeSquareSum(int c) {
        ll left = 0, right = sqrt(c);
        while(left <= right){
            if(left * left + right * right == c) return true;
            if(left * left + right * right < c) left ++;
            else right --;
        }
        return false;
    }
};
