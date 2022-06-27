class Solution{
    public:
    using ll = long long int;
    const ll MOD = 1e9 + 7;
    long long int findMaxProduct(vector<int>&a, int n){
        ll p_c = 0 , z_c = 0 , n_c = 0;
        ll p_p = 1 , n_p = 1;
        ll max_neg = -1e18;
        for(int i = 0; i < n ; i ++){
            if(a[i] > 0){
                p_p = p_p * a[i]; p_p = p_p % MOD;
                p_c ++; continue;
            }
            if(a[i] == 0){
                z_c ++; continue;
            }
            max_neg = max(max_neg , a[i] * 1ll);
            n_p = n_p * a[i]; n_p = n_p % MOD;
            n_c ++;
        }
        if(p_c == 0){
            if(z_c == 0){
                if(n_p > 0 or n_c == 1) return n_p;
                return n_p/max_neg;
            }
            if(n_c <= 1) return 0;
            if(n_p > 0) return n_p;
            return n_p/max_neg;
        }else{
            if(n_c <= 1) return p_p;
            if(n_p > 0) return (n_p * p_p) % MOD;
            ll p = n_p / max_neg;
            return (p * p_p) % MOD;
        }
    }
};