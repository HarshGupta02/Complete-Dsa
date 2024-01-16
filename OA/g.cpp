#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    string nums;
    cin >> nums;
    int n = nums.size();
    int idx = -1;
    for(int i = n - 2; i >= 0 ;i --){
        if(nums[i] >= nums[i + 1]) continue;
        idx = i; break;
    }
    if(idx == -1){
        sort(nums.begin() , nums.end());
        // return "no answer";
        // cout << "no answer" << endl;
    }
    for(int i = n - 1; i >= 0 ; i --){
        if(nums[i] > nums[idx]){
            swap(nums[i] , nums[idx]);
            break;
        }
    }
    sort(nums.begin() + idx + 1, nums.end());
    cout << nums << endl;
    // return nums;

    // METHOD 2:

    bool val = next_permutation(word.begin(), word.end());
    return (val == "false" ? "no answer" : word);

    return (next_permutation(word.begin(), word.end()) ? word : "no answer");
}

int main() {
    fast_cin();
    ll test_cases;
    cin >> test_cases;
    for(ll it=1;it<=test_cases;it++) {
        solve();
    }
    return 0;
}