// METHOD 1: TIME = O(N * N), SPACE = O(N)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<int>dp(n , 1), hash(n);
    for(int i = 0; i < n; i ++) hash[i] = i;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <  i ; j ++){
            if(a[j] < a[i] and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << endl;
    // to print the LIS.
    int last_index, maxi = -1;
    for(int i = 0; i < n; i ++){
        if(dp[i] > maxi){
            maxi = dp[i];
            last_index = i;
        }
    }
    vector<int>ans; ans.push_back(a[last_index]);
    while(last_index != hash[last_index]){
        last_index = hash[last_index];
        ans.push_back(a[last_index]);
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main() {
    fast_cin();
    ll test_cases = 1;
    // cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}


/// METHOD 2: TIME = O(N * LOGN) , SPACE = O(2 * N) ~ O(N)

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>ans;
        vector<int>arr; for(int i = 0; i < n ; i ++) arr.push_back(a[i]);
        int cnt = 0;
        for(int i = 0; i < n ; i ++){
            if(ans.empty() or arr[i] > ans.back()){
                ans.push_back(arr[i]);
                cnt ++;
            }
            else{
                int idx = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }
        return ans.size();
    }
};