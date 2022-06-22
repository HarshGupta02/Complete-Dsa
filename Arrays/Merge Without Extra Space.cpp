/// METHOD 1 :   TIME = O((N+M)LOG(N + M) + O(N) + O(M) + O(N) + O(M)) , SPACE = O(N + M).

/*

HERE WE JUST INSERT ALL THE ELEMENTS OF BOTH THE ARRAYS INTO A THIRD ARRAY , SORT THE ARRAY AND INSERT THE ELEMENTS
BACK TO THE FIRST AND SECOND ARRAY.

*/

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
    int n , m;
    cin >> n >> m;
    vector<int>a(n) , b(m);
    vector<int>c;
    for(int i = 0; i < n ; i ++){cin >> a[i]; c.push_back(a[i]);}
    for(int i = 0; i < m ; i ++){cin >> b[i]; c.push_back(b[i]);}
    sort(c.begin(),c.end());
    for(int i = 0 ; i < n ; i ++){
        a[i] = c[i];
    }
    for(int i = 0 ; i < m; i++){
        b[i] = c[n + i];
    }
    for(auto it : a) cout << it << " "; cout << endl;
    for(auto it : b) cout << it << " "; cout << endl;
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



///  METHOD 2 : TIME = O(N * M) , SPACE = O(1). USES INSERTION SORT.

/*

HERE WE USE 2 POINTER AND IF WE FIND A[I] > B[J] THEN WE SWAP BOTH AND USE INSERTION SORT AND ASSIGN THE CORRECT POSITION
OF THE FIRST ELEMENT IN ARRAY B USING SWAPS.

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;

#define debug(x) cout<<#x<<" = "<<x<<endl
#define nline "\n"
#define all(a) (a).begin(),(a).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n , m;
vector<int>a , b;

void insertion_sort(){
    for(int i = 0 ; i < m - 1 ; i ++){
        if(b[i] > b[i + 1]) swap(b[i], b[i + 1]);
        else break;
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n); b.resize(m);
    for(int i = 0; i < n ; i ++) cin >> a[i];
    for(int i = 0; i < m ; i ++) cin >> b[i];
    int i = 0 , j = 0;
    while(i < n and j < m){
        if(a[i] <= b[j]){
            i ++; continue;
        }
        swap(a[i] , b[j]);
        insertion_sort();
        i ++;
    }
    for(auto it : a) cout << it << " "; cout << endl;
    for(auto it : b) cout << it << " "; cout << endl;
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


/// METHOD 3: SHELL SORT - GAP METHOD 

/// TIME = O((N + M) * LOG(N + M)) , SPACE = O(1).

/*

USE GAP METHOD FOR BOTH THE ARRAYS . GAP METHOD WORKS EITHER IN ARR1 OR ARR2 OR MIX OF ARR1 AND ARR2. WE WILL SWAP ELEMENTS
FOR EACH GAP : GAP , GAP/2 , GAP/4 , GAP/8 .... 1 . WHEN GAP BECOMES 0 , THEN STOP.

*/


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
    int n , m ;
    cin >> n >> m;
    vector<int>a(n) , b(m);
    for(int i = 0; i < n ; i ++) cin >> a[i];
    for(int i = 0; i < m ; i ++) cin >> b[i];
    int initial_gap = (n + m + 1) / 2;
    for(int gap = initial_gap ; gap > 0; gap /= 2){
        int i = 0 , j = 0;
        for(i = 0; i + gap < n ; i ++){
            if(a[i] > a[i + gap]) swap(a[i] , a[i + gap]);
        }

        for(j = (gap > n) ? gap - n : 0 ; i < n and j < m ; i ++ , j ++){
            if(a[i] > b[j]) swap(a[i] , b[j]);
        }

        for(j = 0; j + gap < m ; j ++){
            if(b[j] > b[j + gap]) swap(b[j] , b[j + gap]);
        }
    }
    sort(a.begin() , a.end()); sort(b.begin() , b.end());
    for(auto it : a) cout << it << " "; cout << endl;
    for(auto it : b) cout << it << " "; cout << endl;
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