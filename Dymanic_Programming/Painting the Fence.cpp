/*
here we tried to find the number of ways to arrange i posts with some arrangements having last
2 posts of equal color and some having different color.

no of ways of same color of last 2 posts = no of ways of diff color of i - 1 posts.
# of diff color = total of same + diff of i - 1 posts.

*/


class Solution{
    public:
    using ll = long long int;
    long long countWays(int n, int k){
        const ll MOD = 1e9 + 7;
        if(n == 1) return k;
        if(n == 2 and k == 1) return 1;
        if(n != 2 and k == 1) return 0;
        ll same = k , diff = k * (k - 1) , total = same + diff;
        for(int i = 3; i <= n ; i++){
            same = diff;
            diff = (k - 1) * total; diff = diff % MOD;
            total = same + diff; total = total % MOD;
        }
        return total;
    }
};