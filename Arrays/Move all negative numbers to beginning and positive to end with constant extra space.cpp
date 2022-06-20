////  ORDER DOES NOT MATTER

//// 2 - POINTER APPROACH

/// TIME = O(N) , SPACE = O(1)

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
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
    }
    int i = 0 , j = n - 1;
    while(i < j){
        if(a[i] < 0 and a[j] > 0){
            i ++; j --; continue;
        }
        if(a[i] < 0 and a[j] < 0){
            i ++; continue;
        }
        if(a[i] > 0 and a[j] < 0){
            swap(a[i] , a[j]);
            i ++; j --; continue;
        }
        j --;
    }
    for(auto it : a) cout << it << " ";
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


/// DUTCH NATIONAL FLAG :

/// THE NATIONAL FLAG OF DUTCH HAS THREE COLORS SO WE DIVIDE THE WHOLE ARRAY INTO THREE PARTS

////    ...... LOW ....... HIGH ......

//// ELEMENTS FROM [0...LOW - 1] ARE < 0 AND [LOW ..... HIGH] ARE UNKNOWN WHOSE SIZE WE TEND TO MINIMISE AND MAKE IT 0 AND 
//// ELEMENTS FROM [HIGH + 1.....N - 1] ARE > 0.

// TIME = O(N) , SPACE = O(1)

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
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int low = 0 , high = n - 1;
    while(low < high){
        if(a[low] < 0) low ++;
        else if(a[high] > 0) high --;
        else swap(a[low] , a[high]);
    }
    for(auto it : a) cout << it << " ";
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