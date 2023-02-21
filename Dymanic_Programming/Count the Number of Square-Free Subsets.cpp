/*
we see that each square number has only primes with count as 1.
so in each square free number, there should be distinct prime numbers.
primes = 2,3,5,7,11,13,17,19,23,27,29 (11 no)
min_prod = 2, max_prod = 2*3*5....*29 = 10^11 approx
now our prod will be either include a prime number or not include a prime number.
so there 2^11(2048) possible unique square number products.

so instead of storing the product in the dp, we can store the mask of the number in
the dp with set bits storing the prime factor, the number is made up of.

*/

class Solution {
public:
    using ll = long long int;
    const ll MOD = 1e9 + 7;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    vector<vector<int>> dp;
    
    ll to_mask(int x){
        int mask = 0;
        for(int i = 0; i < primes.size(); i ++){
            if(x % primes[i] == 0){
                x /= primes[i];
                mask |= (1 << i);
            }
        }
        return mask;
    }
    
    ll from_mask(int mask){
        ll x = 1;
        for(int j = 0; j < primes.size(); j ++){
            if((mask & (1 << j)) == 1) x = x * primes[j];
        }
        return x;
    }
    
    ll f(int i, int mask, vector<int> &exclude){
        int n = exclude.size();
        if(mask == 0) return 1;
        // if mask is not zero so there is atleast one bit set
        if(i == n) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        ll x = from_mask(mask);
        cout << x << endl;
        ll res = 0;
        res = res + f(i + 1, mask, exclude);
        if(x % exclude[i] == 0) res = res + f(i + 1, to_mask(x/exclude[i]), exclude);
        return dp[i][mask] = res;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size(), ones = 0;
        vector<int> exclude;
        dp.resize(n, vector<int> (1025, -1));
        for(int i = 0; i < n; i ++){
            if(nums[i] == 1) ones ++;
            else exclude.push_back(nums[i]);
        }
        ll total_one = 1, total_not_one = 0;
        // if mask is 0 so prime factor is selected so not a valid number
        for(int mask = 1; mask < 1024; mask ++){
            total_not_one = total_not_one + f(0, mask, exclude);
        }
        // cout << total_not_one << endl;
        while(ones --) {
            total_one = total_one * 2;
        }
        total_one --; // excluding the case when no one is selected.
        ll res = 0;
        res = total_one + total_not_one; // calculated differently
        res = res + (total_one * total_not_one); // calculated together
        return res;
    }
};
