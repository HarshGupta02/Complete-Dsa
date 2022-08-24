// METHOD 1: TIME = O(19) -> MAX.

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0 or n == 2) return false;
        while(n % 3 == 0){
            n/=3;
        }
        if(n != 1) return false;
        return true;
    }
};

// METHOD 2 : TIME = O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 and 1162261467 % n == 0);
    }
};