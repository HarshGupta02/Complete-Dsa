//// TIME = O(N ^ 2) , SPACE = O(1)

/* 

here for each ith element , we try to find the first element which is greater than the ith element and if we find one such 
that left < right , then we swap them and continue it until the ith element is 0. if it is 0 then i++.

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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
    }
    int left = 0 , right = n - 1;
    while(left < n){
        if(left == right){
            left ++ ; right = n - 1; continue;
        }
        if(a[left] == 0){
            left ++ ; continue ;
        }
        if(a[left] >= a[right]){
            swap(a[left] , a[right]);
            if(a[left] != 0){
                right -- ;
            }
            continue;
        }
        if(a[left] <  a[right]){
            right --; continue ;
        }
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


// ////  TIME = O(N * LOG N) , SPACE = O(1)

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
    sort(all(a));
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


/// ------ COUNT SORT ------

///  TIME = O(N) , SPACE = O(1) , TAKES 2 PASSES AS TRAVERSES THE ARRAY 2 TIMES

/*

HERE WE TRAVERSE THE ARRAY ONCE AND STORE THE COUNT OF 0's , 1's , 2's AND WE FILL THE ORIGINAL ARRAY WITH THEIR COUNT.

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
    int n;
    cin >> n;
    vector<int>a(n);
    int zero_cnt =0 , one_cnt = 0 , two_cnt =0 ;
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
        if(a[i] == 0) zero_cnt ++; 
        else if(a[i] == 1) one_cnt ++;
        else two_cnt ++;
    }
    for(int i = 0 ;i < n; i ++){
        if(zero_cnt > 0){
            a[i] = 0; zero_cnt -- ; continue;
        }
        if(one_cnt > 0){
            a[i] = 1; one_cnt -- ; continue ;
        }
        a[i] = 2;
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


///// ------------ DUTCH NATIONAL FLAG ALGORITHM -------- (D N F) ALGO

////  TIME = O(N) , SPACE = O(1) , TAKES ONLY 1 PASS AS TRAVERSES THE ARRAY ONLY ONE TIME

/*

HERE WE MAINTAIN A LOW , MID ,HIGH POINTERS AND A[0...LOW - 1] = SHOULD CONTAIN ALL 0 , A[HIGH + 1 .... N - 1] = 
SHOULD CONTAIN ALL 2 AND A[LOW .... HIGH] = CAN CONTAIN EITHER OF THE THREE.

SO IF A[MID] == 0 , THEN WE HAVE TO SWAP A[MID] AND A[LOW] AND MOVE BOTH MID AND LOW BECAUSE NOW MID POINTS TO 1 AND 
LOW POINTS TO 0 , SO BOTH ARE SATISPHIED.

SO IF A[MID] == 1 , THEN MID IS SATISPHIED AS IT HAS 1 AND THAT'S WHAT IT NEEDED.

SO IF A[MID] == 2 , THEN WE HAVE TO SWAP A[MID] AND A[HIGH] AND MOVE HIGH -- BECAUSE NOW HIGH HAS 2 SO HE IS SATISPHI
ED BUT MID MIGHT STILL CONTAIN 0 WHICH HE NEEDS TO SWAP WITH LOW , SO ONLY HIGH MOVED OR DECREMENTED BY 1.

AND WE LOOP UNTIL MID <= HIGH BECAUSE AT MID == HIGH , THEN ALSO THERE IS POSSIBILITY THAT WE MIGHT HAVE TO SWAP THE 
CURRENT 0 WITH THE LOW.

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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i =0 ; i < n ; i ++){
        cin >> a[i];
    }
    int low = 0 , mid = 0 , high = n - 1;
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid] , a[low]);
            low ++; mid ++; continue;
        }
        if(a[mid] == 1){
            mid ++; continue;
        }
        if(a[mid] == 2){
            swap(a[mid] , a[high]);
            high -- ; continue;
        }
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