/*

lets say we need a palindrome string so it's first and the last character should be the same so we try to insert characters
at the front and at the end of the middle string.

so let's say we have a function str(C1 M C2) where C1 is the character at the front , C2 is the character at the end and 
M is the middle string. so 

str(C1 M C2) = C1 + M + C2 and 

s(C1 M C2) = represents the total subsequences of the given string 
           => s(str(....s(M)....)) + s(str(C1....s(M)....)) + s(str(....s(M)....C2)) + s(str(C1....s(M)....C2));
                     C1'                      C2'                         C3'                       C4'

if C1 == C2  =>  total palindromic subsequences = C1' + C2' + C3' + C4' = C1' + C2' + C3' + (C1' + 1) 
=> (C1' + C2') + (C1 ' + C3') + 1  => str(C1 M) + str(M C2) + 1;

here + 1 is done because empty subsequence which was excluded in the count is now being included as two equal characters
are added at the end of an empty string which makes it a palindrome.

if C1 != C2  =>  total palindromic subsequences = C1' + C2' + C3' + C4' = C1' + C2' + C3' 
=> (C1' + C2') + (C1 ' + C3') - (C1') => str(C1 M) + str(M C2) - str(M);

here C4' will be zero because even if the middle has palindrome subsequences still adding two unequal characters at the end
will never be able to form the palindromic subsequence.

the dp table considers cells which have i <= j. rows denote the start pointer(i) and columns denote the end pointer(j) and 
dp[i][j] = number of palindromic subsequences for the string[i....j].

dp[i][i] = 1 , dp[i][j] = (s[i] == s[j]) ? 3 : 2; (base case)

*/

class Solution{
    public:
    using ll = long long int;
    long long int  countPS(string str)
    {
        ll n = str.size();
        ll mod = 1e9 + 7;
        vector<vector<ll>>dp(n , vector<ll>(n));
        for(ll gap = 0; gap < n; gap++){
            for(ll i = 0, j = gap;i < n and j < n; i++ , j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }else if(gap == 1){
                    dp[i][j] = (str[i] == str[j] ? 3 : 2);
                    dp[i][j] %= mod;
                }else{
                    if(str[i] == str[j]){
                        dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod + 1) % mod;
                        dp[i][j] %= mod;
                    }else{
                        dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1] + mod) % mod;
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        return dp[0][n - 1] % mod;
    }
};