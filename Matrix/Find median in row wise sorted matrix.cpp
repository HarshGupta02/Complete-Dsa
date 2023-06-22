#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

/*
here we are trying to find if number of elements <= mid are greater than
(n * m)/2. if they are greater then we have to move left hence high = mid - 1.
if they are equal to (n * m)/2 still move to right because we have included
the median in the cnt. 

so low left after condition break is the ans . ???
*/

void solve(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i = 0 ; i < r ; i ++){
        for(int j = 0; j < c ; j ++){
            cin >> v[i][j];
        }
    }
    int low = 1, high = 1e9;
    while(low <= high){
        int mid = low + (high - low)/2;
        // check if mid can be the median
        int cnt = 0;
        for(int i = 0; i < r ; i ++){
            auto it = upper_bound(v[i].begin(), v[i].end(), mid);
            if(it != v[i].end()){
                int idx = it - v[i].begin();
                cnt += idx;
            }else cnt += c;
        }
        if(cnt > (r * c)/2) high = mid - 1;
        else low = mid + 1;
    }
    cout << low << endl; // low will be element in the matrix , how ??
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

// ANOTHER WAY

class Solution{   
public:

    int go(vector<int> &a, int mid) {
        int n = a.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int md = low + (high - low)/2;
            if(a[md] <= mid) low = md + 1;
            else high = md - 1;
        }
        return low;
    }

    int median(vector<vector<int>> &matrix, int n, int m){
        int low = 1, high = 2005;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(int i = 0; i < n; i ++) cnt += go(matrix[i], mid);
            if(cnt <= ((n * m)/2)) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};